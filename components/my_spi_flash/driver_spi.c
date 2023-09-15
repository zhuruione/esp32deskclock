//
// Created by zr on 3/1/23.
//
#include "driver_spi.h"
#include <string.h>
#include <esp_log.h>

static const char *LOGNAME = "driver_spi";
void flashPre(spi_transaction_t *trans) {

}

esp_err_t spi_init(spi_device_handle_t *flash_handle) {
    esp_err_t err = 0;
    spi_bus_config_t spi2_bus_config = {
            .miso_io_num=7,
            .mosi_io_num=8,
            .sclk_io_num=6,
            .quadwp_io_num=-1,
            .quadhd_io_num=-1,
            .max_transfer_sz=4096
    };
    err = spi_bus_initialize(SPI1_HOST, &spi2_bus_config, SPI_DMA_CH_AUTO);
    spi_device_interface_config_t flash_interface_config = {
            .mode=0,
            .clock_speed_hz=20 * 1000 * 1000,
            .pre_cb=flashPre,
            .queue_size=6,
            .spics_io_num=11
    };
    spi_bus_add_device(SPI1_HOST, &flash_interface_config, flash_handle);
    return err;
}

esp_err_t sendCmd(spi_device_handle_t flash_handle, uint8_t cmd, bool keep_alive) {
    spi_transaction_t cmd_tran;
    memset(&cmd_tran, 0, sizeof cmd_tran);
    cmd_tran.tx_buffer = &cmd;
    cmd_tran.length = 8;
    if (keep_alive)
        cmd_tran.flags = SPI_TRANS_CS_KEEP_ACTIVE;
    spi_device_acquire_bus(flash_handle,portMAX_DELAY);  //获取总线🔓
    esp_err_t err=spi_device_polling_transmit(flash_handle, &cmd_tran);
    if (!keep_alive)
        spi_device_release_bus(flash_handle);
    return err;
}
esp_err_t sendDummy(spi_device_handle_t flash_handle){
    spi_transaction_t tran_dummy;
    memset(&tran_dummy,0,sizeof tran_dummy);
    tran_dummy.length=8;
    uint8_t dummy=0xff;
    tran_dummy.tx_buffer=&dummy;
    tran_dummy.flags = SPI_TRANS_CS_KEEP_ACTIVE;
    return spi_device_polling_transmit(flash_handle, &tran_dummy);
}
esp_err_t sendAddr(spi_device_handle_t flash_handle, uint32_t addr, bool keep_alive){
    ((uint8_t *) &addr)[4] = ((uint8_t *) &addr)[0];
    ((uint8_t *) &addr)[0] = ((uint8_t *) &addr)[2];
    ((uint8_t *) &addr)[2] = ((uint8_t *) &addr)[4];
    spi_transaction_t tran_addr;
    memset(&tran_addr,0,sizeof tran_addr);
    tran_addr.length=24;
    tran_addr.tx_buffer=&addr;
    if (keep_alive)
        tran_addr.flags = SPI_TRANS_CS_KEEP_ACTIVE;
    esp_err_t err=spi_device_polling_transmit(flash_handle, &tran_addr);
    if(!keep_alive)
        spi_device_release_bus(flash_handle);
    return err;
}

esp_err_t sendByte(spi_device_handle_t flash_handle, void *buffer, size_t length, bool keep_alive) {
    spi_transaction_t sendtran;
    memset(&sendtran, 0, sizeof sendtran);
    sendtran.length = length*8;
    sendtran.tx_buffer=buffer;
    if (keep_alive)
        sendtran.flags = SPI_TRANS_CS_KEEP_ACTIVE;
    esp_err_t err=spi_device_polling_transmit(flash_handle, &sendtran);
    if (!keep_alive)
        spi_device_release_bus(flash_handle);
    return err;
}
esp_err_t receiveByte(spi_device_handle_t flash_handle, void *buffer, size_t length, bool keep_alive) {
    spi_transaction_t receive;
    memset(&receive, 0, sizeof receive);
    receive.length = length*8;
    receive.rx_buffer=buffer;
    if (keep_alive)
        receive.flags = SPI_TRANS_CS_KEEP_ACTIVE;
    esp_err_t err=spi_device_polling_transmit(flash_handle, &receive);
    if (!keep_alive){
        spi_device_release_bus(flash_handle);
    }
    return err;
}
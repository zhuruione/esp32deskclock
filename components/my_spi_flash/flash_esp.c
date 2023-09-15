//
// Created by zr on 3/7/23.
//
#include <esp_log.h>
#include "flash_esp.h"
#include "driver/spi_common.h"
#include "esp_flash_spi_init.h"
#include "esp_flash.h"
esp_flash_t *espFlash;
const char * LOG="fkash_esp";
esp_err_t flash_init(){
    esp_err_t err=0;
    esp_flash_spi_device_config_t spiDeviceConfig={
            .host_id=SPI1_HOST,
            .cs_io_num=11,
            .freq_mhz=20,
            .io_mode=0
    };
    ESP_LOGI(LOG,"before");
    err=spi_bus_add_flash_device(&espFlash,&spiDeviceConfig );
    ESP_LOGI(LOG,"after");
    esp_flash_init(espFlash);
    return err;
}
uint32_t get_id(){
    uint32_t id;
    esp_flash_read_id(espFlash,&id);
    return id;
}
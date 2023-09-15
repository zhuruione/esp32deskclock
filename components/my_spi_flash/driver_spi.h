//
// Created by zr on 3/1/23.
//

#ifndef SPI_FLASH_DRIVER_SPI_H
#define SPI_FLASH_DRIVER_SPI_H
#include "driver/spi_master.h"


esp_err_t spi_init(spi_device_handle_t *flash_handle);
esp_err_t sendCmd(spi_device_handle_t flash_handle, uint8_t cmd, bool keep_alive);
esp_err_t sendByte(spi_device_handle_t flash_handle, void *buffer, size_t length, bool keep_alive);
esp_err_t receiveByte(spi_device_handle_t flash_handle, void *buffer, size_t length, bool keep_alive);
esp_err_t sendAddr(spi_device_handle_t flash_handle, uint32_t addr, bool keep_alive);
esp_err_t sendDummy(spi_device_handle_t flash_handle);
#endif //SPI_FLASH_DRIVER_SPI_H

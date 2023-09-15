//
// Created by zr on 3/7/23.
//

#ifndef ESP_MAIN_FLASH_ESP_H
#define ESP_MAIN_FLASH_ESP_H

#include <esp_err.h>

esp_err_t flash_init();
uint32_t get_id();
#endif //ESP_MAIN_FLASH_ESP_H

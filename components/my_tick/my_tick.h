//
// Created by zr on 3/3/23.
//

#ifndef SPI_FLASH_MY_TICK_H
#define SPI_FLASH_MY_TICK_H
#include "driver/gptimer.h"

void timerInit(gptimer_handle_t *timer_handle);
int timeCountStart(gptimer_handle_t gptimerHandle);
int timeCountend(gptimer_handle_t gptimerHandle);

#endif //SPI_FLASH_MY_TICK_H

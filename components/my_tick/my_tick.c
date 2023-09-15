//
// Created by zr on 3/3/23.
//
#include "my_tick.h"
void timerInit(gptimer_handle_t *timer_handle) {
    gptimer_config_t timer_config = {
            .clk_src=GPTIMER_CLK_SRC_APB,
            .direction=GPTIMER_COUNT_UP,
            .resolution_hz=1000 * 1000, // 1MHz, 1 tick = 1us
    };
    gptimer_new_timer(&timer_config, timer_handle);
    gptimer_enable(*timer_handle);
}

int timeCountStart(gptimer_handle_t gptimerHandle) {
    gptimer_start(gptimerHandle);
    uint64_t timecount;
    gptimer_get_raw_count(gptimerHandle, &timecount);
    return (int) timecount;
}

int timeCountend(gptimer_handle_t gptimerHandle) {
    gptimer_stop(gptimerHandle);
    uint64_t timecount;
    gptimer_get_raw_count(gptimerHandle, &timecount);
    return (int) timecount;
}
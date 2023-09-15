#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <sys/unistd.h>
#include <errno.h>
#include "driver/gpio.h"
#include "zr_wifi.h"
#include "stdio.h"
#include "esp_log.h"
#include "lvgl.h"
#include "gettime.h"
#include "my_flash_spi.h"
#define TAG "ledClient"
typedef struct {
    int arg1;
    int arg2;
} args;
void ledClient(){
    int fd,flag=0;
    int size=0;
    char buffer[128];

    flag=getSocket(&fd);
    if (flag==-1){
        ESP_LOGE(TAG,"getSocket failed! exit the ledClient task  \n");
        vTaskDelete(xTaskGetCurrentTaskHandle());
    }
    while (1){
        uint8_t num;
        size=read(fd,&num,sizeof(uint8_t));
        switch (size) {
            case -1:
                ESP_LOGE(TAG,"read failed  errno=%d",errno);
                vTaskDelete(xTaskGetCurrentTaskHandle());
            case 0:
                continue;
        }
        if(num=='0'){
            gpio_set_level(GPIO_NUM_32,0);
        } else if (num=='1'){
            gpio_set_level(GPIO_NUM_32,1);
        }
        write(fd,&num,sizeof(uint8_t));
    }
}


// 主任务
void app_main() {
    // 初始化LittlevGL库
    lv_init();

    // 创建屏幕
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = lvgl_flush;
    lv_disp_drv_register(&disp_drv);

    // 创建一个页面
    lv_obj_t *weather_clock_page = lv_page_create(NULL, NULL);
    lv_obj_set_size(weather_clock_page, LV_HOR_RES, LV_VER_RES);
    lv_scr_load(weather_clock_page);

    // 创建天气时钟界面
    create_weather_clock_page(weather_clock_page);
    esp_timer_create_args_t timer_args = {
            .callback = &update_weather_data,
            .name = "weather_update_timer"
    };
    esp_timer_handle_t weather_update_timer;
    esp_timer_create(&timer_args, &weather_update_timer);
    esp_timer_start_periodic(weather_update_timer, 5000); // 5秒更新一次天气数据

    while (1) {
        // 处理LVGL事件
        lv_task_handler();
        vTaskDelay(10);
    }
}


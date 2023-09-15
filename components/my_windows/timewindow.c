#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "lvgl.h"
#include "lvgl_helpers.h"
#include "esp_system.h"
#include "gettime.h"

// 更新时间并刷新界面
static void update_time() {
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);
    char time_str[32];
    strftime(time_str, sizeof(time_str), "%H:%M:%S", &timeinfo);
    lv_obj_t *time_label = lv_obj_get_child(lv_scr_act(), NULL);
    lv_label_set_text(time_label, time_str);
}



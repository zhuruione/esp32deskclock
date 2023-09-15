#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "lvgl/lvgl.h"
#include "lvgl/lvgl_helpers.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_http_client.h"
#include "json_parser.h"

typedef struct {
    char description[50];
    float temperature;
} WeatherData;

static WeatherData currentWeather = {"Unknown", 0.0};


// HTTP事件处理器
esp_err_t http_event_handler(esp_http_client_event_t *evt) {
    switch (evt->event_id) {
        case HTTP_EVENT_ON_DATA:
            // 解析JSON数据
            json_parser_parse(evt->data, evt->data_len, &currentWeather);
            break;
        default:
            break;
    }
    return ESP_OK;
}

// 获取天气数据
void get_weather_data() {
    esp_http_client_config_t config = {
            .url = WEATHER_API_URL,
            .event_handler = http_event_handler,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_http_client_perform(client);
    esp_http_client_cleanup(client);
}

// 创建天气界面
void create_weather_page(lv_obj_t *parent) {
    // 创建一个标签来显示天气描述
    lv_obj_t *weather_label = lv_label_create(parent, NULL);
    lv_label_set_text(weather_label, "Weather: Unknown");
    lv_obj_align(weather_label, NULL, LV_ALIGN_IN_TOP_LEFT, 20, 10);

    // 创建一个标签来显示温度
    lv_obj_t *temp_label = lv_label_create(parent, NULL);
    lv_label_set_text(temp_label, "Temperature: 0.0°C");
    lv_obj_align(temp_label, NULL, LV_ALIGN_IN_TOP_LEFT, 20, 50);
}

// 更新天气界面
void update_weather_page() {
    // 获取界面中的标签对象并更新文本
    lv_obj_t *weather_label = lv_obj_get_child(lv_scr_act(), NULL);
    lv_label_set_text_fmt(weather_label, "Weather: %s", currentWeather.description);

    lv_obj_t *temp_label = lv_obj_get_child(lv_scr_act(), weather_label);
    lv_label_set_text_fmt(temp_label, "Temperature: %.1f°C", currentWeather.temperature);
}


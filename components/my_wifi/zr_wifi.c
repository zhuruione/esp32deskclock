//
// Created by zr on 23-4-16.
//

#include "zr_wifi.h"
#include <esp_err.h>
#include <string.h>
#include <esp_log.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <freertos/FreeRTOS.h>

void test();

static void event_handler(void *arg, esp_event_base_t event_base,
                          int32_t event_id, void *event_data) {
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        printf("wifi started!\n");
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        printf("wifi disconnected!  try reconnect\n");
        esp_err_t err=esp_wifi_connect();
        wifi_event_sta_disconnected_t *resaon=(wifi_event_sta_disconnected_t *)event_data;
        printf("%d  %u\n",err,resaon->reason);
        if (err!=ESP_OK){
            ESP_LOGE("wifi","connect failed errno=%d",err);
        }
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *) event_data;
        ESP_LOGI("TAG", "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
        TaskHandle_t client_handle;
        xTaskCreatePinnedToCore(arg,"client",2048,NULL,1,&client_handle,0);
    }
}

void test(){

}

esp_err_t fast_scan() {
    uint16_t ap_num = 0;
    wifi_scan_config_t wifiScanConfig;
    wifi_ap_record_t wifiApRecord[10];


    memset(&wifiScanConfig, 0, sizeof(wifiScanConfig));
    wifiScanConfig.scan_type = WIFI_SCAN_TYPE_ACTIVE;
    esp_wifi_scan_start(&wifiScanConfig, true);

    errno = esp_wifi_scan_get_ap_num(&ap_num);
    printf("scan finish the ap num=%d\n", ap_num);
    esp_wifi_scan_get_ap_records(&ap_num, wifiApRecord);
    for (wifi_ap_record_t *it = wifiApRecord; it != NULL; it++) {
        printf("%s\n", it->ssid);
    }
    return errno;

}


esp_netif_t *wifi_init(cliFun fun) {
    esp_netif_t *espNetif;
    nvs_flash_init();
    wifi_init_config_t wifiInitConfig = WIFI_INIT_CONFIG_DEFAULT();

    esp_netif_init();

    //initialize the loop event
    esp_event_loop_create_default();
    esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL, NULL);
    esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, fun, NULL);

    espNetif = esp_netif_create_default_wifi_sta();
    errno = esp_wifi_init(&wifiInitConfig);
    if (errno != ESP_OK) {
        ESP_LOGE("main", "init error errno=%d", errno);
    }
    wifi_config_t wifi_config = {
            .sta = {
                    .ssid = "Aust_Studant",
                    .password = "22332233abc",
                    .scan_method = WIFI_FAST_SCAN,
            },
    };
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    esp_wifi_start();
    return espNetif;
}
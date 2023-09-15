//
// Created by zr on 9/15/23.
//
#include "gettime.h"
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "zr_wifi.h"
#define NTP_SERVER "remsuki.top"
#define NTP_PORT TiME_PORT
#define TAG "gettime"
timer_t getTime() {
    xTaskCreate(&ntp_client_task, "ntp_client_task", 4096, NULL, 5, NULL);
}
void ntp_client_task(void *pvParameters) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // 初始化网络连接
    wifi_init(NULL);

    // 创建套接字
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        ESP_LOGE(TAG, "Failed to create socket");
        vTaskDelete(NULL);
        return;
    }

    // 获取NTP服务器的IP地址
    server = gethostbyname(NTP_SERVER);
    if (server == NULL) {
        ESP_LOGE(TAG, "Failed to get server address");
        close(sockfd);
        vTaskDelete(NULL);
        return;
    }


    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(NTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);


    unsigned char ntp_packet[48];
    memset(ntp_packet, 0, sizeof(ntp_packet));
    ntp_packet[0] = 0x1B;


    if (sendto(sockfd, ntp_packet, sizeof(ntp_packet), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        ESP_LOGE(TAG, "Failed to send NTP request");
        close(sockfd);
        vTaskDelete(NULL);
        return;
    }
    unsigned char ntp_response[48];
    socklen_t server_addr_len = sizeof(server_addr);
    if (recvfrom(sockfd, ntp_response, sizeof(ntp_response), 0, (struct sockaddr *)&server_addr, &server_addr_len) < 0) {
        ESP_LOGE(TAG, "Failed to receive NTP response");
        close(sockfd);
        vTaskDelete(NULL);
        return;
    }

    uint32_t ntp_timestamp = (ntp_response[43] << 24) | (ntp_response[42] << 16) | (ntp_response[41] << 8) | ntp_response[40];

    // 计算时间
    time_t now = (time_t)(ntp_timestamp - 2208988800U);

    // 打印时间
    struct tm timeinfo;
    localtime_r(&now, &timeinfo);
    ESP_LOGI(TAG, "NTP Time: %s", asctime(&timeinfo));

    // 关闭套接字
    close(sockfd);

    vTaskDelete(NULL);
}

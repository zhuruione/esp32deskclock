//
// Created by zr on 23-4-18.
//
#include "zr_wifi.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <freertos/FreeRTOS.h>
#include "esp_log.h"
#include "time.h"

struct addrinfo *hostaddr;

int getSocket(int *fd) {
    int flag = 0;
    *fd = socket(AF_INET, SOCK_STREAM, 0);
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;
    hints.ai_flags = AI_NUMERICSERV;
    errno = getaddrinfo(HOST_ADDR, HOST_PORT, &hints, &hostaddr);
    struct sockaddr_in *host_addr = (struct sockaddr_in *) hostaddr->ai_addr;
    if (0 != errno) {
        ESP_LOGE("getaddrinfo", "dns failed  errno=%d", errno);
    } else {
        ESP_LOGI("DNS", "get dns success,the %s ip=%s", HOST_ADDR, inet_ntoa(host_addr->sin_addr));
    }
    if (0 != connect(*fd, hostaddr->ai_addr, hostaddr->ai_addrlen)) {
        ESP_LOGE("connect", "connect failed  errno=%d", errno);
        flag = -1;
    } else {
        ESP_LOGI("connect", "connect success fd=%d", *fd);
        flag = 0;
    }
    return flag;
}

void reConnect(int fd) {
    int flag = 0;
    const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
    closesocket(fd);
    fd = socket(AF_INET, SOCK_STREAM, 0);

    for (int i = 0; i < 5; i++) {
        flag = connect(fd, hostaddr->ai_addr, hostaddr->ai_addrlen);
        if (flag == 0) {
            ESP_LOGI("reconnect", "connect success");
            break;
        } else {
            ESP_LOGE("reconnect", "%d connect failed 1s later ", i + 1);
            vTaskDelay(xDelay);
        }
    }
    if (flag != 0) {
        ESP_LOGE("reconnect", "reconnect failed!!!!");
    }
}

void client(void *value) {
    int fd = 0;
    Msg msg;
    if (getSocket(&fd) == -1) {
        ESP_LOGE("client", "get socket failed  ");
        vTaskSuspend(xTaskGetCurrentTaskHandle());
    }
    ssize_t size_to_recv=0;
    while (1) {
        size_to_recv=recv(fd, &msg, sizeof(Msg), 0);
        if (msg.tpye == MESSAGE)
            printf("size has raad=%u  tpye: %d,time=%lld,size=%d\n",size_to_recv, msg.tpye, msg.time, msg.len);
        msg.tpye=0;
    }

}

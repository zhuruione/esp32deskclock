//
// Created by zr on 23-4-16.
//

#ifndef ESP_MAIN_ZR_WIFI_H
#define ESP_MAIN_ZR_WIFI_H

#include <esp_wifi.h>
#include <nvs_flash.h>
//#define SSID "Aust_Studant"
//#define PWD "22332233abc"

#define HOST_ADDR "192.168.50.81"
#define HOST_PORT "3333"

typedef void (*cliFun)(void) ;
typedef enum{
    MESSAGE=1,
    DATAS,
    COMMAND,
}MSG_TYPE;

typedef struct {
    uint8_t ishead;
    MSG_TYPE tpye;
    time_t time;
    ssize_t len;
}Msg;


//zr_wifi
esp_netif_t* wifi_init(cliFun fun);
esp_err_t fast_scan();

//client
int getSocket(int *fd);
void reConnect(int fd);
void client(void *value);
#endif //ESP_MAIN_ZR_WIFI_H

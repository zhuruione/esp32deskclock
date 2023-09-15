//
// Created by zr on 3/1/23.
//
#include <esp_log.h>
#include "my_flash_spi.h"
#include "freertos/timers.h"
#include "../my_tick/my_tick.h"

static const char *LOGNAME = "my_flash_spi";
static gptimer_handle_t gptimerHandle;
static spi_device_handle_t flash_handle;

static headQueue *head_queue;

void TimerCallback(TimerHandle_t xTimer) { //软件定时器执行函数
    waitForBusy("TimerCallback");
    chipErase();
}


esp_err_t flashInit() {
    esp_err_t err = spi_init(&flash_handle);
    if (err == 0) {
        ESP_LOGI(LOGNAME, "flashInit ok!!");
    } else
        ESP_LOGE(LOGNAME, "my_flash_spi init failed  err=%d", err);
    //创建读写记忆表
    head_queue=(headQueue *) malloc(sizeof (headQueue));
    head_queue->head=NULL;
    head_queue->end=NULL;
    head_queue->size=0;
    timerInit(&gptimerHandle);
    //创建软件计时器
    xTimerCreate("FlashTimer", pdMS_TO_TICKS(1000), pdFALSE, (void *) 1, TimerCallback);
    return err;
}

esp_err_t writeEnable() {
    return sendCmd(flash_handle, 0x6, false);
}

void waitForBusy(char *name) {
    sendCmd(flash_handle, 0x5, true);
    uint8_t status = 0;
    int start = timeCountStart(gptimerHandle);
    while (1) {
        receiveByte(flash_handle, &status, 1, true);
        if ((status & 1U) == 0) {
            receiveByte(flash_handle, &status, 1, false);
//            ESP_LOGI(LOGNAME, "[%s] wait for busy time= %d us",name, timeCountend(gptimerHandle) - start);
            break;
        }
    }
}

//void getFlashHead(uint32_t addr,size_t length,uint8_t *table) {
//    waitForBusy("getFlashHead");
//    uint32_t end_addr=addr+length;
//    sendCmd(flash_handle, 0x3, true);
//    headNode *node=NULL;
//    for (int i = 0; i < head_queue->size; ++i) {
//        headNode *head_node=head_queue->end;
//        if (addr>=node->begin_addr&&addr<end_addr){ //当前需要的head已经在queue内
//            node=head_node;
//            table=node->table;
//        } else
//            head_node=head_node->next;
//    }
//    if (node==NULL){
//        node=(headNode *) malloc(sizeof (headNode));
//        //addr与头地址转换
//        uint32_t head_addr=addr>>11;
//        sendAddr(flash_handle, head_addr, true);
//        receiveByte(flash_handle, node->table, 16, false); //可以表示8*16=128个页面  32768 个字节0x8000
//        table=node->table;
//        for (int i = 0; i < 16; ++i) {
//            printf("%x ", node->table[i]);
//        }
//    }
//
//}

void chipErase() {
    waitForBusy("chipErase");
    writeEnable();
    sendCmd(flash_handle, 0x60, false);
    waitForBusy("chipErase");
}

uint8_t readStatus() {
    sendCmd(flash_handle, 0x5, true);
    uint8_t status = 0;
    receiveByte(flash_handle, &status, 1, false);
    return status;
}


uint32_t getId() {
    sendCmd(flash_handle, 0x9f, true);
    uint8_t id[3] = {0};
    receiveByte(flash_handle, id, 3, false);
    return (id[0] << 16) + (id[1] << 8) + id[2];
}

esp_err_t sectorErase(uint32_t addr) {
    waitForBusy("sectorErase");
    addr = addr >> 12 << 12;
    ESP_LOGW("sectorErase","address %lx will be erase",addr);
    writeEnable();
    sendCmd(flash_handle, 0x20, true);
    esp_err_t err = sendAddr(flash_handle, addr, false);
    return err;
}

esp_err_t pageProgram(uint32_t addr, void *buffer, size_t length) {
    waitForBusy("pageProgram");
    writeEnable();
    sendCmd(flash_handle, 0x2, true);
//    printf("[%c] [%c] [%c]\n",((char*)buffer)[0],((char*)buffer)[1],((char*)buffer)[2]);
    sendAddr(flash_handle, addr, true);
    return sendByte(flash_handle, buffer, length, false);
}

esp_err_t sectorProgram(uint32_t addr, void *buffer, size_t length) {
    waitForBusy("sectorProgram");
    char *data = (char *) malloc(4096 * sizeof(char));
    uint32_t sectorAddress = addr >> 12 << 12;
    readDate(sectorAddress, data, 4096);
    sectorErase(sectorAddress);
    uint32_t head = addr - sectorAddress;
    for (int i = 0; i < length; i++) {
        data[head + i] = ((char *) buffer)[i];
    }
    char *data_index = data;
    for (int i = 0; i < 16; i++) {
        pageProgram(sectorAddress, data_index, 256);
        sectorAddress += 256;
        data_index += 256;
    }
    free(data);
    return 0;
}

esp_err_t readDate(uint32_t addr, void *buffer, size_t length) {
    waitForBusy("readDate");
    sendCmd(flash_handle, 0x3, true);
    sendAddr(flash_handle, addr, true);
    return receiveByte(flash_handle, buffer, length, false);
}

esp_err_t writeDate(uint32_t addr, void *buffer, size_t length) {
    if (addr + length > W25Q64_MAX_ADDR) {
        ESP_LOGE(LOGNAME, "Exceed the max length,the max address length=0x400000");
        return -1;
    }
    while (length > 256) {
        ESP_LOGI(LOGNAME, "Enter the while");
        pageProgram(addr, buffer, 256);
        length -= 256;
        buffer += 256;
        addr += 256;
    }
    return pageProgram(addr, buffer, length);
}




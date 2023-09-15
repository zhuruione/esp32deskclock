//
// Created by zr on 3/1/23.
//

#ifndef SPI_FLASH_MY_FLASH_SPI_H
#define SPI_FLASH_MY_FLASH_SPI_H
#include "driver_spi.h"
#define W25Q64_MAX_ADDR 0x800000

typedef struct headNode{
    uint8_t table[16];
    uint32_t begin_addr;
    uint32_t end_addr;
    struct headNode *next;
}headNode;
typedef struct headQueue{
    headNode *head;
    headNode *end;
    size_t size;
}headQueue;
//一共8MB 8388608Byte  每个Block等于4096byte 则有2048个Block  16进制为0x800
//每个页面记录是否读写 一共有2^23/2^8 =2^15个page 每个字节表示一位2^15/2^3 则通过2^12位表示 16进制表示为0x1000


esp_err_t flashInit();
void waitForBusy(char *name);
void getFlashHead(uint32_t addr,size_t length);
void chipErase();
uint32_t getId();
uint8_t readStatus();
esp_err_t writeEnable();
esp_err_t readDate(uint32_t addr,void *buffer,size_t length);
esp_err_t writeDate(uint32_t addr,void *buffer,size_t length);
esp_err_t sectorErase(uint32_t addr);
esp_err_t pageProgram(uint32_t addr, void *buffer, size_t length);
esp_err_t sectorProgram(uint32_t addr, void *buffer, size_t length);
#endif //SPI_FLASH_MY_FLASH_SPI_H

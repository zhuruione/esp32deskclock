//
// Created by zr on 3/5/23.
//

#ifndef SPI_FLASH_FILE_ZR_H
#define SPI_FLASH_FILE_ZR_H
#include "my_flash_spi.h"

struct file_node{
    uint32_t addr;
    uint32_t size;
    uint16_t page_size;
    uint16_t page_long;
    char name[100];
    char black[144];

};
//第一个文件目录表从0x1000开始  共有16个page 可保存15个文件 最后一个page保存下个目录表的位置信息 ，每个page前4个字节保存文件首地址；再4个字节表示大小，单位为byte，在后面两个字节表示使用了几个连续的page，再后面两个字节表示了这个首地址后面有几个page属于这个文件
//|address 4|size 4|page size 2|page long 2|name 100|none 144|


#endif //SPI_FLASH_FILE_ZR_H

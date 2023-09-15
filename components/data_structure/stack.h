//
// Created by zr on 3/5/23.
//

#ifndef SPI_FLASH_STACK_H
#define SPI_FLASH_STACK_H

typedef struct mystack * stack;
int createStack(stack s);
void destroyStack(stack s);
int clearStack(stack s);
int push(stack s,void *date);
void* pop(stack s);

#endif //SPI_FLASH_STACK_H

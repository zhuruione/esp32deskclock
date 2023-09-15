//
// Created by zr on 3/5/23.
//
#include "stack.h"
#include <memory.h>
typedef struct node{
    void *value; //当前节点数据
    struct node *next; //下个节点指针
} node;
struct mystack {
    node *top;
    int stack_size;
};
int createStack(stack s) {
    s = (stack) malloc(sizeof(stack));
    if (s) {
        s->top = NULL;
        s->stack_size = 0;
        return 1;
    } else {
        return 0;
    }

}

void destroyStack(stack s) {
    free(s);
}

int clearStack(stack s) {
    while (s->stack_size > 0) {
        pop(s);
    }
    if (s->stack_size==0)
        return 1;
    else
        return 0;
}

int push(stack s,void *date) {
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node==NULL){
        return 0;
    }
    new_node->value=date;
    new_node->next=s->top;
    s->top=new_node;
    s->stack_size++;
    return 1;
}
void* pop(stack s){
    if (s->stack_size==0){
        return 0;
    }
    void *date=s->top->value;
    s->top=s->top->next;
    s->stack_size--;
    free(s->top);
    return date;
}
void *getTop(stack s){
    if (s->stack_size==0){
        return 0;
    }
    return s->top->value;
}
//
// Created by Saika on 2024/6/16.
// 顺序表的定义 （动态分配）
//

#include "List_1.h"
#include "stdio.h"
#include "stdlib.h"

#define InitSize 10

typedef struct {
    // 指示动态分配数组的指针
    int *data;
    // 用静态数组存放数据元素
    int MaxSize;
    // 数据表的当前长度
    int length;
} SeqList;

// 基本操作——初始化一个顺序表
void InitList(SeqList &L) {
    // 用 malloc 申请一片连续的存储空间

    L.length = 0;
}

int main() {
    SqList L;
    InitList(L);
    for (int i = 0; i < MaxSize; i++) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }

    return 0;
}
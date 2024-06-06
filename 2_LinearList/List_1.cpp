//
// Created by Saika on 2024/6/16.
// 顺序表的定义 （静态分配）
//

#include "List_1.h"
#include "stdio.h"

#define MaxSize 10

typedef struct {
    // 用静态数组存放数据元素
    int data[MaxSize];
    // 数据表的当前长度
    int length;
} SqList;

// 基本操作——初始化一个顺序表
void InitList(SqList &L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;
    }
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
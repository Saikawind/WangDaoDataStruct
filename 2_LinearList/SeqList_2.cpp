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
    L.data = (int *) malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

// 增加动态数组的长度
void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;
    L.data = (int *) malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++) {
        // 将数据复制到新区域
        L.data[i] = p[i];
    }
    // 顺序表最大长度增加 len
    L.MaxSize = L.MaxSize + len;
    // 释放原来的内存空间
    free(p);
}

// 按位查找
int GetElem(SeqList L, int i) {
    return L.data[i - 1];
}

// 按值查找
int LocateElem(SeqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

int main() {
    SeqList L;
    // 初始化顺序表
    InitList(L);
    // 往顺序表中随便插入几个元素
    IncreaseSize(L, 5);
    for (int i = 0; i < L.MaxSize; ++i) {
        printf("%d, data=[%d]\n", i, L.data[i]);
    }

    return 0;
}
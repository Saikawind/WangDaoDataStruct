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

// 插入操作
bool ListInsert(SqList &L, int i, int e) {
    // 判断 i 的范围是否有效
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;

    // 将第 i 个元素及之后的元素后移
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    // 在位置 i 处放入 e
    L.data[i - 1] = e;
    L.length++;

    return true;
}

// 删除操作
bool ListDelete(SqList &L, int i, int &e) {
    if (i < 1 || i > L.length + 1)
        return false;
    // 将被删除的元素赋值给 e
    e = L.data[i - 1];
    for (int j = i; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

// 按位查找
int GetElem(SqList L, int i) {
    return L.data[i - 1];
}

// 按值查找，在顺序表 L 中查找第一个元素值等于 e 的元素，并返回其位序
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}


int main() {
    SqList L;
    InitList(L);
    ListInsert(L, 3, 3);
    int deleteNum = 0;
    if (ListDelete(L, 3, deleteNum))
        printf("已删除第 3 个元素， 删除元素值为=%d\n", deleteNum);
    else
        printf("位序i不合法，删除失败\n");
    printf("deleteNum is %d\n", deleteNum);
    // 打印列表，测试
    for (int i = 0; i < MaxSize; i++) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }

    return 0;
}
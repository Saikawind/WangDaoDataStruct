//
// Created by Saika on 2024/7/11.
// 循环双链表
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 修正了宏定义为正确的类型定义

// 定义单链表节点类型
typedef struct DNode {
    // 数据域
    ElemType data;
    // 指针域
    struct DNode *prior, *next;
} DNode, *DLinkList;
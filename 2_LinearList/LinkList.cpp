//
// Created by Saika on 2024/6/16.
// 单链表定义
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 修正了宏定义为正确的类型定义

// 定义单链表节点类型
typedef struct LNode {
    // 数据域
    ElemType data;
    // 指针域
    struct LNode *next;
} LNode, *LinkList;


// 带头结点的单链表初始化
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL) {
        return false; // 分配内存失败
    }
    L->next = NULL;
    return true;
}

// 不带头结点的单链表初始化
bool InitListNoHead(LinkList &L) {
    L = NULL;
    return true;
}

// 求表长（带头结点）
int length(LinkList &L) {
    LNode *p = L;
    int length = 0;
    // 单链表的长度不包括头结点
    while (p->next != NULL) {
        p = p->next;
        length++;
    }

    return length;
}

// 求表长（不带头结点）
int LengthNoHead(LinkList &L) {
    LNode *p = L;
    int length = 0;
    while (p != NULL) {
        p = p->next;
        length++;
    }

    return length;
}

// 按位序插入（带头结点）：在第 i 个位置插入元素 e
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1)
        return false;
    LNode *p;
    // 当前 p 指向的是第几个结点
    int j = 0;
    // L 指向头结点，头结点是第 0 个结点（不存数据）
    p = L;
    // 循环找到第 i-1 个结点
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    // i 值不合法
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}

// 按位序插入（不带头结点）：在第 i 个位置插入元素 e
bool ListInsertNoHead(LinkList &L, int i, ElemType e) {
    if (i < 1)
        return false;
    if (i == 1) {
        LNode *s = (LNode *) malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        // 头指针指向新结点
        L = s;
        return true;
    }
    // p 指向第1个结点（不是头结点）
    LNode *p = L;
    // 当前 p 指向的是第几个结点
    int j = 1;
    // 循环找到第 i-1 个结点
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    // i 值不合法
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) {
        return false; // 分配内存失败
    }
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}

// 后插操作：在 p 结点之后插入元素 e
bool InsertNextNode(LNode *p, ElemType e) {
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    // 内存分配失败
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 前插操作：在 p 结点之前插入元素 e（无需头结点且时间复杂度低——交换覆盖的方法）
bool InsertPriorNode(LNode *p, ElemType e) {
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    // 新结点 s 连接到 p 之后
    p->next = s;
    // 将 p 中元素复制到 s 中
    s->data = p->data;
    // p 中元素覆盖为 e
    p->data = e;

    return true;
}

// 前插操作（需要传入头结点的传统方法）
bool InsertPriorNodeHead(LinkList L, LNode *p, ElemType e) {
    return true;
};

// 按位序删除（带头结点）：删除第 i 个位置的元素，并用 e 返回删除元素的值
bool ListDelete(LinkList &L, int i, ElemType &e) {
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    // 第 i-1 个结点之后已无其他结点
    if (p->next == NULL)
        return false;
    // 令 q 指向将被删除的结点
    LNode *q = p->next;
    // 用 e 返回元素的值
    e = q->data;
    // 将*q 结点从链中断开
    p->next = q->next;
    // 释放结点的存储空间
    free(q);

    return true;
}

// 删除指定节点 p（扩展版本）：如果 p 是最后一个结点，则无法处理
bool DeleteNode(LNode *p) {
    if (p == NULL || p->next == NULL) {
        return false;
    }
    // 令 q 指向 *p 的后继节点
    LNode *q = p->next;
    // 和后继节点交换数据
    p->data = q->data;
    // 将 *q 结点从链中“断开”
    p->next = q->next;
    // 释放后继节点的存储空间
    free(q);
    return true;
}


// 按位序删除（不带头结点）
bool ListDeleteNoHead(LinkList &L, int i, ElemType &e) {
    if (i < 1 || L == NULL)
        return false;
    LNode *p = L;
    // 删除第一个结点
    if (i == 1) {
        e = p->data;
        L = p->next;
        free(p);
        return true;
    }
    int j = 1;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    // 第 i-1 个结点之后已无其他结点
    if (p->next == NULL)
        return false;
    // 令 q 指向将被删除的结点
    LNode *q = p->next;
    // 用 e 返回元素的值
    e = q->data;
    // 将*q 结点从链中断开
    p->next = q->next;
    // 释放结点的存储空间
    free(q);

    return true;
}


// 按位查找，返回第 i 个元素（带头结点）头结点被视为第 0 个结点
LNode *GetElem(LinkList L, int i) {
    if (i < 0)
        return NULL;
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }

    return p;
}

// 按值查找（带头结点）
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    // 从第 1 个结点开始查找数据域为 e 的结点
    while (p != NULL && p->data != e)
        p = p->next;
    // 找到后返回该结点指针，否则返回 NULL
    return p;
}

// 封装调用后的带头结点按序插入
bool ListInsertOptimize(LinkList &L, int i, ElemType e) {
    if (i < 1)
        return false;
    // 找到第 i-1 个结点
    LNode *p = GetElem(L, i - 1);

    return InsertNextNode(p, e);
}

// 尾插法建立单链表
LinkList ListTailInsert(LinkList &L) {
    int x;
    // 建立头结点
    L = (LinkList) malloc(sizeof(LNode));
    // r 为表尾指针
    LNode *s, *r = L;
    scanf("%d", &x);
    // 输入999表示结束输入
    while (x != 999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        // r 指向新的表尾结点
        r = s;
        scanf("%d", &x);
    }
    // 表尾结点指针置空
    r->next = NULL;
    return L;
}

// 头插法建立单链表——重要应用，链表的逆置
LinkList ListHeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }

    return L;
}


// 测试函数
void test() {
    LinkList L;
    InitList(L);
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    ElemType e;
    ListDelete(L, 2, e);
    printf("Deleted element: %d\n", e);
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    test();
    return 0;
}

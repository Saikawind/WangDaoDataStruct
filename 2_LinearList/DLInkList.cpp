//
// Created by Saika on 2024/7/11.
// 双链表
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


// 双链表初始化
bool InitLinkList(DLinkList &L) {
    // 分配头结点
    L = (DNode *) malloc(sizeof(DNode));
    // 分配失败
    if (L == NULL)
        return false;
    // 头结点的 prior 始终指向 NULL
    L->prior = NULL;
    // 头结点之后暂时没有结点
    L->next = NULL;

    return true;
}

// 双链表的插入（后插法）
bool InsertNextDNode(DNode *p, DNode *s) {
    // 非法参数
    if (p == NULL || s == NULL)
        return false;
    // 将结点 *s 插入到结点 *p 之后
    s->next = p->next;
    // 判断 p 结点是否有后继节点，防止p指向最后一个结点时插入报错
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;

    return true;
}

// 双链表的前插法



// 双链表的删除
bool DeleteNextDNode(DNode *p) {
    if (p == NULL) return false;
    // 找到 p 的后继节点 q
    DNode *q = p->next;
    // 若 p 没有后继
    if (q == NULL) return false;
    p->next = q->next;
    // 判断 q 结点是不是最后一个结点
    if (q->next != NULL)
        q->next->prior = p;
    free(q);

    return true;
}

// 销毁双链表
void DestroyList(DLinkList &L) {
    // 循环释放各个数据节点
    while (L->next != NULL)
        DeleteNextDNode(L);
    free(L);
    L = NULL;
}

// 双链表的遍历，前向遍历，后向遍历，前向遍历（跳过头结点）




void test() {
    // 初始化双链表
    DLinkList L;
    InitLinkList(L);
    // 后续代码


}


int main() {


    return 0;
}
#include "iostream"
#include "stdlib.h"
#include "stdio.h"

/* 链表节点结构体 */
typedef struct ListNode {
    int val;               // 节点值
    struct ListNode *next; // 指向下一节点的指针
} ListNode;

/* 构造函数 */
ListNode *newListNode(int val) {
    ListNode *node;
    node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/* 在链表的节点 n0 之后插入节点 P */
void insert(ListNode *n0, ListNode *P) {
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

/* 删除链表的节点 n0 之后的首个节点 */
// 注意：stdio.h 占用了 remove 关键词
void removeItem(ListNode *n0) {
    if (!n0->next)
        return;
    // n0 -> P -> n1
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    // 释放内存
    free(P);
}

/* 访问链表中索引为 index 的节点 */
ListNode *access(ListNode *head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == NULL)
            return NULL;
        head = head->next;
    }
    return head;
}

/* 在链表中查找值为 target 的首个节点 */
int find(ListNode *head, int target) {
    int index = 0;
    while (head) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

/* 打印链表 */
void printList(ListNode *head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    /* 初始化链表 1 -> 3 -> 2 -> 5 -> 4 */
    // 初始化各个节点
    ListNode *n0 = newListNode(1);
    ListNode *n1 = newListNode(3);
    ListNode *n2 = newListNode(2);
    ListNode *n3 = newListNode(5);
    ListNode *n4 = newListNode(4);
    // 构建节点之间的引用
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // 打印初始链表
    printf("初始链表: ");
    printList(n0);

    // 在 n0 后插入节点 10
    ListNode *newNode = newListNode(10);
    insert(n0, newNode);
    printf("在 n0 后插入节点 10 后的链表: ");
    printList(n0);

    // 删除 n1 后的节点
    removeItem(n1);
    printf("删除 n1 后的节点后的链表: ");
    printList(n0);

    // 访问索引为 3 的节点
    ListNode *node = access(n0, 3);
    if (node) {
        printf("访问索引为 3 的节点: %d\n", node->val);
    } else {
        printf("访问索引为 3 的节点: NULL\n");
    }

    // 查找值为 2 的节点
    int index = find(n0, 2);
    if (index != -1) {
        printf("值为 2 的节点的索引: %d\n", index);
    } else {
        printf("值为 2 的节点未找到\n");
    }

    return 0;
}

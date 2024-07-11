#include "iostream"
#include "stdlib.h"
#include "stdio.h"

/* ����ڵ�ṹ�� */
typedef struct ListNode {
    int val;               // �ڵ�ֵ
    struct ListNode *next; // ָ����һ�ڵ��ָ��
} ListNode;

/* ���캯�� */
ListNode *newListNode(int val) {
    ListNode *node;
    node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/* ������Ľڵ� n0 ֮�����ڵ� P */
void insert(ListNode *n0, ListNode *P) {
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

/* ɾ������Ľڵ� n0 ֮����׸��ڵ� */
// ע�⣺stdio.h ռ���� remove �ؼ���
void removeItem(ListNode *n0) {
    if (!n0->next)
        return;
    // n0 -> P -> n1
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    // �ͷ��ڴ�
    free(P);
}

/* ��������������Ϊ index �Ľڵ� */
ListNode *access(ListNode *head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == NULL)
            return NULL;
        head = head->next;
    }
    return head;
}

/* �������в���ֵΪ target ���׸��ڵ� */
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

/* ��ӡ���� */
void printList(ListNode *head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    /* ��ʼ������ 1 -> 3 -> 2 -> 5 -> 4 */
    // ��ʼ�������ڵ�
    ListNode *n0 = newListNode(1);
    ListNode *n1 = newListNode(3);
    ListNode *n2 = newListNode(2);
    ListNode *n3 = newListNode(5);
    ListNode *n4 = newListNode(4);
    // �����ڵ�֮�������
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // ��ӡ��ʼ����
    printf("��ʼ����: ");
    printList(n0);

    // �� n0 �����ڵ� 10
    ListNode *newNode = newListNode(10);
    insert(n0, newNode);
    printf("�� n0 �����ڵ� 10 �������: ");
    printList(n0);

    // ɾ�� n1 ��Ľڵ�
    removeItem(n1);
    printf("ɾ�� n1 ��Ľڵ�������: ");
    printList(n0);

    // ��������Ϊ 3 �Ľڵ�
    ListNode *node = access(n0, 3);
    if (node) {
        printf("��������Ϊ 3 �Ľڵ�: %d\n", node->val);
    } else {
        printf("��������Ϊ 3 �Ľڵ�: NULL\n");
    }

    // ����ֵΪ 2 �Ľڵ�
    int index = find(n0, 2);
    if (index != -1) {
        printf("ֵΪ 2 �Ľڵ������: %d\n", index);
    } else {
        printf("ֵΪ 2 �Ľڵ�δ�ҵ�\n");
    }

    return 0;
}

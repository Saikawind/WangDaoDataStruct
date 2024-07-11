//
// Created by Saika on 2024/6/16.
// ˳���Ķ��� ����̬���䣩
//

#include "List_1.h"
#include "stdio.h"

#define MaxSize 10

typedef struct {
    // �þ�̬����������Ԫ��
    int data[MaxSize];
    // ���ݱ�ĵ�ǰ����
    int length;
} SqList;

// ��������������ʼ��һ��˳���
void InitList(SqList &L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;
    }
    L.length = 0;
}

// �������
bool ListInsert(SqList &L, int i, int e) {
    // �ж� i �ķ�Χ�Ƿ���Ч
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;

    // ���� i ��Ԫ�ؼ�֮���Ԫ�غ���
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    // ��λ�� i ������ e
    L.data[i - 1] = e;
    L.length++;

    return true;
}

// ɾ������
bool ListDelete(SqList &L, int i, int &e) {
    if (i < 1 || i > L.length + 1)
        return false;
    // ����ɾ����Ԫ�ظ�ֵ�� e
    e = L.data[i - 1];
    for (int j = i; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

// ��λ����
int GetElem(SqList L, int i) {
    return L.data[i - 1];
}

// ��ֵ���ң���˳��� L �в��ҵ�һ��Ԫ��ֵ���� e ��Ԫ�أ���������λ��
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
        printf("��ɾ���� 3 ��Ԫ�أ� ɾ��Ԫ��ֵΪ=%d\n", deleteNum);
    else
        printf("λ��i���Ϸ���ɾ��ʧ��\n");
    printf("deleteNum is %d\n", deleteNum);
    // ��ӡ�б�����
    for (int i = 0; i < MaxSize; i++) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }

    return 0;
}
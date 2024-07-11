#include "iostream"
#include "stdlib.h"
#include "stdio.h"

/* �������Ԫ�� */
int randomAccess(int *nums, int size) {
    // ������ [0, size) �������ȡһ������
    int randomIndex = rand() % size;
    // ��ȡ���������Ԫ��
    int randomNum = nums[randomIndex];
    return randomNum;
}

/* ����������� index ������Ԫ�� num */
void insert(int *nums, int &size, int num, int index) {
    // ������ index �Լ�֮�������Ԫ������ƶ�һλ
    for (int i = size; i > index; i--) {
        nums[i] = nums[i - 1];
    }
    // �� num ���� index ����Ԫ��
    nums[index] = num;
    size++;
}

/* ɾ������ index ����Ԫ�� */
// ע�⣺stdio.h ռ���� remove �ؼ���
void removeItem(int *nums, int &size, int index) {
    // ������ index ֮�������Ԫ����ǰ�ƶ�һλ
    for (int i = index; i < size - 1; i++) {
        nums[i] = nums[i + 1];
    }
    size--;
}

/* �������� */
void traverse(int *nums, int size) {
    printf("��ӡ����\n");

    // ͨ��������������
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/* �������в���ָ��Ԫ�� */
// ��ֵ����
int find(int *nums, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

/* ��չ���鳤�� */
int *extend(int *nums, int size, int enlarge) {
    // ��ʼ��һ����չ���Ⱥ������
    int *res = (int *) malloc(sizeof(int) * (size + enlarge));
    // ��ԭ�����е�����Ԫ�ظ��Ƶ�������
    for (int i = 0; i < size; i++) {
        res[i] = nums[i];
    }
    // ��ʼ����չ��Ŀռ�
    for (int i = size; i < size + enlarge; i++) {
        res[i] = 0;
    }
    // ������չ���������
    return res;
}

int main() {
    /* ��ʼ������ */
    int arr[10] = {0}; // { 0, 0, 0, 0, 0 }
    int nums[6] = {1, 3, 2, 5, 4};
    int length = 5; // ��ʼ��ʱ������ʵ�ʴ洢��Ԫ�ظ���

    int num = randomAccess(nums, length);
    printf("%d\n", num);

    // ����Ԫ��
    insert(nums, length, 10, 1);
    traverse(nums, length);

    // ����Ԫ��
    int index = find(nums, length, 2);
    printf("�� nums �в���Ԫ�� 2 ���õ����� = %d\n", index);

    // ��չ����
    int *newNums = extend(nums, length, 3);
    length += 3; // �������鳤��
    traverse(newNums, length);

    // �ͷž������ڴ�
    free(newNums);

    return 0;
}

#include "iostream"
#include "stdlib.h"
#include "stdio.h"

/* 随机访问元素 */
int randomAccess(int *nums, int size) {
    // 在区间 [0, size) 中随机抽取一个数字
    int randomIndex = rand() % size;
    // 获取并返回随机元素
    int randomNum = nums[randomIndex];
    return randomNum;
}

/* 在数组的索引 index 处插入元素 num */
void insert(int *nums, int &size, int num, int index) {
    // 把索引 index 以及之后的所有元素向后移动一位
    for (int i = size; i > index; i--) {
        nums[i] = nums[i - 1];
    }
    // 将 num 赋给 index 处的元素
    nums[index] = num;
    size++;
}

/* 删除索引 index 处的元素 */
// 注意：stdio.h 占用了 remove 关键词
void removeItem(int *nums, int &size, int index) {
    // 把索引 index 之后的所有元素向前移动一位
    for (int i = index; i < size - 1; i++) {
        nums[i] = nums[i + 1];
    }
    size--;
}

/* 遍历数组 */
void traverse(int *nums, int size) {
    printf("打印数组\n");

    // 通过索引遍历数组
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/* 在数组中查找指定元素 */
// 按值查找
int find(int *nums, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

/* 扩展数组长度 */
int *extend(int *nums, int size, int enlarge) {
    // 初始化一个扩展长度后的数组
    int *res = (int *) malloc(sizeof(int) * (size + enlarge));
    // 将原数组中的所有元素复制到新数组
    for (int i = 0; i < size; i++) {
        res[i] = nums[i];
    }
    // 初始化扩展后的空间
    for (int i = size; i < size + enlarge; i++) {
        res[i] = 0;
    }
    // 返回扩展后的新数组
    return res;
}

int main() {
    /* 初始化数组 */
    int arr[10] = {0}; // { 0, 0, 0, 0, 0 }
    int nums[6] = {1, 3, 2, 5, 4};
    int length = 5; // 初始化时数组中实际存储的元素个数

    int num = randomAccess(nums, length);
    printf("%d\n", num);

    // 插入元素
    insert(nums, length, 10, 1);
    traverse(nums, length);

    // 查找元素
    int index = find(nums, length, 2);
    printf("在 nums 中查找元素 2 ，得到索引 = %d\n", index);

    // 扩展数组
    int *newNums = extend(nums, length, 3);
    length += 3; // 更新数组长度
    traverse(newNums, length);

    // 释放旧数组内存
    free(newNums);

    return 0;
}

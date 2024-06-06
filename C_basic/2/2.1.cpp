//
// Created by Saika on 2024/1/2.
//
#include <stdio.h>

// 符号常量
#define PI 3+2

int main() {
    // i 就是一个整体变量
    int i = PI * 2;
    printf("i=%d\n", i);
    printf("i size=%llu\n", sizeof(i));

    float f = 3e-3;
    printf("f=%f\n", f);

    // 大写变小写
    char c = 'A';
    // 数值形式输出
    printf("%d\n", c);
    printf("%d\n", c + 32);
    // 字符形式输出
    printf("%c\n", c);
    printf("%c\n", c + 32);

    return 0;
}
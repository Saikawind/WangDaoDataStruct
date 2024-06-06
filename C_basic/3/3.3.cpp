//
// Created by Saika on 2024/3/23.
//
# include "stdio.h"

// 短路运算、赋值运算、求字节运算符 sizeof
int main() {
    int i = 0;
    i && printf("you can't see me !\n");
    int j = 1;
    j && printf("you can just see me !\n");
    int k = 1;
    k || printf("you can't see me also!");

    // 赋值运算
    int a = 1, b = 2;
    a += 3;
    printf("a=%d\n", a);

    // sizeof
    int c = 0;
    printf("i size is %d\n", sizeof(c));

    return 0;
}
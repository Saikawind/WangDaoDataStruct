//
// Created by Saika on 2024/3/23.
//
# include "stdio.h"
# include "stdlib.h"

int main() {
    int i = 0, sum = 1;
    scanf("%d", &i);
    while (i > 0) {
        sum *= i;
        i -= 1;
    }
    printf("%d", sum);

    return 0;
}
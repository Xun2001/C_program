#include <stdio.h>
#include <stdlib.h>

// 打印二维矩阵的函数
void printmatrix(int matrix[][100], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("请输入二维矩阵的维度N: ");
    scanf("%d", &N);
    // 使用动态分配内存的方式创建二维矩阵
    int (*matrix)[100] = (int (*)[100])malloc(N * sizeof(int[100]));

    if (matrix == NULL) {
        perror("内存分配失败");
        return 1;
    }
    // 为二维矩阵元素赋值（这里简单示例赋值为行列索引之和，可按需修改）
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = i + j;
        }
    }
    printmatrix(matrix, N);
    // 释放动态分配的内存
    free(matrix);
    return 0;
}
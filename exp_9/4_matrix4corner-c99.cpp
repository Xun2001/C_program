/*
P177 4.2.3 T5
requirements:

    void printmatrix(int matrix[][N]);  //矩阵元素的打印输出
    void min4corner(int * address,int n);  // 用排序把最小的四个元素放在题目要求的位置
    void swap(int *a, int *b);  //排序时需要调用交换的函数
*/

#include <stdio.h>
#include <malloc.h>

#define swap(a, b) \
    do             \
    {              \
        int t;     \
        t = a;     \
        a = b;     \
        b = t;     \
    } while (0)

int main(void)
{
    int n;
    printf("input n:\n");
    scanf("%d", &n);

    // // create-1
    typedef int(*MT)[n]; // n个行的指针
    MT matrix; 
    matrix = (MT)malloc(n * n * sizeof(int));

    // // create-2
    // int matt[n][n]={0};
    // int (*matrix)[n];
    // matrix = matt;

    printf("input matrix:\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &matrix[i][j]);

    printf("matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
            printf("%6d", matrix[i][j]);
        putchar('\n');
    }
    { // select sort 4 biggest numbers
        int i, j, k;
        int *mat = matrix[0];//将二维数组，转换为一维数组
        for (i = 0; i < 4; i++) //把最小的四个放在最前面
        {
            for (k = i, j = i + 1; j < n * n; j++) // 根据 j 逐列
                if (mat[j] < mat[k])
                    k = j;
            if (k != i)
                swap(mat[i], mat[k]);
        }
        if (n > 2)
        {
            swap(mat[3], mat[n * n - 1]);
            swap(mat[2], mat[n * (n - 1)]);
            swap(mat[1], mat[n - 1]);
        }
    }
    printf("\nnew matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
            printf("%6d", matrix[i][j]);
        putchar('\n');
    }

    return 0;
}

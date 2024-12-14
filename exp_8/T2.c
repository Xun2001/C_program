#include <stdio.h>
/*
4.1.3 2 用指针完成矩阵的转置
*/

void swap(int a[][3],int n);
int main()
{
    int a[3][3];

    printf("请输入矩阵元素:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    swap(a,3);
    printf("转置后:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }


    return 0;
}

void swap(int a[][3],int n)
{
    int i,j,temp;
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}
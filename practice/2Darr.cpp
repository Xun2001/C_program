#include <stdio.h>
#include <malloc.h>

int main(){

    // int a[2][2]={1,2,3,4};
    // int *b=*(a+1);
    // printf("%d\n",**(a+1));
    // printf("%d\n",*(a+1));
    // printf("%d\n",b);
    // printf("%d\n",b[0]);
    // printf("%d\n",b[1]);

    // // a+1就是第1行的首地址
    // printf("%d\n",*(*(a+1)+0));
    // printf("%d\n",*(*(a+1)+1));

    // int *c=*a;
    // printf("%d\n",c[2]);
    // printf("%d\n",*(c+2));

    int n;
    printf("input n:\n");
    scanf("%d", &n);
    // // create-1
    typedef int(*MT)[n]; // n个行的指针
    MT matrix; 
    matrix = (MT)malloc(n * n * sizeof(int));

    // // create-2
    // int mat[n][n]={0};
    // int (*matrix)[n];
    // matrix = mat;

    printf("input matrix:\n");

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &matrix[i][j]);

    printf("matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
            printf("%6d", matrix[i][j]);
        putchar('\n');
    }


    int *p;
    p = (int *)malloc(n *sizeof(int));
    printf("sizeof(int)%d",sizeof(int));
    printf("sizeof(p) %d\n",sizeof(*p));

    return 0;
}
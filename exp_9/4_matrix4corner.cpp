#include <stdio.h>
#include <stdlib.h>


void min4corner(int * address,int n);
void swap(int *a, int *b);
void print_matrix(int * address,int n);
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    // int *arr = (int*)malloc(n*sizeof(int));
    //数组指针 指向一个数组，这个数组的元素为n个行指针，所以类型为 int * [n]
    // int (*input_arr)[n] = (int(*)[n])malloc(sizeof(int[n][n]));
    int (*input_arr)[n] = (int(*)[n])malloc(n*n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",(*input_arr+n*i+j));
        }
    }


    printf("Matrix is: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d=",input_arr[i][j]);
            printf("%d ",*(*input_arr+n*i+j));
        }
        printf("\n");
    }

    min4corner(*input_arr,n);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min4corner(int *address,int n)
{
    int i,j,k;
    for (i = 0; i < 4; i++) //把最小的四个放在最前面
    {
        for (k = i, j = i + 1; j < n * n; j++) // 根据 j 逐列
            if (address[j] < address[k]) //找到最小的保存索引为 k
                k = j;
        if (k != i)
            swap(&address[i], &address[k]);
    }
    if (n > 2)
    {
        //换元素的时候，注意替换顺序
        swap(&address[3], &address[n * n - 1]);//右下角
        swap(&address[2], &address[n * (n - 1)]);//左下角
        swap(&address[1], &address[n - 1]);//右上角
    }
    printf("\nnew matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
            printf("%6d", address[i * n + j]);
        putchar('\n');
    }
}
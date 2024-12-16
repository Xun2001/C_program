/*
int *p[10]和
int (*p)[10]有什么区别？

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[2][3]={1,2,3,4,5,6};
    int *p1[2];//指针数组;p1是数组; 是一个包含了2个指针的数组，每个指针指向一个int类型的变量
    int (*p2)[3];//数组指针

    for(int i=0;i<2;i++)
    {
        p1[i]=arr[i];
    }
    printf("p1:\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            // printf("%d ",*(*(p1+i)+j));
            printf("%d ",*(p1[i]+j));
            printf("%d ",(*p1)[i][j]);
        }
        printf("\n");
    }

    p2=arr;
    printf("p2:\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            // printf("%d ",*(*p2+i*3+j));
            printf("%d ",*(p2[i]+j));
        }
        printf("\n");
    }
    return 0;
}
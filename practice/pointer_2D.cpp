/*
int *p[10]和
int (*p)[10]有什么区别？

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[2][3]={1,2,3,4,5,6};
    int *p1[2];//数组指针;p1是数组; 是一个包含了2个指针的数组，每个指针指向一个int类型的变量
    int *((*p2)[2])[3];//指针数组;p2是指针; 指向一个数组，数组中包含2个int *类型的指针
    /*
    printf("二维数组的数组名\'a\'为：%p\n",a);
    printf("二维数组的第一行元素的值\'a[0]\'为：%p\n",a[0]);
    printf("二维数组的第一个元素的地址\'a\'为：%p\n",&a[0][0]);

    printf("\'*a\'为：%p\n",*a);
    printf("\'*(a+1)\'为：%p\n",*(a+1));
    printf("\'a+1\'为：%p\n",a+1);
    printf("\'a[0]+1\'为：%p\n",a[0]+1);
    printf("\'a[0][0]的地址\'为：%p\n",&a[0][0]);
    printf("\'a[0][1]的地址\'为：%p\n",&a[0][1]);
    printf("\'a[1][0]的地址\'为：%p\n",&a[1][0]);
    */
    for(int i=0;i<2;i++)
    {
        p1[i]=a[i];
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",*(p1[i]+j));
        }
        printf("\n");
    }

    return 0;
}
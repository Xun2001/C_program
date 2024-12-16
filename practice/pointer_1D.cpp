/*
int *p[10]和
int (*p)[10]有什么区别？

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int *p1[10];//数组指针;p1是数组; 是一个包含了10个指针的数组，每个指针指向一个int类型的变量
    int (*p2)[10];//指针数组;p2是指针; 指向一个数组，数组中包含10个int类型的变量
    int *p3=a;

    //如果希望给p1赋值，就需要遍历，给数组中的每一个指针元素赋予一个地址
    for (int i = 0; i < 10; i++)
    {
        p1[i] = &a[i];
    }

    printf("p1:\n");
    //取出p1中的元素，需要遍历p1，找到每一个地址元素指向的元素
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *p1[i]);
    }


    //如果希望给p2赋值，就需要找到一个数组，然后让p2指向这个数组的首地址
    //所以 p2是 地址(数组名)的地址
    p2 = &a;// 我们都知道a是数组名，也是数组的首地址，而对一个地址取地址，即得到地址的地址
    printf("\np2_1:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", (*p2)[i]);//p2指向a，所以*p就是a
    }
    
    printf("\np2_2:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *((*p2)+i));
    }

    printf("\na的地址:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%p ", &a[i]);
    }
    printf("\np2指向的数组后续地址:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%p ", (*p2)+i);
    }
    printf("\n");
    printf("\np2的地址:%p p2中的元素:%p", &p2,p2);

}
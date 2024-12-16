#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void type_self(int n);

int main()
{
    char a[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};
    char (*q)[4]=a;
    char b[2]={0};
    printf("%p\n",a[0]);
    printf("%d\n",q[2][0]);
    printf("%p\n",q+2);

    // type_self(q[2]);
    
    return 0;
}


void type_self(int n)
{

    printf("%d\n",n);
}
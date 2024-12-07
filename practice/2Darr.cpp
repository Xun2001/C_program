#include <stdio.h>
int main(){

    int a[2][2]={1,2,3,4};
    int *b=*(a+1);
    // printf("%d\n",**(a+1));
    // printf("%d\n",*(a+1));
    // printf("%d\n",b);
    // printf("%d\n",b[0]);
    // printf("%d\n",b[1]);

    // // a+1就是第1行的首地址
    // printf("%d\n",*(*(a+1)+0));
    // printf("%d\n",*(*(a+1)+1));

    int *c=*a;
    printf("%d\n",c[2]);
    printf("%d\n",*(c+2));

    return 0;
}
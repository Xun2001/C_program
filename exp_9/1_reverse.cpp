/*
4.2.3 T1 reverse array
要求使用 malloc 函数

*/

#include <stdio.h>
#include <malloc.h>

void reverse_array(int *, int);
int main(void)
{
    int *a;
    int i, n;

    printf("input n:\n");
    scanf("%d", &n);
    printf("input %d numbers:\n", n);
    a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    reverse_array(a, n - 1);
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
void reverse_array(int *a, int n)
{
    int i;
    for (i = 0; i < n/2; i++)
    {
        int temp;
        temp = a[i];
        a[i] = a[n-i];
        a[n] = temp;
    }
}
/*
P177 4.2.3 T2
find max subarray sum
*/

#include <stdio.h>
#include <malloc.h>
int findmax(int a[], int n);

int main(void)
{
    int i, n, *a;
    do
    {
        printf("input n (n>3):\n");
        scanf("%d", &n);
    } while (n <= 3);
    printf("input %d numbers:\n", n);
    a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("max sub_array start from %d\n", findmax(a, n - 1));
    return 0;
}

int findmax(int a[], int n)
{
    int i, max, start = 0;
    max = a[0] + a[1] + a[2];
    for (i = 1; i <= n - 2; i++)
    {
        int s = a[i] + a[i + 1] + a[i + 2];
        if (s > max)
        {
            max = s;
            start = i;
        }
    }
    return start;
}
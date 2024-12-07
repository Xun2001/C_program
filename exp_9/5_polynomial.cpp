/*
1、 int fact(int n){} { //返回 n 的阶乘，不考虑整数溢出的情况 …} 
2、 int * coef(int n) { 
    //求 n 次二项式展开式的各项系数;
    //要求在计算二项式系数时， 调用 fact 函数计算阶乘;
    //当参数 n<0 时，返回 NULL;当 n>=0 时，返回由 malloc 函数生成的存储空间的起始地址，该空间存放 n 次二项式系数序列。
         …} 

3. 不要求求和，只求系数
*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

int fact(int n);
int * coef(int n);
int * mult(int, int, int);
int add(int *,int *, int);
int main()
{
    int n,n1,n2;
    int result=0;

    printf("Enter one number as N: ");
    scanf("%d", &n);
    int *p_coef = coef(n);

    printf("\nEnter two numbers to calculate the coefficients of their %d-th binomial expansion: ",n);
    scanf("%d", &n1);
    scanf("%d", &n2);
    int *p_mult= mult(n1, n2, n);
    result = add(p_coef,p_mult,n);

    printf("\nFactorial of %d and %d is %d\n", n1,n2, result);

    return 0;
}

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int * coef(int n){
    int *p;
    p = (int *)malloc(n * sizeof(int));
    if (n < 0)
        return NULL;

    for(int k = 0; k <= n; k++)
    {
        p[k] = fact(n) / (fact(k) * fact(n - k));
    }


    printf("The coefficients of %d-th binomial expansion are:\n", n);
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", p[i]);
    }

    return p;
}

int * mult(int n1, int n2, int n)
{
    int *p;
    p = (int *)malloc(n * sizeof(int));
    int a,b;

    for (int k = 0; k <= n; k++)
    {
        a=pow(n1, n-k);
        b=pow(n2, k);
        p[k]=a*b;
    }

    printf("\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", p[i]);
    }

    return p;
}


int add(int *p1,int *p2, int n)
{
    int results=0;
    for (int i = 0; i <= n; i++)
    {
        results += p1[i] * p2[i];
    }

    return results;
}
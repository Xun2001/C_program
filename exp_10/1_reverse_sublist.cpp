#include <stdio.h>
#include <malloc.h>
#define N 20

typedef struct node
{
    int n;
    struct node *next;
} NODE;

NODE *sublistrev(NODE *list, int m, int n)
{
    NODE *q = NULL, *p = list;
    NODE *sublistr = NULL;
    NODE *subtail = NULL;
    n = n - m + 1;
    while (m > 1 && p != NULL)
    {
        q = p;
        p = p->next;
        m--;
    }
    subtail = p;
    while (n > 0 && p != NULL)
    {
        NODE *pp = p->next;
        p->next = sublistr;
        sublistr = p;
        p = pp;
        n--;
    }
    if (q)
        q->next = sublistr;
    else
        list = sublistr;
    subtail->next = p;
    return list;
}

int main(int argc, char const *argv[])
{
    NODE *list = NULL, *p;
    int i, m, n;
    for (i = N; i > 0; --i)
    {
        p = (NODE*)malloc(sizeof(NODE));
        p->n = i;
        p->next = list;
        list = p;
    }
    p = list;
    while (p)
    {
        printf("%d-", p->n);
        p = p->next;
    }
    do
    {
        printf("\ninput m n : (1..20)");
        scanf("%d%d", &m, &n);
    } while (n < m || m < 1 || n > 20);

    list=sublistrev(list, m, n);
    p = list;

    while (p)
    {
        printf("%d-", p->n);
        p = p->next;
    }
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <malloc.h>
#define DATA_FILE_NAME "./C_homework/exp_10/txt/students.txt"

typedef struct student
{
    int stunum;
    char name[20];
    float examscore;
    float labscore;
    float totalmark;
    struct student *next;
} ST, *LinkList;

LinkList createList(void);
LinkList insertSort(LinkList head, LinkList pnew);
void statistics(LinkList head);
void print(LinkList head);

int main(void)
{
    LinkList head = NULL;
    head = createList();
    print(head);
    statistics(head);
    // print(head);
    return 0;
}
void statistics(LinkList p)
{
    int s[5] = {0};
    float num=0;
    char *smsg[5] = {"[90-100]", "[85-90)", "[75-85)", "[60-75)", "[0-60)"};
    while (p)
    {
        num+=1;
        if (p->totalmark <= 100 && p->totalmark >= 90)
            s[0]++;
        else if (p->totalmark < 90 && p->totalmark >= 85)
            s[1]++;
        else if (p->totalmark < 85 && p->totalmark >= 75)
            s[2]++;
        else if (p->totalmark < 75 && p->totalmark >= 60)
            s[3]++;
        else
            s[4]++;
        p = p->next;
    }
    printf("统计结果:\n"); 
    for (int i = 0; i < 5; i++)
    {
        printf("%s :\t%d人\t%.2f%%\n", smsg[i], s[i],100*s[i]/num);
    }
}

LinkList createList(void)
{
    FILE *fp;
    ST stu;
    LinkList pnew, head = NULL;
    stu.next = NULL;
    fp = fopen(DATA_FILE_NAME, "r");
    if (!fp)
    {
        perror("fopen " DATA_FILE_NAME " failed");
        // exit(0);
    }
    while (EOF != fscanf(fp, "%d%s%f%f\n", &stu.stunum, stu.name, &stu.examscore, &stu.labscore))
    {
        stu.totalmark = stu.labscore * 0.4 + stu.examscore * 0.6;
        pnew = (LinkList)malloc(sizeof(ST));
        *pnew = stu;
        pnew->next = NULL;
        head = insertSort(head, pnew);
    }
    return head;
}
LinkList insertSort(LinkList head, LinkList pnew)
{
    LinkList p, prep;
    p = prep = head;
    if (NULL == head)
        return pnew;

    while (p && p->totalmark > pnew->totalmark)
    {
        prep = p;
        p = p->next;
    }
    if (p == head)
    {
        pnew->next = head;
        head = pnew;
    }
    else
    {
        pnew->next = p;
        prep->next = pnew;
    }
    return head;
}

void print(LinkList h)
{
    int i = 1;
    printf("\nThe list:\n");
    while (h)
    {
        printf("%d:\t%d %s\tfinal:%.1f\n", i++, h->stunum, h->name, h->totalmark);
        h = h->next;
    }
}
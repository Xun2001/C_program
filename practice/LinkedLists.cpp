#include<stdio.h>
#include<stdlib.h>

struct node{
    int num;
    struct node *next;
};

struct node *CreateListF(void){
    struct node *head, *p;
    int num;

    head = NULL;
    printf("Input -1 to quit.\n");
    printf("Input a number:");
    scanf("%d", &num);
    while(num != -1){
        p = (struct node *)malloc(sizeof(struct node));
        p->num = num;
        p->next = head;
        head = p;
        printf("Input a number:");
        scanf("%d", &num);

    }
    return p;
}


int main(){

    printf("hello world\n");

    struct node *linkedlist;

    linkedlist = CreateListF();
    printf("Finish");
    for(int i = 0;linkedlist !=NULL;linkedlist = linkedlist->next)
    {   
        i++;
        printf("链表的第%d个元素中Num为: ",i);
        printf("%d\n", linkedlist->num);
    }

    return 0;
}
//求两个多项式的和与乘积 (书上练习只要求求和)
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct lnode
{
	float coef;
	int expn;
	struct lnode *next;
} Lnode, *LinkList;

LinkList CreatePolyn(void);
LinkList AddPolyn(LinkList, LinkList);
LinkList MltpPolyn(LinkList, LinkList);
LinkList InsertPolynNode(LinkList, float, int);
void PrintPolyn(LinkList);

int main(void)
{

	LinkList L1, L2, L3, L4;
	L1 = L2 = L3 = L4 = NULL;
	L1 = CreatePolyn();
	L2 = CreatePolyn();
	L3 = AddPolyn(L1, L2);
	L4 = MltpPolyn(L1, L2);
	printf("L1:\n");
	PrintPolyn(L1);
	printf("L2:\n");
	PrintPolyn(L2);
	printf("\nL1 + L2:\n");
	PrintPolyn(L3);
	printf("\nL1 * L2:\n");
	PrintPolyn(L4);
	return 0;
}

LinkList CreatePolyn(void)
{
	int n = 0, i;
	int exp;
	float coef;
	LinkList p = NULL;

	do
	{
		printf("输入多项式的项数n(n>0):\n");
		fscanf(stdin, "%d", &n);
	} while (n <= 0);
	for (i = 1; i <= n; ++i)
	{
		printf("输入第%d项系数和指数:", i);
		fscanf(stdin, "%f", &coef);
		fscanf(stdin, "%d", &exp);
		p = InsertPolynNode(p, coef, exp);
		printf("\n");
	}
	return p;
}

LinkList AddPolyn(LinkList L1, LinkList L2)
{
	LinkList Lnew = NULL, p;
	p = L1;
	while (p)
	{
		Lnew = InsertPolynNode(Lnew, p->coef, p->expn);
		p = p->next;
	}
	p = L2;
	while (p)
	{
		Lnew = InsertPolynNode(Lnew, p->coef, p->expn);
		p = p->next;
	}
	return Lnew;
}

LinkList MltpPolyn(LinkList L1, LinkList L2)
{
	LinkList Lnew = NULL, p, q;
	p = L1;
	while (p)
	{
		q = L2;
		while (q)
		{
			Lnew = InsertPolynNode(Lnew, (p->coef) * (q->coef), (p->expn + q->expn));
			q = q->next;
		}
		p = p->next;
	}
	return Lnew;
}

LinkList InsertPolynNode(LinkList L, float c, int e)
{
	LinkList p = L;
	LinkList q = L;
	LinkList pnewnode = NULL;

	pnewnode = (LinkList)malloc(sizeof(Lnode));
	//assert(pnewnode);
	pnewnode->coef = c;
	pnewnode->expn = e;
	pnewnode->next = NULL;

	if (L == NULL)
		return pnewnode;

	while (p != NULL && p->expn > e)
	{
		q = p;
		p = p->next;
	}

	if (p != NULL && p->expn == e) //合并同次项：
	{
		if (p->coef + c == 0.0) // delete node with coef==0
		{
			if (p == L)
				L = p->next;
			else
				q->next = p->next;
			free(p);
			free(pnewnode); // free node:
		}
		else //
		{
			p->coef += c; // keep the node with new coef
			free(pnewnode);
		}
	}
	else if (p == NULL)
	{ //表尾：
		q->next = pnewnode;
	}
	else // p->expn < e: 插入在p之前
	{
		pnewnode->next = p;
		if (p == L) // insert pnewnode as list head:
			L = pnewnode;
		else
			q->next = pnewnode;
	}
	return L;
}

void PrintPolyn(LinkList L)
{
	LinkList p = L;
	printf("P(x) = ");
	while (p)
	{
		if (p->expn == 0)
			printf("%+.1f  ", p->coef);
		else
			printf("%+.1fx^%d  ", p->coef, p->expn);
		p = p->next;
	}
	printf("\n");
}
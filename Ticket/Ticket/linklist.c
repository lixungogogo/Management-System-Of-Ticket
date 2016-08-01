#define _CRT_SECURE_NO_WARNINGS 1

#include  <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "linklist.h"
#include <malloc.h>
#include <string.h>


typedef Station LNode, *PNode, *LinkList, Station_List;

int InitList(Station* *h)
{

	if (!h)
	{
		printf("初始化链表错误\n");
		return 0;
	}
	(*h)->next = NULL;
	return 1;
}


int ListInsert_station(Station* h, int pos, char *station_id, Time c, Time a, int time)
{
	Station *p = h, *q, *o = NULL;
	int i = 0;
	printf("H");
	while (p && i < pos - 1)
	{
		o = p;
		p = p->next;
		i++;
		printf("->");
	}
	if (!o || i > pos - 1)
	{
		printf("插入位置不合法！\n"); return 0;
	}

	q = (Station*)malloc(sizeof(Station));
	q->Station_ID = (char *)malloc(10 * sizeof(char));

	if (!q)
	{
		printf("不能生成新的结点\n"); return 0;
	}
	printf("%s", station_id);
	strcpy_s(q->Station_ID, 6, station_id);
	q->time_C = c;
	q->time_A = a;
	q->time = time;
	q->next = o->next;
	o->next = q;
	q->next = NULL;
	printf("\n");
	return 0;
}

int InitList_order(Order* *h)
{
	*h = (Order *)malloc(sizeof(Order));
	if (!h)
	{
		printf("初始化链表错误\n");
		return 0;
	}
	(*h)->next = NULL;
	return 1;
}

int ListInsert_order(Order* h, int pos, int order_id)
{
	Order* p = h, *q, *o = NULL;
	while (p)
	{
		o = p->next;
		p = p->next;
	}

	q = (Order*)malloc(sizeof(Order));

	if (!q)
	{
		printf("不能生成新的结点\n"); return 0;
	}

	q->Order_ID = order_id;
	q->next = o->next;
	o->next = q;
	q->next = NULL;
}

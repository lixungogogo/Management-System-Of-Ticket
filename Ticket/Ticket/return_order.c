#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "linklist.h"
#include <malloc.h>
#include <string.h>
/*****************退票*****************/

Order *return_order(Order *head, char *name)
{
	int i = 0;
	Order *p, *p1;
	p = (Order *)malloc(sizeof(Order));
	p1 = (Order *)malloc(sizeof(Order));
	p1 = head;
	p->next = head->next;
	p = head->next;
	p->next = NULL;
	while (p != NULL)
	{
		if (!strcmp(p->client.Name, name))
		{
			printf("\n您订单的情况如下：\n");
			printf("订单编号：%d\t", p->Order_ID); printf("\n");
			printf("订票数量：%d\t", p->ticket_num); printf("\n");
			for (int j = 0; j < p->ticket_num; j++)
			{
				if (p->ticket[j].Ticket_State == 1){
					printf("第%d张票信息为：\n", j + 1);
					printf("车次类型为：%c\t车次编号为：%d\n", p->ticket[j].Train_type, p->ticket[j].Train_id);
					printf("车票号为：%d", p->ticket[j].tic_num);
					printf("车厢号：%d\t座位号：%d\t座位类型：%c\n折后价格：%4.2f\t折扣：%f",
						p->ticket[j].Cap_ID, p->ticket[j].seat.Seat_ID, p->ticket[j].seat.Seattype_ID,
						p->ticket[j].PRICE, p->ticket[j].Discout); printf("\n");
					printf("出发站为：%s", p->ticket[j].Station_C);
					printf("\n");
					printf("出发时间为：%d-%d-%d-%d:%d",
						p->ticket[j].time_c.Time_Y, p->ticket[j].time_c.Time_MON, p->ticket[j].time_c.Time_D,
						p->ticket[j].time_c.Time_H, p->ticket[j].time_c.Time_MIN);
					printf("\n");
					printf("到达站为：%s", p->ticket[j].Station_A);
					printf("\n");
					printf("到达时间为：%d-%d-%d-%d：%d",
						p->ticket[j].time_a.Time_Y, p->ticket[j].time_a.Time_MON, p->ticket[j].time_a.Time_D,
						p->ticket[j].time_a.Time_H, p->ticket[j].time_a.Time_MIN);
					printf("\n\n\n");
				}
			}

			p = p->next;
		}
		else {
			p1 = p;
			p = p->next;
		}
	}
	char k;
	printf("是否确定退单？");
	getchar();
	scanf_s("%c", &k);
	if (k == 'Y')
	{
		if (p == head)
			head = head->next;
		else p1->next = NULL;
		free(p);
		printf("退单成功！");
	}
	else{
		printf("1.返回主菜单\n2.返回客户端\n0.退出\n");
		int d;
		scanf_s("%d", &d);
		switch (d)
		{
		case 1: mena(); break;
		case 2: Server(); break;
		case 0:
			printf("* * * * * * * * * * * * * * * * * * *  * *\n");
			printf("*                                       *\n");
			printf("*           Thanks for using            *\n");
			printf("*                                       *\n");
			printf("* * * * * * * * * * * * * * * * * * *  * *\n");
			exit(0); break;
		}
	}
	return head;
}

Order *return_ticket(Order *head, char *name)
{
	int i = 0;
	Order *p, *p1;
	p = (Order *)malloc(sizeof(Order));
	p->next = head->next;
	p = head->next;
	p->next = NULL;
	while (p != NULL)
	{
		if (!strcmp(p->client.Name, name))
		{
			printf("\n您订单的情况如下：\n");
			printf("订单编号：%d\t", p->Order_ID); printf("\n");
			printf("订票数量：%d\t", p->ticket_num); printf("\n");
			for (int j = 0; j < p->ticket_num; j++)
			{
				printf("第%d张票信息为：\n", j + 1);
				printf("车次类型为：%c\t车次编号为：%d\n", p->ticket[j].Train_type, p->ticket[j].Train_id);
				printf("车票号为：%d", p->ticket[j].tic_num);
				printf("车厢号：%d\t座位号：%d\t座位类型：%c\n折后价格：%4.2f\t折扣：%f",
					p->ticket[j].Cap_ID, p->ticket[j].seat.Seat_ID, p->ticket[j].seat.Seattype_ID,
					p->ticket[j].PRICE, p->ticket[j].Discout); printf("\n");
				printf("出发站为：%s", p->ticket[j].Station_C);
				printf("\n");
				printf("出发时间为：%d-%d-%d-%d:%d",
					p->ticket[j].time_c.Time_Y, p->ticket[j].time_c.Time_MON, p->ticket[j].time_c.Time_D,
					p->ticket[j].time_c.Time_H, p->ticket[j].time_c.Time_MIN);
				printf("\n");
				printf("到达站为：%s", p->ticket[j].Station_A);
				printf("\n");
				printf("到达时间为：%d-%d-%d-%d：%d",
					p->ticket[j].time_a.Time_Y, p->ticket[j].time_a.Time_MON, p->ticket[j].time_a.Time_D,
					p->ticket[j].time_a.Time_H, p->ticket[j].time_a.Time_MIN);
				printf("\n\n\n");
			}
			p = p->next;
		}
		else p = p->next;
	}
	int  k;
	printf("请选择要退的车票号：\t");
	getchar();
	scanf_s("%d", &k);
	p1 = (Order *)malloc(sizeof(Order));
	p1->next = head->next;
	p1 = head->next;
	p1->next = NULL;
	char t;
	for (int v = 0; v < p1->ticket_num; v++)
	{
		if (p1->ticket[v].tic_num == k)
		{
			printf("第%d张票信息为：\n", v + 1);
			printf("车次类型为：%c\t车次编号为：%d\n", p1->ticket[v].Train_type, p1->ticket[v].Train_id);
			printf("车票号为：%d", p1->ticket[i].tic_num);
			printf("车厢号：%d\t座位号：%d\t座位类型：%c\n折后价格：%4.2f\t折扣：%f",
				p1->ticket[v].Cap_ID, p1->ticket[v].seat.Seat_ID, p1->ticket[v].seat.Seattype_ID,
				p1->ticket[v].PRICE, p1->ticket[v].Discout); printf("\n");
			printf("出发站为：%s", p1->ticket[v].Station_C);
			printf("\n");
			printf("出发时间为：%d-%d-%d-%d:%d",
				p1->ticket[v].time_c.Time_Y, p1->ticket[v].time_c.Time_MON, p1->ticket[v].time_c.Time_D,
				p1->ticket[v].time_c.Time_H, p1->ticket[v].time_c.Time_MIN);
			printf("\n");
			printf("到达站为：%s", p1->ticket[v].Station_A);
			printf("\n");
			printf("到达时间为：%d-%d-%d-%d：%d",
				p1->ticket[v].time_a.Time_Y, p1->ticket[v].time_a.Time_MON, p1->ticket[v].time_a.Time_D,
				p1->ticket[v].time_a.Time_H, p1->ticket[v].time_a.Time_MIN);
			printf("\n\n\n");
			printf("确定请输入Y！");
			getchar();
			scanf_s("%c", &t);
			if (t == 'Y')
				p1->ticket[v].Ticket_State = 0;
			else  {
				printf("1.返回主菜单\n2.返回客户端\n0.退出\n");
				int d;
				scanf_s("%d", &d);
				switch (d)
				{
				case 1: mena(); break;
				case 2: Server(); break;
				case 0:
					printf("* * * * * * * * * * * * * * * * * * *  * *\n");
					printf("*                                       *\n");
					printf("*           Thanks for using            *\n");
					printf("*                                       *\n");
					printf("* * * * * * * * * * * * * * * * * * *  * *\n");
					exit(0); break;
				}
			}
		}
	}
	printf("退票成功！");
	Order *e;
	e = (Order *)malloc(sizeof(Order));
	e->next = head->next;
	e = head->next;
	e->next = NULL;
	while (e != NULL)
	{
		if (!strcmp(e->client.Name, name))
		{
			printf("\n您订单的情况如下：\n"); int m = 0;
			printf("订单编号：%d\t", e->Order_ID); printf("\n");
			for (int u = 0; u < e->ticket_num; u++)
			if (e->ticket[u].Ticket_State == 1)
				m++;
			printf("订票数量：%d\t", m); printf("\n");
			for (int j = 0, g = 0; j < e->ticket_num; j++)
			{
				if (e->ticket[j].Ticket_State == 1){
					g++;
					printf("第%d张票信息为：\n", g);
					printf("车次类型为：%c\t车次编号为：%d\n", e->ticket[j].Train_type, e->ticket[j].Train_id);
					printf("车票号为：%d", e->ticket[j].tic_num);
					printf("车厢号：%d\t座位号：%d\t座位类型：%c\n折后价格：%4.2f\t折扣：%f",
						e->ticket[j].Cap_ID, e->ticket[j].seat.Seat_ID, e->ticket[j].seat.Seattype_ID,
						e->ticket[j].PRICE, e->ticket[j].Discout); printf("\n");
					printf("出发站为：%s", e->ticket[j].Station_C);
					printf("\n");
					printf("出发时间为：%d-%d-%d-%d:%d",
						e->ticket[j].time_c.Time_Y, e->ticket[j].time_c.Time_MON, e->ticket[j].time_c.Time_D,
						e->ticket[j].time_c.Time_H, e->ticket[j].time_c.Time_MIN);
					printf("\n");
					printf("到达站为：%s", e->ticket[j].Station_A);
					printf("\n");
					printf("到达时间为：%d-%d-%d-%d：%d",
						e->ticket[j].time_a.Time_Y, e->ticket[j].time_a.Time_MON, e->ticket[j].time_a.Time_D,
						e->ticket[j].time_a.Time_H, e->ticket[j].time_a.Time_MIN);
					printf("\n\n\n");
				}
			}
			e = e->next;
		}
		else e = e->next;
	}

	printf("1.返回主菜单\n2.返回客户端\n0.退出\n");
	int d;
	scanf_s("%d", &d);
	switch (d)
	{
	case 1: mena(); break;
	case 2: Server(); break;
	case 0:
		printf("* * * * * * * * * * * * * * * * * * *  * *\n");
		printf("*                                       *\n");
		printf("*           Thanks for using            *\n");
		printf("*                                       *\n");
		printf("* * * * * * * * * * * * * * * * * * *  * *\n");
		exit(0); break;
	}
	return head;
}

int RETURN(Order *h)
{
	char name[10]; int j = 0;
	printf("请输入您的姓名：\t");
	scanf_s("%s", &name, 10);
	printf("您的订单编号有：");
	Order * Ord;
	Ord = (Order*)malloc(sizeof(Order));
	Ord->next = h->next;
	Ord = h->next;
	while (Ord != NULL)
	{
		if (!strcmp(Ord->client.Name, name))
		{
			printf("%d\t", Ord->Order_ID);
			j++;
		}
		Ord = Ord->next;
	}
	if (j == 0)
		printf("NULL\n");
	printf("\n1.退票\n2.退单\n0.退出\t");
	int s;
	scanf_s("%d", &s);
	switch (s)
	{
	case 1: h = return_ticket(h, name);; break;
	case 2:  h = return_order(h, name); break;
	case 0:
		printf("* * * * * * * * * * * * * * * * * * *  * *\n");
		printf("*                                       *\n");
		printf("*           Thanks for using            *\n");
		printf("*                                       *\n");
		printf("* * * * * * * * * * * * * * * * * * *  * *\n");
		exit(0); break;
	}

	printf("退票后您的订单情况为：");
	int k = 0;
	while (h != NULL)
	{
		if (!strcmp(h->client.Name, name))
		{
			printf("\n您订单的情况如下：\n");
			printf("订单编号：%d\t", h->Order_ID); printf("\n");
			printf("订票数量：%d\t", h->ticket_num); printf("\n");
			for (int j = 0; j < h->ticket_num; j++)
			{
				if (h->ticket[j].Ticket_State == 1)
				{
					printf("第%d张票信息为：\n", j + 1);
					printf("车次类型为：%s\t车次编号为：%d\n", h->ticket[j].Train_type, h->ticket[j].Train_id);
					printf("车票号为：%d", h->ticket[j].tic_num);
					printf("车厢号：%d\t座位号：%d\t座位类型：%c\n折后价格：%4.2f\t折扣：%f",
						h->ticket[j].Cap_ID, h->ticket[j].seat.Seat_ID, h->ticket[j].seat.Seattype_ID,
						h->ticket[j].PRICE, h->ticket[j].Discout); printf("\n");
					printf("出发站为：%s", h->ticket[j].Station_C);
					printf("\n");
					printf("出发时间为：%d-%d-%d-%d:%d",
						h->ticket[j].time_c.Time_Y, h->ticket[j].time_c.Time_MON, h->ticket[j].time_c.Time_D,
						h->ticket[j].time_c.Time_H, h->ticket[j].time_c.Time_MIN);
					printf("\n");
					printf("到达站为：%s", h->ticket[j].Station_A);
					printf("\n");
					printf("到达时间为：%d-%d-%d-%d：%d",
						h->ticket[j].time_a.Time_Y, h->ticket[j].time_a.Time_MON, h->ticket[j].time_a.Time_D,
						h->ticket[j].time_a.Time_H, h->ticket[j].time_a.Time_MIN);
					printf("\n\n\n");
				}
			}
			k++;
		}
		h = h->next;
	}
	if (k == 0)
		printf("NULL\n");
	printf("1.返回主菜单\n2.返回客户端\n0.退出\n");
	int d;
	scanf_s("%d", &d);
	switch (d)
	{
	case 1: mena(); break;
	case 2: Server(); break;
	case 0:
		printf("* * * * * * * * * * * * * * * * * * *  * *\n");
		printf("*                                       *\n");
		printf("*           Thanks for using            *\n");
		printf("*                                       *\n");
		printf("* * * * * * * * * * * * * * * * * * *  * *\n");
		exit(0); break;
	default: printf("The number is not in 0-2!\n"); getchar(); break;
	}
	return 0;
}


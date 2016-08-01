#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "linklist.h"
#include <malloc.h>
#include <string.h>
/***************查询*******************/

int SelectTrain(Train train, int NUM, int station_id, char *idc, char *ida, int state)
{
	int j = 0, i = 1;

	for (int k = 0; k <= train.ticket.Tickets_Num; k++)
	{
		if (train.ticket.tickets[k].Ticket_State == 0)
		{
			if (state == 1)
			{
				if (!strcmp(train.ticket.tickets[k].Station_C, idc) && !strcmp(train.ticket.tickets[k].Station_A, ida))
				{
					printf("\n剩余车票号：");
					printf("%d\t\t", k + 1);
					printf("座位类型：%c\t", train.ticket.tickets[k].seat.Seattype_ID);
					printf("座位号:\t");
					printf("%d\t", train.ticket.tickets[k].seat.Seat_ID);
					printf("\n");
					printf("出发站：%s\n", train.ticket.tickets[k].Station_C);
					Station *q;
					q = train.station;
					while (q)
					{
						q = q->next;
						if (!strcmp(q->Station_ID, train.ticket.tickets[k].Station_C))
						{
							printf("到达时间：%d-%d-%d-%d:%d\n",
								q->time_C.Time_Y, q->time_C.Time_MON, q->time_C.Time_D, q->time_C.Time_H, q->time_C.Time_MIN);

							printf("出发时间：%d-%d-%d-%d:%d\n"
								, q->time_A.Time_Y, q->time_A.Time_MON, q->time_A.Time_D, q->time_A.Time_H, q->time_A.Time_MIN);
							break;
						}
					}
					printf("到达站：%s\n", train.ticket.tickets[k].Station_A);
					Station *p;
					p = train.station;
					while (p)
					{
						p = p->next;
						if (!strcmp(p->Station_ID, train.ticket.tickets[k].Station_A))
						{
							printf("到达时间：%d-%d-%d-%d:%d\n",
								p->time_C.Time_Y, p->time_C.Time_MON, p->time_C.Time_D, p->time_C.Time_H, p->time_C.Time_MIN);

							printf("出发时间：%d-%d-%d-%d:%d\n"
								, p->time_A.Time_Y, p->time_A.Time_MON, p->time_A.Time_D, p->time_A.Time_H, p->time_A.Time_MIN);

							break;
						}
					}
					j++;
				}
			}
			else {
				printf("剩余车票号：");
				printf("%d\t", k + 1);
				printf("座位类型：%c\t", train.ticket.tickets[k].seat.Seattype_ID);
				printf("座位号：:\t");
				printf("%d\t", train.ticket.tickets[k].seat.Seat_ID);
				printf("\n");
				printf("出发站：%s\n", train.ticket.tickets[k].Station_C);
				Station *q;
				q = train.station;
				while (q)
				{
					q = q->next;
					if (!strcmp(q->Station_ID, train.ticket.tickets[k].Station_C))
					{
						printf("到达时间：%d-%d-%d-%d:%d\n",
							q->time_C.Time_Y, q->time_C.Time_MON, q->time_C.Time_D, q->time_C.Time_H, q->time_C.Time_MIN);
						printf("出发时间：%d-%d-%d-%d-:%d\n"
							, q->time_A.Time_Y, q->time_A.Time_MON, q->time_A.Time_D, q->time_A.Time_H, q->time_A.Time_MIN);
						break;
					}
				}
				printf("到达站：%s\n", train.ticket.tickets[k].Station_A);
				Station *p;
				p = train.station;
				while (p)
				{
					p = p->next;
					if (!strcmp(p->Station_ID, train.ticket.tickets[k].Station_A))
					{
						printf("到达时间：%d-%d-%d-%d:%d\n",
							p->time_C.Time_Y, p->time_C.Time_MON, p->time_C.Time_D, p->time_C.Time_H, p->time_C.Time_MIN);
						printf("出发时间：%d-%d-%d-%d-:%d\n"
							, p->time_A.Time_Y, p->time_A.Time_MON, p->time_A.Time_D, p->time_A.Time_H, p->time_A.Time_MIN);
						break;
					}
				}
				j++;
			}
		}
	}
	if (j == 0)
	{

		printf("该车次没有剩余车票，请选择其他可供选择车次：\n");
		return 1;
	}
	else{

		printf("请选择一张余票号：\n");
		int a, b;
		scanf_s("%d", &b);
		a = b - 1;

		printf("详细信息：\n");

		printf("车厢号：%d\n", train.ticket.tickets[a].Cap_ID);
		printf("座位类型：%c\n", train.ticket.tickets[a].seat.Seattype_ID);
		printf("座位号：%d\n", train.ticket.tickets[a].seat.Seat_ID);
		printf("经过一站价格：%d\n", train.ticket.tickets[a].Price);
		printf("折扣：%f\n", train.ticket.tickets[a].Discout);
		printf("出发站：%s\n", train.ticket.tickets[a].Station_C);
		Station *q;
		q = train.station;
		while (q)
		{
			q = q->next;
			if (!strcmp(q->Station_ID, train.ticket.tickets[a].Station_C))
			{
				printf("到达时间：%d-%d-%d-%d:%d\n",
					q->time_C.Time_Y, q->time_C.Time_MON, q->time_C.Time_D, q->time_C.Time_H, q->time_C.Time_MIN);
				printf("出发时间：%d-%d-%d-%d:%d\n"
					, q->time_A.Time_Y, q->time_A.Time_MON, q->time_A.Time_D, q->time_A.Time_H, q->time_A.Time_MIN);
				break;
			}
		}
		printf("到达站：%s\n", train.ticket.tickets[a].Station_A);
		Station *p;
		p = train.station;
		while (p)
		{
			p = p->next;
			if (!strcmp(p->Station_ID, train.ticket.tickets[a].Station_A))
			{
				printf("到达时间：%d-%d-%d-%d:%d\n",
					p->time_C.Time_Y, p->time_C.Time_MON, p->time_C.Time_D, p->time_C.Time_H, p->time_C.Time_MIN);
				printf("出发时间：%d-%d-%d-%d:%d\n"
					, p->time_A.Time_Y, p->time_A.Time_MON, p->time_A.Time_D, p->time_A.Time_H, p->time_A.Time_MIN);
				break;
			}
		}
		if (NUM != 0)
		{
			int price = (train.ticket.tickets[a].Price)*(NUM);
			printf("折扣前价格：%d\n", price);
			double PRICE = (price)* (train.ticket.tickets[a].Discout);
			printf("总价格：%4.2f\n", PRICE);
		}
	}
	//getchar();
	printf("1.主菜单\n2.客户端\n0.退出\n");
	int y;
	scanf_s("%d", &y);
	switch (y)
	{
	case 1:mena(); break;
	case 2:Server(); break;
	case 0:
		printf("* * * * * * * * * * * * * * * * * * *  * *\n");
		printf("*                                       *\n");
		printf("*           Thanks for using            *\n");
		printf("*                                       *\n");
		printf("* * * * * * * * * * * * * * * * * * *  * *\n");
		exit(0); break;
	}
	return 0;
}

int SelectStation(Train *train)
{
	char station_idC[10], station_idA[10]; int NUM[10] = { 0 };
	printf("请输入出发站及到达站\n");
	printf("出发站：\t");
	scanf_s("%s", &station_idC, 10);
	printf("\t到达站：\t");
	scanf_s("%s", &station_idA, 10);
	printf("可供选择车次编号有：\n");	int state_C = 0, state_A = 0;
	for (int i = 0; i < 10; i++)
	{
		int j = 0, k = 0;
		if (train[i].train_state != 1)
			break;
		else {
			Station *h, *p;
			h = (Station *)malloc(sizeof(Station));
			p = (Station *)malloc(sizeof(Station));
			p->next = NULL;

			h = train[i].station;
			p->next = h->next;
			p = h->next;

			while (p != NULL)
			{
				if (!strcmp(p->Station_ID, station_idC))
				{
					state_C = 2; state_A = 0;
					j++;
				}
				else if (!strcmp(p->Station_ID, station_idA))
				{
					state_A++;
					state_C++;
					k++;
				}
				if (j > 0 && k == 0)
					j++;
				p = p->next;
			}
		}
		if (state_C == 3 && state_A == 1)
		{
			printf("车站编号%d\t", i + 1);
			NUM[i] = j - 1; //满足条件的车次的间隔大站数
		}
		else NUM[i] = 0;
		printf("中间间隔%d站\n", j - 2);
	}

	int station_id;
	printf("是否继续查询车次编号？继续请输入Y");
	char L; getchar();
	scanf_s("%c", &L);


	if (L == 'Y')
	{
		printf("请选择其中一个车次编号查询\n");
		scanf_s("%d", &station_id);
		SelectTrain(train[station_id - 1], NUM[station_id - 1], station_id, station_idC, station_idA, 1);
		printf("1.主菜单\n2.客户端\n0.退出\n");
		int c;
		scanf_s("%d", &c);
		switch (c)
		{
		case 1:mena(); break;
		case 2:Server(); break;
		case 0:
			printf("* * * * * * * * * * * * * * * * * * *  * *\n");
			printf("*                                       *\n");
			printf("*           Thanks for using            *\n");
			printf("*                                       *\n");
			printf("* * * * * * * * * * * * * * * * * * *  * *\n");
			exit(0); break;
		}
		return 0;
	}
	else {
		printf("1.主菜单\n2.客户端\n0.退出\n");
		int c;
		scanf_s("%d", &c);
		switch (c)
		{
		case 1:mena(); break;
		case 2:Server(); break;
		case 0:
			printf("* * * * * * * * * * * * * * * * * * *  * *\n");
			printf("*                                       *\n");
			printf("*           Thanks for using            *\n");
			printf("*                                       *\n");
			printf("* * * * * * * * * * * * * * * * * * *  * *\n");
			exit(0); break;
		}
		return 0;
	}
}

int SELECT()
{
	printf("1.查询车站\n");
	printf("2.查询车次车票情况\n");
	printf("0.返回主菜单\n");
	int a;
	printf("Input 0-2:");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:
		SelectStation(train);

		break;
	case 2:
		printf("您选择了查询车次信息：\n");
		printf("可查询车次号：");
		for (int i = 0; i < 10; i++)
		if (train[i].train_state == 1)
			printf("%d\t", i + 1);
		printf("\n");
		printf("请输入您要查询的车次号：");
		int j;
		scanf_s("%d", &j);
		SelectTrain(train[j - 1], 0, j, NULL, NULL, 0);
		break;
	case 0:
		mena();
		break;
	default: printf("The number is not in 0-2!\n"); getchar(); break;
	}

	return 0;
}
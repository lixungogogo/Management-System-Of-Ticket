#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "linklist.h"
#include <malloc.h>
#include <string.h>
/***************��ѯ*******************/

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
					printf("\nʣ�೵Ʊ�ţ�");
					printf("%d\t\t", k + 1);
					printf("��λ���ͣ�%c\t", train.ticket.tickets[k].seat.Seattype_ID);
					printf("��λ��:\t");
					printf("%d\t", train.ticket.tickets[k].seat.Seat_ID);
					printf("\n");
					printf("����վ��%s\n", train.ticket.tickets[k].Station_C);
					Station *q;
					q = train.station;
					while (q)
					{
						q = q->next;
						if (!strcmp(q->Station_ID, train.ticket.tickets[k].Station_C))
						{
							printf("����ʱ�䣺%d-%d-%d-%d:%d\n",
								q->time_C.Time_Y, q->time_C.Time_MON, q->time_C.Time_D, q->time_C.Time_H, q->time_C.Time_MIN);

							printf("����ʱ�䣺%d-%d-%d-%d:%d\n"
								, q->time_A.Time_Y, q->time_A.Time_MON, q->time_A.Time_D, q->time_A.Time_H, q->time_A.Time_MIN);
							break;
						}
					}
					printf("����վ��%s\n", train.ticket.tickets[k].Station_A);
					Station *p;
					p = train.station;
					while (p)
					{
						p = p->next;
						if (!strcmp(p->Station_ID, train.ticket.tickets[k].Station_A))
						{
							printf("����ʱ�䣺%d-%d-%d-%d:%d\n",
								p->time_C.Time_Y, p->time_C.Time_MON, p->time_C.Time_D, p->time_C.Time_H, p->time_C.Time_MIN);

							printf("����ʱ�䣺%d-%d-%d-%d:%d\n"
								, p->time_A.Time_Y, p->time_A.Time_MON, p->time_A.Time_D, p->time_A.Time_H, p->time_A.Time_MIN);

							break;
						}
					}
					j++;
				}
			}
			else {
				printf("ʣ�೵Ʊ�ţ�");
				printf("%d\t", k + 1);
				printf("��λ���ͣ�%c\t", train.ticket.tickets[k].seat.Seattype_ID);
				printf("��λ�ţ�:\t");
				printf("%d\t", train.ticket.tickets[k].seat.Seat_ID);
				printf("\n");
				printf("����վ��%s\n", train.ticket.tickets[k].Station_C);
				Station *q;
				q = train.station;
				while (q)
				{
					q = q->next;
					if (!strcmp(q->Station_ID, train.ticket.tickets[k].Station_C))
					{
						printf("����ʱ�䣺%d-%d-%d-%d:%d\n",
							q->time_C.Time_Y, q->time_C.Time_MON, q->time_C.Time_D, q->time_C.Time_H, q->time_C.Time_MIN);
						printf("����ʱ�䣺%d-%d-%d-%d-:%d\n"
							, q->time_A.Time_Y, q->time_A.Time_MON, q->time_A.Time_D, q->time_A.Time_H, q->time_A.Time_MIN);
						break;
					}
				}
				printf("����վ��%s\n", train.ticket.tickets[k].Station_A);
				Station *p;
				p = train.station;
				while (p)
				{
					p = p->next;
					if (!strcmp(p->Station_ID, train.ticket.tickets[k].Station_A))
					{
						printf("����ʱ�䣺%d-%d-%d-%d:%d\n",
							p->time_C.Time_Y, p->time_C.Time_MON, p->time_C.Time_D, p->time_C.Time_H, p->time_C.Time_MIN);
						printf("����ʱ�䣺%d-%d-%d-%d-:%d\n"
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

		printf("�ó���û��ʣ�೵Ʊ����ѡ�������ɹ�ѡ�񳵴Σ�\n");
		return 1;
	}
	else{

		printf("��ѡ��һ����Ʊ�ţ�\n");
		int a, b;
		scanf_s("%d", &b);
		a = b - 1;

		printf("��ϸ��Ϣ��\n");

		printf("����ţ�%d\n", train.ticket.tickets[a].Cap_ID);
		printf("��λ���ͣ�%c\n", train.ticket.tickets[a].seat.Seattype_ID);
		printf("��λ�ţ�%d\n", train.ticket.tickets[a].seat.Seat_ID);
		printf("����һվ�۸�%d\n", train.ticket.tickets[a].Price);
		printf("�ۿۣ�%f\n", train.ticket.tickets[a].Discout);
		printf("����վ��%s\n", train.ticket.tickets[a].Station_C);
		Station *q;
		q = train.station;
		while (q)
		{
			q = q->next;
			if (!strcmp(q->Station_ID, train.ticket.tickets[a].Station_C))
			{
				printf("����ʱ�䣺%d-%d-%d-%d:%d\n",
					q->time_C.Time_Y, q->time_C.Time_MON, q->time_C.Time_D, q->time_C.Time_H, q->time_C.Time_MIN);
				printf("����ʱ�䣺%d-%d-%d-%d:%d\n"
					, q->time_A.Time_Y, q->time_A.Time_MON, q->time_A.Time_D, q->time_A.Time_H, q->time_A.Time_MIN);
				break;
			}
		}
		printf("����վ��%s\n", train.ticket.tickets[a].Station_A);
		Station *p;
		p = train.station;
		while (p)
		{
			p = p->next;
			if (!strcmp(p->Station_ID, train.ticket.tickets[a].Station_A))
			{
				printf("����ʱ�䣺%d-%d-%d-%d:%d\n",
					p->time_C.Time_Y, p->time_C.Time_MON, p->time_C.Time_D, p->time_C.Time_H, p->time_C.Time_MIN);
				printf("����ʱ�䣺%d-%d-%d-%d:%d\n"
					, p->time_A.Time_Y, p->time_A.Time_MON, p->time_A.Time_D, p->time_A.Time_H, p->time_A.Time_MIN);
				break;
			}
		}
		if (NUM != 0)
		{
			int price = (train.ticket.tickets[a].Price)*(NUM);
			printf("�ۿ�ǰ�۸�%d\n", price);
			double PRICE = (price)* (train.ticket.tickets[a].Discout);
			printf("�ܼ۸�%4.2f\n", PRICE);
		}
	}
	//getchar();
	printf("1.���˵�\n2.�ͻ���\n0.�˳�\n");
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
	printf("���������վ������վ\n");
	printf("����վ��\t");
	scanf_s("%s", &station_idC, 10);
	printf("\t����վ��\t");
	scanf_s("%s", &station_idA, 10);
	printf("�ɹ�ѡ�񳵴α���У�\n");	int state_C = 0, state_A = 0;
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
			printf("��վ���%d\t", i + 1);
			NUM[i] = j - 1; //���������ĳ��εļ����վ��
		}
		else NUM[i] = 0;
		printf("�м���%dվ\n", j - 2);
	}

	int station_id;
	printf("�Ƿ������ѯ���α�ţ�����������Y");
	char L; getchar();
	scanf_s("%c", &L);


	if (L == 'Y')
	{
		printf("��ѡ������һ�����α�Ų�ѯ\n");
		scanf_s("%d", &station_id);
		SelectTrain(train[station_id - 1], NUM[station_id - 1], station_id, station_idC, station_idA, 1);
		printf("1.���˵�\n2.�ͻ���\n0.�˳�\n");
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
		printf("1.���˵�\n2.�ͻ���\n0.�˳�\n");
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
	printf("1.��ѯ��վ\n");
	printf("2.��ѯ���γ�Ʊ���\n");
	printf("0.�������˵�\n");
	int a;
	printf("Input 0-2:");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:
		SelectStation(train);

		break;
	case 2:
		printf("��ѡ���˲�ѯ������Ϣ��\n");
		printf("�ɲ�ѯ���κţ�");
		for (int i = 0; i < 10; i++)
		if (train[i].train_state == 1)
			printf("%d\t", i + 1);
		printf("\n");
		printf("��������Ҫ��ѯ�ĳ��κţ�");
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
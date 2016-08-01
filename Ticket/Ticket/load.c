#define _CRT_SECURE_NO_WARNINGS 1

#include  <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "linklist.h"
#include <malloc.h>
#include <string.h>


/*****************�Զ�¼��*************/

Train LOAD_1()
{
	Train train;
	train.Train_ID = 1;
	train.Traintype_ID = 'G';
	train.train_state = 1;
	train.Cap_num = 1;
	train.Seat_num = 30;

	strcpy_s(train.CStation, sizeof("�Ϻ�"), "�Ϻ�");
	strcpy_s(train.AStation, sizeof("����"), "����");
	train.Time_C.Time_Y = 2015;
	train.Time_C.Time_MON = 6;
	train.Time_C.Time_D = 24;
	train.Time_A.Time_Y = 2015;
	train.Time_A.Time_MON = 6;
	train.Time_A.Time_D = 25;

	train.station = (Station *)malloc(sizeof(Station));
	train.station->next = NULL;
	Station *q;
	q = (Station *)malloc(sizeof(Station));
	q->next = NULL;

	q->Station_ID = "�Ϻ�";
	station_line[0].Station_ID[0] = "�Ϻ�";
	q->time_C.Time_Y = 2015;
	q->time_C.Time_MON = 6;
	q->time_C.Time_D = 24;
	q->time_C.Time_H = 18;
	q->time_C.Time_MIN = 25;

	q->time_A.Time_Y = 2015;
	q->time_A.Time_MON = 6;
	q->time_A.Time_D = 24;
	q->time_A.Time_H = 18;
	q->time_A.Time_MIN = 26;
	q->time = 8;
	q->next = train.station->next;
	train.station->next = q;
	q->next = NULL;


	Station *o;
	o = (Station *)malloc(sizeof(Station));
	o->next = NULL;

	o->Station_ID = "�ɶ�";
	station_line[0].Station_ID[1] = "�ɶ�";
	o->time_C.Time_Y = 2015;
	o->time_C.Time_MON = 6;
	o->time_C.Time_D = 25;
	o->time_C.Time_H = 8;
	o->time_C.Time_MIN = 5;

	o->time_A.Time_Y = 2015;
	o->time_A.Time_MON = 6;
	o->time_A.Time_D = 25;
	o->time_A.Time_H = 8;
	o->time_A.Time_MIN = 10;
	o->next = q->next;
	q->next = o;
	o->next = NULL;

	Station *p;
	p = (Station *)malloc(sizeof(Station));
	p->next = NULL;

	p->Station_ID = "���";
	station_line[0].Station_ID[2] = "���";
	p->time_C.Time_Y = 2015;
	p->time_C.Time_MON = 6;
	p->time_C.Time_D = 25;
	p->time_C.Time_H = 12;
	p->time_C.Time_MIN = 25;

	p->time_A.Time_Y = 2015;
	p->time_A.Time_MON = 6;
	p->time_A.Time_D = 25;
	p->time_A.Time_H = 12;
	p->time_A.Time_MIN = 26;
	p->next = o->next;
	o->next = p;
	p->next = NULL;

	Station *r;
	r = (Station *)malloc(sizeof(Station));
	r->next = NULL;

	r->Station_ID = "�人";
	station_line[0].Station_ID[3] = "�人";
	r->time_C.Time_Y = 2015;
	r->time_C.Time_MON = 6;
	r->time_C.Time_D = 25;
	r->time_C.Time_H = 18;
	r->time_C.Time_MIN = 5;

	r->time_A.Time_Y = 2015;
	r->time_A.Time_MON = 6;
	r->time_A.Time_D = 25;
	r->time_A.Time_H = 18;
	r->time_A.Time_MIN = 16;
	r->next = p->next;
	p->next = r;
	r->next = NULL;
	Station *s;
	s = (Station *)malloc(sizeof(Station));
	s->next = NULL;

	s->Station_ID = "����";
	station_line[0].Station_ID[4] = "����";
	s->time_C.Time_Y = 2015;
	s->time_C.Time_MON = 6;
	s->time_C.Time_D = 25;
	s->time_C.Time_H = 23;
	s->time_C.Time_MIN = 25;

	s->time_A.Time_Y = 2015;
	s->time_A.Time_MON = 6;
	s->time_A.Time_D = 25;
	s->time_A.Time_H = 23;
	s->time_A.Time_MIN = 28;
	s->next = r->next;
	r->next = s;
	s->next = NULL;


	Ticket *array;

	array = (Ticket*)calloc(40, sizeof(Ticket));
	train.ticket.Tickets_Num = 40;
	int i; int j = 1, k = 1;
	for (i = 0; i < 40; i++)
	{
		train.ticket.tickets = array;
		train.ticket.tickets[i].Ticket_State = 0;
		train.ticket.tickets[i].Train_id = train.Train_ID;
		train.ticket.tickets[i].Train_type = train.Traintype_ID;
		train.ticket.tickets[i].tic_num = i + 1;//��Ʊ��
		if (i < 20)
		{
			train.ticket.tickets[i].Cap_ID = 1;

			train.ticket.tickets[i].seat.Seat_ID = i + 1;
			if (i < 10)
			{
				train.ticket.tickets[i].seat.Seattype_ID = 'S';
				train.ticket.tickets[i].Price = 85;
				train.ticket.tickets[i].Discout = 0.9;
			}
			else
			{
				train.ticket.tickets[i].seat.Seattype_ID = 'H';
				train.ticket.tickets[i].Price = 55;
				train.ticket.tickets[i].Discout = 0.8;
			}
		}
		else if (i < 30)

		{
			train.ticket.tickets[i].Cap_ID = 1;
			train.ticket.tickets[i].seat.Seattype_ID = 's';
			train.ticket.tickets[i].seat.Seat_ID = 0;
			train.ticket.tickets[i].Price = 25;
			train.ticket.tickets[i].Discout = 0.7; j++;
		}
		else if (i <  40)

		{
			train.ticket.tickets[i].Ticket_State = 0;
			train.ticket.tickets[i].Cap_ID = 1;
			train.ticket.tickets[i].seat.Seattype_ID = 'L';
			train.ticket.tickets[i].seat.Seat_ID = 0;
			train.ticket.tickets[i].Price = 100;
			train.ticket.tickets[i].Discout = 1; k++;
		}
		int j = i % 10;
		switch (j)
		{
		case 0:train.ticket.tickets[i].Station_C = "�Ϻ�"; train.ticket.tickets[i].Station_A = "�ɶ�"; break;
		case 1:train.ticket.tickets[i].Station_C = "�Ϻ�"; train.ticket.tickets[i].Station_A = "���"; break;
		case 2:train.ticket.tickets[i].Station_C = "�Ϻ�"; train.ticket.tickets[i].Station_A = "�人"; break;
		case 3:train.ticket.tickets[i].Station_C = "�Ϻ�"; train.ticket.tickets[i].Station_A = "����"; break;
		case 4:train.ticket.tickets[i].Station_C = "�ɶ�"; train.ticket.tickets[i].Station_A = "���"; break;
		case 5:train.ticket.tickets[i].Station_C = "�ɶ�"; train.ticket.tickets[i].Station_A = "�人"; break;
		case 6:train.ticket.tickets[i].Station_C = "�ɶ�"; train.ticket.tickets[i].Station_A = "����"; break;
		case 7:train.ticket.tickets[i].Station_C = "���"; train.ticket.tickets[i].Station_A = "�人"; break;
		case 8:train.ticket.tickets[i].Station_C = "���"; train.ticket.tickets[i].Station_A = "����"; break;
		case 9:train.ticket.tickets[i].Station_C = "�人"; train.ticket.tickets[i].Station_A = "����"; break;
		}
	}

	return train;
}


/********************�ֶ�¼����Ϣ*****************/

int Create_stationlist(int num, Train *train, Station **S, int Num, char *C_id, char  *A_id)
{

	(*S) = (Station*)malloc(sizeof(Station));
	(*S)->next = NULL;

	for (int i = 1; i <= num; i++)
	{
		station_line[Num].Station_ID[i - 1] = (char*)malloc(10 * sizeof(char));
		int time; char ID[10];
		Time time_c, time_a;
		printf("�������%d����վ����\t", i);
		scanf_s("%s", &ID, 10);
		strcpy_s(station_line[Num].Station_ID[i - 1], 10, ID);
		printf("�����뵽��ʱ�䣺\n");
		printf("��\t��\t��\tСʱ\t����\n");
		scanf_s("%d%d%d%d%d", &time_a.Time_Y, &time_a.Time_MON, &time_a.Time_D, &time_a.Time_H, &time_a.Time_MIN);

		printf("���������ʱ�䣺");
		printf("��\t��\t��\tСʱ\t����\n");
		scanf_s("%d%d%d%d%d", &time_c.Time_Y, &time_c.Time_MON, &time_c.Time_D, &time_c.Time_H, &time_c.Time_MIN);

		printf("�������г��ڸ�վͣ��ʱ�䣺");
		getchar();
		scanf_s("%d", &time);

		if (i == 1)
		if (strcmp(ID, C_id) != 0)
		{
			printf("��������ʼ��վ��ͬ�����������룡\a\a\a\n\n");
			load(train, Num);
		}
		if (i == num)
		if (strcmp(ID, A_id) != 0)
		{
			printf("���������յ�վ��ͬ�����������룡\a\a\a\n\n");
			load(train, Num);
		}
		printf("\n");
		ListInsert_station(*S, i + 1, ID, time_c, time_a, time);


	}

	return 0;
}
//������վ��Ϣ

Train *tickets_load(Train *train, int Num, int station_num, char train_type)
{
	int price_stand, price_hard, price_soft, price_lie;
	float discout_stand, discout_seats, discout_seath, discout_lie;
	scanf_s("%d", &train->ticket.Tickets_Num);//���빲�ж����ų�Ʊ
	// train->ticket.Tickets_Num = tickets_list[Num].Tickets_Num;
	int stand_num = 0, seat_num = 0, lie_num = 0, seat_s = 0, seat_h = 0;


	printf("����������վƱƱ����\t");
	scanf_s("%d", &stand_num);
	train->ticket.stand_num = stand_num;
	if (stand_num > train->ticket.Tickets_Num)
	{
		printf("����Ʊ��������Ʊ�������������룡\n");
		printf("�����빲�ж����ų�Ʊ������վƱ����Ʊ�����̣�\n");
		return NULL;
	}

	if (stand_num != 0)
	{
		printf("վƱһվ�۸�Ϊ:\t");
		scanf_s("%d", &price_stand);
		printf("վƱ�ۿ�Ϊ��\t");
		scanf_s("%f", &discout_stand);
	}



	printf("������������ƱƱ��(����λ��)��\t");
	scanf_s("%d", &seat_num);

	if (stand_num + seat_num > train->ticket.Tickets_Num)
	{
		printf("����Ʊ��������Ʊ�������������룡\n");
		printf("�����빲�ж����ų�Ʊ������վƱ����Ʊ�����̣�\n");
		return NULL;
	}



	if (seat_num != 0)
	{
		printf("����������Ӳ��Ʊ����\t");
		scanf_s("%d", &seat_h);
		train->ticket.hard_num = seat_h;
		if (seat_h> seat_num)
		{
			printf("����Ʊ����������Ʊ�������������룡\n");
			printf("�����빲�ж����ų�Ʊ������վƱ����Ʊ�����̣�\n");
			return NULL;
		}
		if (seat_h != 0)
		{
			printf("Ӳ��һվƱ�۸�Ϊ:\t");
			scanf_s("%d", &price_hard);
			printf("Ӳ��Ʊ�ۿ�Ϊ��\t");
			scanf_s("%f", &discout_seath);
		}



		printf("��������������Ʊ����\t");
		scanf_s("%d", &seat_s);
		train->ticket.soft_num = seat_s;
		if ((seat_s + seat_h) > seat_num)
		{
			printf("����������Ӳ��Ʊ����������Ʊ�������������룡\n");
			printf("�����빲�ж����ų�Ʊ������վƱ����Ʊ�����̣�\n");
			return NULL;
		}
		if (seat_s != 0)
		{
			printf("����һվƱ�۸�Ϊ:\t");
			scanf_s("%d", &price_soft);
			printf("����Ʊ�ۿ�Ϊ��\t");
			scanf_s("%f", &discout_seats);
		}
	}



	printf("��������������Ʊ����\t");
	scanf_s("%d", &lie_num);
	train->ticket.lie_num = lie_num;
	if ((stand_num + seat_num) + lie_num > train->ticket.Tickets_Num)
	{
		printf("����Ʊ���������������룡\n");
		printf("�����빲�ж����ų�Ʊ������վƱ����Ʊ�����̣�\n");
		return NULL;
	}
	if (lie_num != 0){
		printf("����һվƱ�۸�Ϊ:\t");
		scanf_s("%d", &price_lie);
		printf("����Ʊ�ۿ�Ϊ��\t");
		scanf_s("%f", &discout_lie);
	}

	Ticket *array;

	array = (Ticket*)calloc(train->ticket.Tickets_Num, sizeof(Ticket));
	int i, j;
	printf("��λ���ͣ�\tվƱ:s\t����:S\tӲ��:H\t����:L\n");


	for (i = 0, j = 0; i < train->ticket.Tickets_Num; i++)
	{
		train->ticket.tickets = array;  //��Ʊ���Ա� ��ʾNum�ų��ε����г�Ʊ
		train->ticket.tickets[i].tic_num = i + 1; //��Ʊ��
		train->ticket.tickets[i].Train_id = train->Train_ID;
		train->ticket.tickets[i].Train_type = train_type;
		if (i < stand_num)
		{
			train->ticket.tickets[i].seat.Seattype_ID = 's';
			train->ticket.tickets[i].Price = price_stand;
			train->ticket.tickets[i].Discout = discout_stand;

		}
		else if (i < (stand_num + seat_num) && j < seat_num)
		{
			if (j < seat_s)
			{
				train->ticket.tickets[i].seat.Seattype_ID = 'H';
				train->ticket.tickets[i].Price = price_soft;
				train->ticket.tickets[i].Discout = discout_seats;
			}
			else {
				train->ticket.tickets[i].seat.Seattype_ID = 'S';
				train->ticket.tickets[i].Price = price_hard;
				train->ticket.tickets[i].Discout = discout_seath;
			}
			j++;
			train->ticket.tickets[i].seat.Seat_ID = j;
		}
		else {
			train->ticket.tickets[i].seat.Seattype_ID = 'L';
			train->ticket.tickets[i].Discout = discout_lie;
			train->ticket.tickets[i].Price = price_lie;
		}

		train->ticket.tickets[i].Ticket_State = 0;
		train->ticket.tickets[i].Station_State = 0;

		printf("��%d��Ʊ\n��λ��Ϊ��%d\t��λ����Ϊ��%c\t",
			i + 1, train->ticket.tickets[i].seat.Seat_ID, train->ticket.tickets[i].seat.Seattype_ID);
		if (train->ticket.tickets[i].Ticket_State == 0) printf("����\n"); else printf("����\n");
	}

	return train;
}
//¼�복Ʊ��Ϣ
int tickets_station(Train *train, int Num, int num)
{
	int s = 0, S = 0, H = 0, L = 0;
	printf("��Ʊ��Ϊ��%d\n", train->ticket.Tickets_Num);
	printf("վƱ��Ʊ��Ϊ��%d\n", train->ticket.stand_num);
	printf("Ӳ����Ʊ��Ϊ��%d\n", train->ticket.hard_num);
	printf("������Ʊ��Ϊ��%d\n", train->ticket.soft_num);
	printf("������Ʊ��Ϊ��%d\n", train->ticket.lie_num);
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = num - 1; j > i; j--)
		{
			printf("����վ��%s\n", station_line[Num].Station_ID[i]);
			printf("����վ��%s\n", station_line[Num].Station_ID[j]);
			printf("������վƱ������\t");
			scanf_s("%d", &s);    printf("\n");
			for (int k = 0, o = 0; k < train->ticket.Tickets_Num; k++)
			{
				if (train->ticket.tickets[k].Station_State == 0 && train->ticket.tickets[k].seat.Seattype_ID == 's')
				{
					o++;
					train->ticket.tickets[k].Station_C = (char *)malloc(10 * sizeof(char));
					train->ticket.tickets[k].Station_A = (char *)malloc(10 * sizeof(char));
					strcpy_s(train->ticket.tickets[k].Station_C, 10, station_line[Num].Station_ID[i + 1]);
					strcpy_s(train->ticket.tickets[k].Station_A, 10, station_line[Num].Station_ID[j]);
					train->ticket.tickets[k].Station_State = 1;
					if (o >= s) break;
				}
			}
			printf("������Ӳ��Ʊ������\t");
			scanf_s("%d", &H);    printf("\n");
			for (int k = 0, o = 0; k < train->ticket.Tickets_Num; k++)
			{
				if (train->ticket.tickets[k].Station_State == 0 && train->ticket.tickets[k].seat.Seattype_ID == 'H')
				{
					o++;
					train->ticket.tickets[k].Station_C = (char *)malloc(10 * sizeof(char));
					train->ticket.tickets[k].Station_A = (char *)malloc(10 * sizeof(char));
					strcpy_s(train->ticket.tickets[k].Station_C, 10, station_line[Num].Station_ID[i]);
					strcpy_s(train->ticket.tickets[k].Station_A, 10, station_line[Num].Station_ID[j]);
					train->ticket.tickets[k].Station_State = 1;
					if (o >= H) break;
				}
			}
			printf("����������Ʊ������\t");
			scanf_s("%d", &S);    printf("\n");
			for (int k = 0, o = 0; k < train->ticket.Tickets_Num; k++)
			{
				if (train->ticket.tickets[k].Station_State == 0 && train->ticket.tickets[k].seat.Seattype_ID == 'S')
				{
					o++;
					train->ticket.tickets[k].Station_C = (char *)malloc(10 * sizeof(char));
					train->ticket.tickets[k].Station_A = (char *)malloc(10 * sizeof(char));
					strcpy_s(train->ticket.tickets[k].Station_C, 10, station_line[Num].Station_ID[i]);
					strcpy_s(train->ticket.tickets[k].Station_A, 10, station_line[Num].Station_ID[j]);
					train->ticket.tickets[k].Station_State = 1;
					if (o >= S) break;
				}
			}
			printf("����������Ʊ������\t");
			scanf_s("%d", &L);    printf("\n");
			for (int k = 0, o = 0; k < train->ticket.Tickets_Num; k++)
			{
				if (train->ticket.tickets[k].Station_State == 0 && train->ticket.tickets[k].seat.Seattype_ID == 'L')
				{
					o++;
					train->ticket.tickets[k].Station_C = (char *)malloc(10 * sizeof(char));
					train->ticket.tickets[k].Station_A = (char *)malloc(10 * sizeof(char));
					strcpy_s(train->ticket.tickets[k].Station_C, 10, station_line[Num].Station_ID[i]);
					strcpy_s(train->ticket.tickets[k].Station_A, 10, station_line[Num].Station_ID[j]);
					train->ticket.tickets[k].Station_State = 1;
					if (o >= L) break;
				}
			}
		}
	}
	return 0;
}

int load_index()
{
	printf("********¼�복����Ϣ��********\n");
	printf("����ʮ�����Σ���ŷֱ�Ϊ1-10\n");
	printf("1\t2\t3\t4\t5\n6\t7\t8\t9\t10\t\n");
	printf("������¼��ĳ��α��Ϊ��\n");
	for (int i = 0; i < 10; i++)
	if (train[i].train_state == 0)
		printf("%d\t", i + 1);
	printf("\n");
	printf("�����복����Ϣ��\n");
	printf("���α�ţ�\t");
	int num;
	scanf_s("%d", &num);
	return (num - 1);
}
//�ֶ�¼������

int traver_station(Station* q, int num)
{
	printf("\n");
	for (int k = 0; k < num; k++)
	{
		printf("���γ�վΪ:");
		q = q->next;
		printf("%s\n����ʱ�䣺%d-%d-%d-%d:%d\n����ʱ�䣺%d-%d-%d-%d:%d\nͣ��ʱ�䣺%dMIN\n",
			q->Station_ID, q->time_A.Time_Y, q->time_A.Time_MON, q->time_A.Time_D, q->time_A.Time_H, q->time_A.Time_MIN,
			q->time_C.Time_Y, q->time_C.Time_MON, q->time_C.Time_D, q->time_C.Time_H, q->time_C.Time_MIN, q->time);

	}
	return 0;
}
//������վ����

void load(Train *train, int Num)//num�ǳ��δ�վ���Ա���
{
	train->Train_ID = Num + 1;
	train->station = (Station*)malloc(sizeof(Station));
	printf("\n");

	printf("����վ�� \t");
	scanf_s("%s", &train->CStation, 10);
	printf("\n");

	printf("����վ�� \t");
	scanf_s("%s", &train->AStation, 10);
	printf("\n");

	int num = 0;
	printf(";����Ҫ��վ������ \t");
	getchar();
	scanf_s("%d", &num);

	Create_stationlist(num, train, &train->station, Num, train->CStation, train->AStation);
	traver_station(train->station, num);
	printf("��վ���Ա�Ϊ��");
	Station *p;
	p = (Station *)malloc(sizeof(Station));
	p = train->station;
	for (int k = 0; k < num; k++)
	{
		p = p->next;
		printf("->%s", p->Station_ID);
	}

	printf("\n");
	printf("�������ͣ�\t");
	printf("����������G������������D��ֱ��������Z���ؿ�������T������������K\n");
	getchar();
	scanf_s("%c", &train->Traintype_ID, 1);
	printf("\n");

	printf("����ʱ�䣺(��ʽΪ����\t��\t��\tСʱ\t����)\n");
	scanf_s("%d%d%d%d%d",
		&train->Time_C.Time_Y, &train->Time_C.Time_MON, &train->Time_C.Time_D, &train->Time_C.Time_H, &train->Time_C.Time_MIN);
	printf("\n");

	printf("����ʱ��: (��ʽΪ����\t��\t��\tСʱ\t����)\n");
	scanf_s("%d%d%d%d%d",
		&train->Time_A.Time_Y, &train->Time_A.Time_MON, &train->Time_A.Time_D, &train->Time_A.Time_H, &train->Time_A.Time_MIN);
	printf("\n");

	printf("�������� \t");
	scanf_s("%d", &train->Cap_num);
	printf("\n");


	printf("ÿ��������λ���ֱ�Ϊ�� \n");
	scanf_s("%d", &train->Seat_num);
	printf("\n");


	printf("�����빲�ж����ų�Ʊ������վƱ����Ʊ�����̣�\n");
	train = tickets_load(train, Num, num, train->Traintype_ID);
	while (train == NULL)
		train = tickets_load(train, Num, num, train->Traintype_ID);
	tickets_station(train, Num, num);
	train->train_state = 1;

}
//�ֶ�¼��

int LOAD()
{
	int Num;
	printf("��ѡ�����ֶ�¼�복����Ϣ��\n\n\n");
	Num = load_index();
	load(&train[Num], Num);
	printf("�Ƿ���Ҫ����¼���������Σ�\n����˳�������0\n����������1\n���ؿͻ���������2\n");
	int dec;
	scanf_s("%d", &dec);
	switch (dec)
	{
	case 1: LOAD();; break;
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
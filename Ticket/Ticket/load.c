#define _CRT_SECURE_NO_WARNINGS 1

#include  <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "linklist.h"
#include <malloc.h>
#include <string.h>


/*****************自动录入*************/

Train LOAD_1()
{
	Train train;
	train.Train_ID = 1;
	train.Traintype_ID = 'G';
	train.train_state = 1;
	train.Cap_num = 1;
	train.Seat_num = 30;

	strcpy_s(train.CStation, sizeof("上海"), "上海");
	strcpy_s(train.AStation, sizeof("北京"), "北京");
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

	q->Station_ID = "上海";
	station_line[0].Station_ID[0] = "上海";
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

	o->Station_ID = "成都";
	station_line[0].Station_ID[1] = "成都";
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

	p->Station_ID = "天津";
	station_line[0].Station_ID[2] = "天津";
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

	r->Station_ID = "武汉";
	station_line[0].Station_ID[3] = "武汉";
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

	s->Station_ID = "北京";
	station_line[0].Station_ID[4] = "北京";
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
		train.ticket.tickets[i].tic_num = i + 1;//车票号
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
		case 0:train.ticket.tickets[i].Station_C = "上海"; train.ticket.tickets[i].Station_A = "成都"; break;
		case 1:train.ticket.tickets[i].Station_C = "上海"; train.ticket.tickets[i].Station_A = "天津"; break;
		case 2:train.ticket.tickets[i].Station_C = "上海"; train.ticket.tickets[i].Station_A = "武汉"; break;
		case 3:train.ticket.tickets[i].Station_C = "上海"; train.ticket.tickets[i].Station_A = "北京"; break;
		case 4:train.ticket.tickets[i].Station_C = "成都"; train.ticket.tickets[i].Station_A = "天津"; break;
		case 5:train.ticket.tickets[i].Station_C = "成都"; train.ticket.tickets[i].Station_A = "武汉"; break;
		case 6:train.ticket.tickets[i].Station_C = "成都"; train.ticket.tickets[i].Station_A = "北京"; break;
		case 7:train.ticket.tickets[i].Station_C = "天津"; train.ticket.tickets[i].Station_A = "武汉"; break;
		case 8:train.ticket.tickets[i].Station_C = "天津"; train.ticket.tickets[i].Station_A = "北京"; break;
		case 9:train.ticket.tickets[i].Station_C = "武汉"; train.ticket.tickets[i].Station_A = "北京"; break;
		}
	}

	return train;
}


/********************手动录入信息*****************/

int Create_stationlist(int num, Train *train, Station **S, int Num, char *C_id, char  *A_id)
{

	(*S) = (Station*)malloc(sizeof(Station));
	(*S)->next = NULL;

	for (int i = 1; i <= num; i++)
	{
		station_line[Num].Station_ID[i - 1] = (char*)malloc(10 * sizeof(char));
		int time; char ID[10];
		Time time_c, time_a;
		printf("请输入第%d个车站名：\t", i);
		scanf_s("%s", &ID, 10);
		strcpy_s(station_line[Num].Station_ID[i - 1], 10, ID);
		printf("请输入到达时间：\n");
		printf("年\t月\t日\t小时\t分钟\n");
		scanf_s("%d%d%d%d%d", &time_a.Time_Y, &time_a.Time_MON, &time_a.Time_D, &time_a.Time_H, &time_a.Time_MIN);

		printf("请输入出发时间：");
		printf("年\t月\t日\t小时\t分钟\n");
		scanf_s("%d%d%d%d%d", &time_c.Time_Y, &time_c.Time_MON, &time_c.Time_D, &time_c.Time_H, &time_c.Time_MIN);

		printf("请输入列车在该站停靠时间：");
		getchar();
		scanf_s("%d", &time);

		if (i == 1)
		if (strcmp(ID, C_id) != 0)
		{
			printf("两次输入始发站不同！请重新输入！\a\a\a\n\n");
			load(train, Num);
		}
		if (i == num)
		if (strcmp(ID, A_id) != 0)
		{
			printf("两次输入终点站不同！请重新输入！\a\a\a\n\n");
			load(train, Num);
		}
		printf("\n");
		ListInsert_station(*S, i + 1, ID, time_c, time_a, time);


	}

	return 0;
}
//创建车站信息

Train *tickets_load(Train *train, int Num, int station_num, char train_type)
{
	int price_stand, price_hard, price_soft, price_lie;
	float discout_stand, discout_seats, discout_seath, discout_lie;
	scanf_s("%d", &train->ticket.Tickets_Num);//输入共有多少张车票
	// train->ticket.Tickets_Num = tickets_list[Num].Tickets_Num;
	int stand_num = 0, seat_num = 0, lie_num = 0, seat_s = 0, seat_h = 0;


	printf("请输入其中站票票数：\t");
	scanf_s("%d", &stand_num);
	train->ticket.stand_num = stand_num;
	if (stand_num > train->ticket.Tickets_Num)
	{
		printf("输入票数大于总票数！请重新输入！\n");
		printf("请输入共有多少张车票（包括站票，坐票，卧铺）\n");
		return NULL;
	}

	if (stand_num != 0)
	{
		printf("站票一站价格为:\t");
		scanf_s("%d", &price_stand);
		printf("站票折扣为：\t");
		scanf_s("%f", &discout_stand);
	}



	printf("请输入其中坐票票数(即座位数)：\t");
	scanf_s("%d", &seat_num);

	if (stand_num + seat_num > train->ticket.Tickets_Num)
	{
		printf("输入票数大于总票数！请重新输入！\n");
		printf("请输入共有多少张车票（包括站票，坐票，卧铺）\n");
		return NULL;
	}



	if (seat_num != 0)
	{
		printf("请输入其中硬座票数：\t");
		scanf_s("%d", &seat_h);
		train->ticket.hard_num = seat_h;
		if (seat_h> seat_num)
		{
			printf("输入票数大于总坐票数！请重新输入！\n");
			printf("请输入共有多少张车票（包括站票，坐票，卧铺）\n");
			return NULL;
		}
		if (seat_h != 0)
		{
			printf("硬座一站票价格为:\t");
			scanf_s("%d", &price_hard);
			printf("硬座票折扣为：\t");
			scanf_s("%f", &discout_seath);
		}



		printf("请输入其中软座票数：\t");
		scanf_s("%d", &seat_s);
		train->ticket.soft_num = seat_s;
		if ((seat_s + seat_h) > seat_num)
		{
			printf("输入软座与硬座票数大于总坐票数！请重新输入！\n");
			printf("请输入共有多少张车票（包括站票，坐票，卧铺）\n");
			return NULL;
		}
		if (seat_s != 0)
		{
			printf("软座一站票价格为:\t");
			scanf_s("%d", &price_soft);
			printf("软座票折扣为：\t");
			scanf_s("%f", &discout_seats);
		}
	}



	printf("请输入其中卧铺票数：\t");
	scanf_s("%d", &lie_num);
	train->ticket.lie_num = lie_num;
	if ((stand_num + seat_num) + lie_num > train->ticket.Tickets_Num)
	{
		printf("输入票数错误！请重新输入！\n");
		printf("请输入共有多少张车票（包括站票，坐票，卧铺）\n");
		return NULL;
	}
	if (lie_num != 0){
		printf("卧铺一站票价格为:\t");
		scanf_s("%d", &price_lie);
		printf("卧铺票折扣为：\t");
		scanf_s("%f", &discout_lie);
	}

	Ticket *array;

	array = (Ticket*)calloc(train->ticket.Tickets_Num, sizeof(Ticket));
	int i, j;
	printf("座位类型：\t站票:s\t软座:S\t硬座:H\t卧铺:L\n");


	for (i = 0, j = 0; i < train->ticket.Tickets_Num; i++)
	{
		train->ticket.tickets = array;  //车票线性表 表示Num号车次的所有车票
		train->ticket.tickets[i].tic_num = i + 1; //车票号
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

		printf("第%d张票\n座位号为：%d\t座位类型为：%c\t",
			i + 1, train->ticket.tickets[i].seat.Seat_ID, train->ticket.tickets[i].seat.Seattype_ID);
		if (train->ticket.tickets[i].Ticket_State == 0) printf("无人\n"); else printf("有人\n");
	}

	return train;
}
//录入车票信息
int tickets_station(Train *train, int Num, int num)
{
	int s = 0, S = 0, H = 0, L = 0;
	printf("总票数为：%d\n", train->ticket.Tickets_Num);
	printf("站票总票数为：%d\n", train->ticket.stand_num);
	printf("硬座总票数为：%d\n", train->ticket.hard_num);
	printf("软座总票数为：%d\n", train->ticket.soft_num);
	printf("卧铺总票数为：%d\n", train->ticket.lie_num);
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = num - 1; j > i; j--)
		{
			printf("出发站：%s\n", station_line[Num].Station_ID[i]);
			printf("到达站：%s\n", station_line[Num].Station_ID[j]);
			printf("请输入站票个数：\t");
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
			printf("请输入硬座票个数：\t");
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
			printf("请输入软座票个数：\t");
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
			printf("请输入卧铺票个数：\t");
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
	printf("********录入车次信息：********\n");
	printf("共有十个车次，编号分别为1-10\n");
	printf("1\t2\t3\t4\t5\n6\t7\t8\t9\t10\t\n");
	printf("您还可录入的车次编号为：\n");
	for (int i = 0; i < 10; i++)
	if (train[i].train_state == 0)
		printf("%d\t", i + 1);
	printf("\n");
	printf("请输入车次信息：\n");
	printf("车次编号：\t");
	int num;
	scanf_s("%d", &num);
	return (num - 1);
}
//手动录入引言

int traver_station(Station* q, int num)
{
	printf("\n");
	for (int k = 0; k < num; k++)
	{
		printf("车次车站为:");
		q = q->next;
		printf("%s\n到达时间：%d-%d-%d-%d:%d\n出发时间：%d-%d-%d-%d:%d\n停靠时间：%dMIN\n",
			q->Station_ID, q->time_A.Time_Y, q->time_A.Time_MON, q->time_A.Time_D, q->time_A.Time_H, q->time_A.Time_MIN,
			q->time_C.Time_Y, q->time_C.Time_MON, q->time_C.Time_D, q->time_C.Time_H, q->time_C.Time_MIN, q->time);

	}
	return 0;
}
//遍历车站链表

void load(Train *train, int Num)//num是车次大站线性表编号
{
	train->Train_ID = Num + 1;
	train->station = (Station*)malloc(sizeof(Station));
	printf("\n");

	printf("出发站： \t");
	scanf_s("%s", &train->CStation, 10);
	printf("\n");

	printf("到达站： \t");
	scanf_s("%s", &train->AStation, 10);
	printf("\n");

	int num = 0;
	printf("途径主要大站总数： \t");
	getchar();
	scanf_s("%d", &num);

	Create_stationlist(num, train, &train->station, Num, train->CStation, train->AStation);
	traver_station(train->station, num);
	printf("车站线性表为：");
	Station *p;
	p = (Station *)malloc(sizeof(Station));
	p = train->station;
	for (int k = 0; k < num; k++)
	{
		p = p->next;
		printf("->%s", p->Station_ID);
	}

	printf("\n");
	printf("车次类型：\t");
	printf("高铁请输入G，动车请输入D，直达请输入Z，特快请输入T，快速请输入K\n");
	getchar();
	scanf_s("%c", &train->Traintype_ID, 1);
	printf("\n");

	printf("出发时间：(格式为：年\t月\t日\t小时\t分钟)\n");
	scanf_s("%d%d%d%d%d",
		&train->Time_C.Time_Y, &train->Time_C.Time_MON, &train->Time_C.Time_D, &train->Time_C.Time_H, &train->Time_C.Time_MIN);
	printf("\n");

	printf("到达时间: (格式为：年\t月\t日\t小时\t分钟)\n");
	scanf_s("%d%d%d%d%d",
		&train->Time_A.Time_Y, &train->Time_A.Time_MON, &train->Time_A.Time_D, &train->Time_A.Time_H, &train->Time_A.Time_MIN);
	printf("\n");

	printf("车厢数： \t");
	scanf_s("%d", &train->Cap_num);
	printf("\n");


	printf("每个车厢座位数分别为： \n");
	scanf_s("%d", &train->Seat_num);
	printf("\n");


	printf("请输入共有多少张车票（包括站票，坐票，卧铺）\n");
	train = tickets_load(train, Num, num, train->Traintype_ID);
	while (train == NULL)
		train = tickets_load(train, Num, num, train->Traintype_ID);
	tickets_station(train, Num, num);
	train->train_state = 1;

}
//手动录入

int LOAD()
{
	int Num;
	printf("您选择了手动录入车次信息！\n\n\n");
	Num = load_index();
	load(&train[Num], Num);
	printf("是否需要继续录入其他车次？\n完成退出请输入0\n继续请输入1\n返回客户端请输入2\n");
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
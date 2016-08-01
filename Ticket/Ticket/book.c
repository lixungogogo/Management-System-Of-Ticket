#include  <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "linklist.h"
#include <malloc.h>
#include <string.h>

#define G 高铁
#define D 动车
#define Z 直达
#define T 特快
#define K 快速


/*************************订票************************/

Order * create_one(Client client, int i, int num, Train train, int tickets_num[10])
{
	Order* order;
	order = (Order *)malloc(sizeof(Order));
	for (int j = 0; j < 18; j++)
		order->client.ID[j] = client.ID[j];
	strcpy_s(order->client.Name, 10, client.Name);
	for (int j = 0; j < 11; j++)
		order->client.Tele[j] = client.Tele[j];
	order->client.Ticket_num = client.Ticket_num;
	order->Order_ID = i;
	order->ticket_num = num;
	for (int i = 0; i < num; i++)
	{
		order->ticket[i].Train_type = train.ticket.tickets[tickets_num[i] - 1].Train_type;
		order->ticket[i].tic_num = train.ticket.tickets[tickets_num[i] - 1].tic_num;
		order->ticket[i].Train_id = train.ticket.tickets[tickets_num[i] - 1].Train_id;
		order->ticket[i].Cap_ID = train.ticket.tickets[tickets_num[i] - 1].Cap_ID;
		order->ticket[i].Price = train.ticket.tickets[tickets_num[i] - 1].Price;
		order->ticket[i].Ticket_State = train.ticket.tickets[tickets_num[i] - 1].Ticket_State;
		order->ticket[i].seat.Seat_ID = train.ticket.tickets[tickets_num[i] - 1].seat.Seat_ID;
		order->ticket[i].seat.Seattype_ID = train.ticket.tickets[tickets_num[i] - 1].seat.Seattype_ID;
		order->ticket[i].Discout = train.ticket.tickets[tickets_num[i] - 1].Discout;
		order->ticket[i].Station_C = (char *)malloc(10 * sizeof (char));
		order->ticket[i].Station_A = (char *)malloc(10 * sizeof (char));
		strcpy_s(order->ticket[i].Station_C, 10, train.ticket.tickets[tickets_num[i] - 1].Station_C);
		strcpy_s(order->ticket[i].Station_A, 10, train.ticket.tickets[tickets_num[i] - 1].Station_A);
	}
	order->next = NULL;
	return order;
}

Order * Dish_Order(Order *head, Order *p)
{
	Order *p1;
	p1 = head;
	if (p1 != NULL)
	{
		if (p != NULL)
		{
			while (p1->next != NULL)
				p1 = p1->next;
			p1->next = p;
			printf("创建订单成功！\n");
		}
		else
			printf("创建订单失败！\n");
	}
	else {
		if (head == NULL && p != NULL)
			head = p;
	}
	return head;
}


Order * book(Train train, int Num, int state)
{
	h = (Order *)malloc(sizeof (Order));
	Order *p;
	if (!InitList_order(&h))
	{
		printf("创建订单链表错误\n");
		return 0;
	}
	int y;
	printf("\n");
	printf("是否预订此车次的票?\n");
	printf("1.订票\n2.返回客户端\n3.返回主菜单\n4.退出\t");
	scanf_s("%d", &y);
	printf("\n");
	if (y == 1)
	{
		char name[10];
		int tele[11], id[18], ticket_num, tickets_num[10];//选择的车票号;

		printf("请输入订票数量：(单人一次最多订10张票)\n");
		scanf_s("%d", &ticket_num);//订票数量

		for (int i = 0; i < ticket_num; i++)
		{
			printf("请输入选择的车票号：");
			scanf_s("%d", &tickets_num[i]);
			printf("\n");
			train.ticket.tickets[tickets_num[i]].Ticket_State = 1;
			printf("车次类型：%c\t车次编号：%d\n", train.ticket.tickets[tickets_num[i]].Train_type, train.ticket.tickets[tickets_num[i]].Train_id);
			printf("您选择的%d号车票\n一站票价为：%d\t折扣为：%1.2f\n座位号为：%d\t座位类型编号为：%c\n",
				tickets_num[i], train.ticket.tickets[tickets_num[i] - 1].Price,
				train.ticket.tickets[tickets_num[i] - 1].Discout, train.ticket.tickets[tickets_num[i] - 1].seat.Seat_ID,
				train.ticket.tickets[tickets_num[i] - 1].seat.Seattype_ID);
			printf("出发站：%s\n", train.ticket.tickets[tickets_num[i] - 1].Station_C);
			Station *q;
			q = train.station;
			int m = 0, n = 0;
			while (q)
			{
				q = q->next;
				if (!strcmp(q->Station_ID, train.ticket.tickets[tickets_num[i] - 1].Station_C))
				{
					printf("出发时间：%d-%d-%d-%d:%d\n"
						, q->time_A.Time_Y, q->time_A.Time_MON, q->time_A.Time_D, q->time_A.Time_H, q->time_A.Time_MIN);
					printf("到达时间：%d-%d-%d-%d:%d\n",
						q->time_C.Time_Y, q->time_C.Time_MON, q->time_C.Time_D, q->time_C.Time_H, q->time_C.Time_MIN);
					break;
				}
				m++;
			}
			printf("到达站：%s\n", train.ticket.tickets[tickets_num[i] - 1].Station_A);
			Station *p;
			p = train.station;
			while (p)
			{
				p = p->next;
				if (!strcmp(p->Station_ID, train.ticket.tickets[tickets_num[i] - 1].Station_A))
				{
					printf("出发时间：%d-%d-%d-%d:%d\n"
						, p->time_A.Time_Y, p->time_A.Time_MON, p->time_A.Time_D, p->time_A.Time_H, p->time_A.Time_MIN);
					printf("到达时间：%d-%d-%d-%d:%d\n",
						p->time_C.Time_Y, p->time_C.Time_MON, p->time_C.Time_D, p->time_C.Time_H, p->time_C.Time_MIN);
					break;
				}
				n++;
			}
			printf("\n沿途大站有:\t");
			for (int u = m; u <= n; u++)
			if (u != n)
				printf("%s->", station_line[Num - 1].Station_ID[u]);
			else printf("%s\t", station_line[Num - 1].Station_ID[u]);
			printf("\n");
		}

		char Yes;
		printf("确定以上信息继续请输入Y\t");
		getchar();
		scanf_s("%c", &Yes);

		if (Yes == 'Y')
		{
			for (int i = 0; i < ticket_num; i++)
				train.ticket.tickets[tickets_num[i] - 1].Ticket_State = 1;
			printf("请输入订票人姓名：\n");
			scanf_s("%s", &name, 10);//strcpy_s(train.ticket.tickets[tickets_num[i]-1].client.Name,10,name);
			for (int i = 0; i < ticket_num; i++)
			for (int j = 0; j < sizeof(name); j++)
				train.ticket.tickets[tickets_num[i] - 1].client.Name[j] = name[j];
			printf("请输入订票人联系方式：输入一个数字后加空格\n");
			for (int l = 0; l < 11; l++)
				scanf_s("%d", &tele[l]);
			for (int i = 0; i < ticket_num; i++)//************
			for (int j = 0; j < 11; j++)
				train.ticket.tickets[tickets_num[i] - 1].client.Tele[j] = tele[j];


			printf("请输入证件号码：每输入一位后加空格\n");
			for (int l = 0; l<18; l++)
				scanf_s("%d", &id[l]);
			for (int i = 0; i < ticket_num; i++)
			{
				for (int j = 0; j < 18; j++)
					train.ticket.tickets[tickets_num[i] - 1].client.ID[j] = id[j];
			}
			Station *sta;
			sta = (Station*)malloc(sizeof(Station));
			sta->next = train.station->next;
			sta = train.station->next;
			printf("沿途大站有：");
			while (sta != NULL)
			{

				printf("%s\t", sta->Station_ID); sta = sta->next;
			}
			printf("\n");

			p = create_one(train.ticket.tickets[tickets_num[0] - 1].client, 1, ticket_num, train, tickets_num);

			for (int r = 0; r < p->ticket_num; r++)
			{
				Station *STA;
				STA = (Station*)malloc(sizeof(Station));
				STA->next = train.station->next;
				STA = train.station->next;
				while (STA != NULL)
				{
					if (!strcmp(STA->Station_ID, p->ticket[r].Station_C))
					{

						p->ticket[r].time_c.Time_Y = STA->time_C.Time_Y;
						p->ticket[r].time_c.Time_MON = STA->time_C.Time_MON;
						p->ticket[r].time_c.Time_D = STA->time_C.Time_D;
						p->ticket[r].time_c.Time_H = STA->time_C.Time_H;
						p->ticket[r].time_c.Time_MIN = STA->time_C.Time_MIN;

						p->ticket[r].time_c.Time_Y = STA->time_A.Time_Y;
						p->ticket[r].time_c.Time_MON = STA->time_A.Time_MON;
						p->ticket[r].time_c.Time_D = STA->time_A.Time_D;
						p->ticket[r].time_c.Time_H = STA->time_A.Time_H;
						p->ticket[r].time_c.Time_MIN = STA->time_A.Time_MIN;

						break;
					}
					STA = STA->next;
				}
				Station *Sta;
				Sta = (Station*)malloc(sizeof(Station));
				Sta->next = train.station->next;
				Sta = train.station->next;
				while (Sta != NULL)
				{
					if (!strcmp(Sta->Station_ID, p->ticket[r].Station_A))
					{

						p->ticket[r].time_a.Time_Y = Sta->time_C.Time_Y;
						p->ticket[r].time_a.Time_MON = Sta->time_C.Time_MON;
						p->ticket[r].time_a.Time_D = Sta->time_C.Time_D;
						p->ticket[r].time_a.Time_H = Sta->time_C.Time_H;
						p->ticket[r].time_a.Time_MIN = Sta->time_C.Time_MIN;

						p->ticket[r].time_a.Time_Y = Sta->time_A.Time_Y;
						p->ticket[r].time_a.Time_MON = Sta->time_A.Time_MON;
						p->ticket[r].time_a.Time_D = Sta->time_A.Time_D;
						p->ticket[r].time_a.Time_H = Sta->time_A.Time_H;
						p->ticket[r].time_a.Time_MIN = Sta->time_A.Time_MIN;

						break;
					}
					Sta = Sta->next;
				}

				int state_C, state_A, j = 0, sta_num = 0, k = 0;
				Station *W;
				W = (Station*)malloc(sizeof(Station));
				W->next = train.station->next;
				W = train.station->next;
				while (W)
				{
					if (!strcmp(W->Station_ID, p->ticket[r].Station_C))
					{
						state_C = 2; state_A = 0;
						j++;
					}
					else if (!strcmp(W->Station_ID, p->ticket[r].Station_A))
					{
						state_A++;
						state_C++;
						k++;
					}
					if (j > 0 && k == 0)
						j++;
					W = W->next;
				}
				if (state_C == 3 && state_A == 1)
				{
					sta_num = j - 1; //满足条件的车次的间隔大站数
				}
				p->ticket[r].station_num = sta_num;
				printf("中间间隔%d站\n", p->ticket[r].station_num);
			}

			Dish_Order(h, p);

			int order_num = 0;
			Order *o;
			o = (Order*)malloc(sizeof(Order));
			o->next = h->next;
			o = h->next;
			while (o != NULL)
			{
				if (!strcmp(name, p->client.Name))
					order_num++;
				o = o->next;
			}

			while (p != NULL)
			{
				printf("\n");
				printf("订单编号为：\t");
				printf("%d\n", p->Order_ID);
				printf("该订单共有%d张票", p->ticket_num);
				printf("\n");

				for (int i = 0; i < p->ticket_num; i++)
				{
					printf("第%d张票信息为：\n", p->ticket[i].tic_num);
					printf("车次类型：%c\t车次号：%d\n", p->ticket[i].Train_type, p->ticket[i].Train_id);
					printf("车厢号：%d\t", p->ticket[i].Cap_ID);
					printf("座位号：%d\t", p->ticket[i].seat.Seat_ID);
					printf("座位类型：%c\t", p->ticket[i].seat.Seattype_ID); printf("\n");
					printf("一站价格：%d\t", p->ticket[i].Price);
					printf("总价格：%d\t", p->ticket[i].Price*p->ticket[i].station_num);
					double P;
					P = p->ticket[i].Price*p->ticket[i].station_num*p->ticket[i].Discout;
					printf("折扣：%1.2f\t", p->ticket[i].Discout);
					p->ticket[i].PRICE = P;
					printf("折后价格为：%4.2f\t", P);
					printf("\n");
					printf("出发站为：%s", p->ticket[i].Station_C);
					printf("\n");
					printf("出发时间为：%d-%d-%d-%d:%d",
						p->ticket[i].time_c.Time_Y, p->ticket[i].time_c.Time_MON, p->ticket[i].time_c.Time_D,
						p->ticket[i].time_c.Time_H, p->ticket[i].time_c.Time_MIN);
					printf("\n");
					printf("到达站为：%s", p->ticket[i].Station_A);
					printf("\n");
					printf("到达时间为：%d-%d-%d-%d：%d",
						p->ticket[i].time_a.Time_Y, p->ticket[i].time_a.Time_MON, p->ticket[i].time_a.Time_D,
						p->ticket[i].time_a.Time_H, p->ticket[i].time_a.Time_MIN);
					printf("\n");
					p->ticket[i].Ticket_State = 1;
				}
				printf("\n");
				printf("客户信息为：\n");
				printf("姓名：%s\t", p->client.Name);
				printf("订单数量：%d\t", order_num);
				printf("\n");
				printf("身份证号为：");
				for (int i = 0; i < 18; i++)
					printf("%d", p->client.ID[i]);
				printf("\n");
				printf("电话号为：");
				for (int i = 0; i < 11; i++)
					printf("%d", p->client.Tele[i]);
				printf("\n");
				p = p->next;
			}
			printf("\n");
			printf("请选择接下来的操作\n1.返回主菜单\n2.返回客户端\n0.退出\t");
			int b;
			scanf_s("%d", &b);
			switch (b)
			{
			case 1:mena(); break;
			case 2:Server(); break;
			default:return h; break;
			}

		}
		else  return h;
	}
	else if (y == 2)Server();
	else if (y == 3)mena();
	else return h;

}

int show_ticket(Train train, int NUM)
{

	printf("请选择一张余票号：\n");
	int i;
	scanf_s("%d", &i);

	i = i - 1;
	printf("详细信息：\n");

	printf("车厢号：%d", train.ticket.tickets[i].Cap_ID);
	printf("座位类型：%c", train.ticket.tickets[i].seat.Seattype_ID);
	if (train.ticket.tickets[i].seat.Seattype_ID == 'S' || train.ticket.tickets[i].seat.Seattype_ID == 'H')
	{
		printf("座位号：%d", train.ticket.tickets[i].seat.Seat_ID);
	}
	printf("经过一站价格：%d", train.ticket.tickets[i].Price);
	printf("折扣：%1.2f", train.ticket.tickets[i].Discout);
	printf("出发站：%s\n", train.ticket.tickets[i].Station_C);
	Station *q;
	q = train.station;
	while (q)
	{
		q = q->next;
		if (!strcmp(q->Station_ID, train.ticket.tickets[i].Station_C))
		{
			printf("出发时间：%d-%d-%d-%d:%d\n"
				, q->time_A.Time_Y, q->time_A.Time_MON, q->time_A.Time_D, q->time_A.Time_H, q->time_A.Time_MIN);
			printf("到达时间：%d-%d-%d-%d:%d\n",
				q->time_C.Time_Y, q->time_C.Time_MON, q->time_C.Time_D, q->time_C.Time_H, q->time_C.Time_MIN);
			break;
		}
	}
	printf("到达站：%s\n", train.ticket.tickets[i].Station_A);
	Station *p;
	p = train.station;
	while (p)
	{
		p = p->next;
		if (!strcmp(p->Station_ID, train.ticket.tickets[i].Station_A))
		{
			printf("出发时间：%d-%d-%d-%d-:%d\n"
				, p->time_A.Time_Y, p->time_A.Time_MON, p->time_A.Time_D, p->time_A.Time_H, p->time_A.Time_MIN);
			printf("到达时间：%d-%d-%d-%d:%d\n",
				p->time_C.Time_Y, p->time_C.Time_MON, p->time_C.Time_D, p->time_C.Time_H, p->time_C.Time_MIN);
			break;
		}
	}
	if (NUM != 0)
	{
		int price = (train.ticket.tickets[i].Price)*(NUM);
		printf("折扣前价格：%d", price);
		double PRICE = (price)* (train.ticket.tickets[i].Discout);
		train.ticket.tickets[i].PRICE = PRICE;
		printf("折扣后总价格：%4.2f", PRICE);
		printf("\n");
	}
	return 0;
}

int SelectStation_Book(Train *train)
{
	char station_idC[10], station_idA[10]; int NUM[10] = { 0 };
	Station_Line station_line;
	printf("请输入出发站及到达站\n");
	printf("出发站：\t");
	scanf_s("%s", &station_idC, 10);
	printf("\t到达站：\t");
	scanf_s("%s", &station_idA, 10);
	printf("可供选择车次编号有：");
	int state_C = 0, state_A = 0;
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
				if (j > 0 && k == 0)  j++;
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
	printf("请选择其中一个车次编号查询\n");
	scanf_s("%d", &station_id);
	printf("%d", NUM[station_id]);
	SelectTrain_Book(train[station_id - 1], NUM[station_id - 1], station_id, station_idC, station_idA, 1);
	return station_id;
}

Order * SelectTrain_Book(Train train, int NUM, int station_id, char *idc, char *ida, int state)
{
	//Order *h;
	int j = 0, i = 1;

	for (int k = 0; k < train.ticket.Tickets_Num; k++)
	{
		if (train.ticket.tickets[k].Ticket_State == 0)
		{
			if (state == 1)
			{
				if (!strcmp(train.ticket.tickets[k].Station_C, idc) && !strcmp(train.ticket.tickets[k].Station_A, ida))
				{
					printf("剩余车票号：");
					printf("%d\t", k + 1);
					printf("座位类型：%c\t", train.ticket.tickets[k].seat.Seattype_ID);
					printf("座位号：:\t");
					printf("%d\t", train.ticket.tickets[k].seat.Seat_ID);
					printf("\n");
					printf("出发站：%s\n", train.ticket.tickets[i].Station_C);
					Station *q;
					q = train.station;
					while (q)
					{
						q = q->next;
						if (!strcmp(q->Station_ID, train.ticket.tickets[i].Station_C))
						{
							printf("到达时间：%d-%d-%d-%d:%d\n",
								q->time_C.Time_Y, q->time_C.Time_MON, q->time_C.Time_D, q->time_C.Time_H, q->time_C.Time_MIN);
							printf("出发时间：%d-%d-%d-%d:%d\n"
								, q->time_A.Time_Y, q->time_A.Time_MON, q->time_A.Time_D, q->time_A.Time_H, q->time_A.Time_MIN);
							break;
						}
					}
					printf("到达站：%s\n", train.ticket.tickets[i].Station_A);
					Station *p;
					p = train.station;
					while (p)
					{
						p = p->next;
						if (!strcmp(p->Station_ID, train.ticket.tickets[i].Station_A))
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
					if (!strcmp(q->Station_ID, train.ticket.tickets[i].Station_C))
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
					if (!strcmp(p->Station_ID, train.ticket.tickets[i].Station_A))
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
	}

	if (j == 0)
	{

		printf("该车次没有剩余车票，请选择其他可供选择车次：\n");
		return h;
	}
	else{
		for (int c = 0; c < 4; c++)
		{
			printf("是否继续查询车票信息，继续请输入Y\t");
			char O; getchar();
			scanf_s("%c", &O);
			if (O == 'Y')
				show_ticket(train, NUM);
			else break;
		}
	}
	getchar();
	h = book(train, station_id, state);
	return h;
}
//返回的为订单链表头结点

Order* ORDER(){
	printf("请输入要进行的操作编号：1.通过查询车站订票 2.通过查询车次剩余车票订票");
	int i, num = 0; Order *j;	int id;
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:SelectStation_Book(train); break;
	case 2:{
			   printf("可查询车次为：\t");
			   for (int m = 0; m < 10; m++)
			   if (train[m].train_state == 1)
				   printf("%d\t", m + 1);
			   printf("\n请输入查询车次：\t");
			   scanf_s("%d", &id);
			   j = SelectTrain_Book(train[id - 1], num, id, NULL, NULL, 0);
			   if (j == NULL)
			   {
				   printf("请输入要查询车次编号");
				   scanf_s("%d", &id);
				   SelectTrain_Book(train[id - 1], num, id, NULL, NULL, 0);
			   }
			   break;
	}
	default:break;
	}
	return h;
}


#include <stdio.h>
#include <malloc.h>
#pragma once
#define SeatMax 100
#ifndef _TEST_H
#define _TEST_H


/*****************ʱ��**********************/
typedef struct Time {
    int Time_Y;
	int Time_MON;
	int Time_D;
	int Time_H;
	int Time_MIN;
}Time;

/*************;����Ҫ��վ******************/


typedef struct Station{
    char *Station_ID;      //վ̨���
    Time time_C;
	Time time_A;
	int time;
struct Station *next;
}Station;

/************����;����վ���Ա�************/



typedef  struct Station_Line{
	  char* Station_ID[10];      //վ̨���
    Time time_C[10];
	Time time_A[10];
	int time[10];
}Station_Line;

 Station_Line station_line[10];

/******************��λ*********************/

 typedef struct Seat{
	int Seat_ID;           //��λ��
	char Seattype_ID;       //��λ���� ���̣�berth Ӳ����hardseat ������softseat վƱ��stand
 }Seat;


/****************�ͻ�����********************/


 typedef struct Client{
	char Name[10];      //����
	int ID[18];         //���֤��
	int Ticket_num;     //��������
	int  Order[10];      //�������
	int Tele[11];       //��ϵ��ʽ
 }Client;


/*****************��Ʊ��Ϣ********************/


typedef struct Ticket{
			Client client;      //�ͻ�����
			int tic_num;
			char Train_type;
			int Train_id;
			int Price;          //�۸�
			double PRICE;
			double Discout;        //�ۿ�
			Seat seat;          //��λ{��λ�ţ���λ����}
			int Cap_ID;         //�����
			char *Station_C;
			Time time_c;
			Time time_a;
			int station_num;
			char *Station_A;
			int Station_State;
			int Ticket_State;   //1 ���� 0 ����
}Ticket;


/***************��Ʊ******************/

typedef struct Tickets{
	Ticket *tickets;     //���г�Ʊ
	int Tickets_Num;
	int stand_num;
	int soft_num;
	int hard_num;
	int lie_num;
}Tickets;

/******************������Ϣ****************/

typedef struct Train{
	int Train_ID;           //���α��
	char Traintype_ID;      //��������
	Tickets ticket;         //�������г�Ʊ
	Time Time_C;            //����ʱ��
	Time Time_A;            //����ʱ��
	char CStation[6];        //����վ���
	char AStation[6];        //����վ���
	Station* station;        //;����Ҫ��վ
	int Cap_num;            //������
	int Seat_num;           //ÿ�ڳ�����λ��
	int train_state;
}Train;
Train train[10];



/*****************�����ṹ��****************/
typedef struct Order {
	int Order_ID;        //�������
	Ticket ticket[10];   //��Ʊ
	int ticket_num;
	Client client;
	int state;//ͨ����վ����Ϊ1���ζ���Ϊ0
	struct Order *next;
}Order;


/*****************����********************/
void load(Train *train, int Num);
int traver_station(Station* q, int num);
int Server();
int mena();
Train LOAD_1();
Order *return_order(Order *head);
Order * SelectTrain_Book(Train train, int NUM, int station_id, char *idc, char *ida, int state);
Order *h;
#endif
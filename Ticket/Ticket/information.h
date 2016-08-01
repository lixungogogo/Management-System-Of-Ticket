#include <stdio.h>
#include <malloc.h>
#pragma once
#define SeatMax 100
#ifndef _TEST_H
#define _TEST_H


/*****************时间**********************/
typedef struct Time {
    int Time_Y;
	int Time_MON;
	int Time_D;
	int Time_H;
	int Time_MIN;
}Time;

/*************途径主要大站******************/


typedef struct Station{
    char *Station_ID;      //站台编号
    Time time_C;
	Time time_A;
	int time;
struct Station *next;
}Station;

/************车次途径大站线性表************/



typedef  struct Station_Line{
	  char* Station_ID[10];      //站台编号
    Time time_C[10];
	Time time_A[10];
	int time[10];
}Station_Line;

 Station_Line station_line[10];

/******************座位*********************/

 typedef struct Seat{
	int Seat_ID;           //座位号
	char Seattype_ID;       //座位类型 卧铺：berth 硬座：hardseat 软座：softseat 站票：stand
 }Seat;


/****************客户资料********************/


 typedef struct Client{
	char Name[10];      //姓名
	int ID[18];         //身份证号
	int Ticket_num;     //订单数量
	int  Order[10];      //订单编号
	int Tele[11];       //联系方式
 }Client;


/*****************车票信息********************/


typedef struct Ticket{
			Client client;      //客户资料
			int tic_num;
			char Train_type;
			int Train_id;
			int Price;          //价格
			double PRICE;
			double Discout;        //折扣
			Seat seat;          //座位{座位号，座位类型}
			int Cap_ID;         //车厢号
			char *Station_C;
			Time time_c;
			Time time_a;
			int station_num;
			char *Station_A;
			int Station_State;
			int Ticket_State;   //1 有人 0 无人
}Ticket;


/***************车票******************/

typedef struct Tickets{
	Ticket *tickets;     //所有车票
	int Tickets_Num;
	int stand_num;
	int soft_num;
	int hard_num;
	int lie_num;
}Tickets;

/******************车次信息****************/

typedef struct Train{
	int Train_ID;           //车次编号
	char Traintype_ID;      //车次类型
	Tickets ticket;         //车次所有车票
	Time Time_C;            //出发时间
	Time Time_A;            //到达时间
	char CStation[6];        //出发站编号
	char AStation[6];        //到达站编号
	Station* station;        //途径主要大站
	int Cap_num;            //车厢数
	int Seat_num;           //每节车厢座位数
	int train_state;
}Train;
Train train[10];



/*****************订单结构体****************/
typedef struct Order {
	int Order_ID;        //订单编号
	Ticket ticket[10];   //车票
	int ticket_num;
	Client client;
	int state;//通过车站订单为1车次订单为0
	struct Order *next;
}Order;


/*****************声明********************/
void load(Train *train, int Num);
int traver_station(Station* q, int num);
int Server();
int mena();
Train LOAD_1();
Order *return_order(Order *head);
Order * SelectTrain_Book(Train train, int NUM, int station_id, char *idc, char *ida, int state);
Order *h;
#endif
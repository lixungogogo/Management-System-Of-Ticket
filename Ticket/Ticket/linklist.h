/* ******* 单链表的基本操作*******/
#pragma once
#include <stdio.h>
#include "malloc.h"
#include "information.h"
#include <string.h>

typedef Station LNode, *PNode, *LinkList, Station_List;

int InitList(Station* *h);
int ListInsert_station(Station* h, int pos, char *station_id, Time c, Time a, int time);
int InitList_order(Order* *h);
int ListInsert_order(Order* h, int pos, int order_id);
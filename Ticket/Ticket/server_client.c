#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "linklist.h"
#include <malloc.h>
#include <string.h>

int Admin()
{
	printf("您已进入管理端\n");
	printf("1.手动录入车次信息\n");
	printf("0.返回主菜单\n");
	int a;
	printf("Input 0-1:");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1: LOAD(); break;
	case 0:
		mena(); break;
	default: printf("The number is not in 0-2!\n"); getchar(); break;
	}
	return 0;
}


int Server()
{
	printf("您已进入客户端\n");
	int a;
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * *              1.查询                       * *\n");
	printf(" * *              2.订票                       * *\n");
	printf(" * *              3.退票                       * *\n");
	printf(" * *              4.返回主菜单                 * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * *                                           * *\n");
	printf(" * *              0.退出                       * *\n");
	printf(" * *                                           * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");

	printf("Input 0-4:");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1: SELECT(); break;
	case 2: h = ORDER(); break;
	case 3: RETURN(h); break;
	case 4:mena(); break;
	case 0:
		printf("* * * * * * * * * * * * * * * * * * *  * *\n");
		printf("*                                       *\n");
		printf("*           Thanks for using            *\n");
		printf("*                                       *\n");
		printf("* * * * * * * * * * * * * * * * * * *  * *\n");
		exit(0); break;
	default: printf("The number is not in 0-4!\n"); getchar(); break;
	}
	return 0;
}

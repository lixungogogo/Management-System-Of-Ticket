#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "linklist.h"
#include <malloc.h>
#include <string.h>

int Admin()
{
	printf("���ѽ�������\n");
	printf("1.�ֶ�¼�복����Ϣ\n");
	printf("0.�������˵�\n");
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
	printf("���ѽ���ͻ���\n");
	int a;
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * *              1.��ѯ                       * *\n");
	printf(" * *              2.��Ʊ                       * *\n");
	printf(" * *              3.��Ʊ                       * *\n");
	printf(" * *              4.�������˵�                 * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * *                                           * *\n");
	printf(" * *              0.�˳�                       * *\n");
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

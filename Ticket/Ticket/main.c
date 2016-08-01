#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "linklist.h"
#include "malloc.h"
#include <string.h>

#define G 高铁
#define D 动车
#define Z 直达
#define T 特快
#define K 快速


int mena()
{
	int a,b;
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * *            欢迎使用火车票管理系统         * *\n");
	printf(" * *              1.管理端                     * *\n");
	printf(" * *              2.客户端                     * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * *                                           * *\n");
	printf(" * *              0.退出                       * *\n");
	printf(" * *                                           * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("Input 0-2:");
	scanf_s("%d",&a);
	switch (a)
	{
		case 1:
			b = Admin();
			while ( b == 0 )
				b = Admin();
			break;
		case 2: 
			b = Server();
			while (b == 0 )
				b = Server();
			break;
		case 0:
				printf("* * * * * * * * * * * * * * * * * * *  * *\n");
				printf("*                                       *\n");
				printf("*           Thanks for using            *\n");
				printf("*                                       *\n");
				printf("* * * * * * * * * * * * * * * * * * *  * *\n");
				exit(0);break;
		default: printf("The number is not in 0-2!\n");getchar();break;
	}
	return 0;
}

int main()
{
    train[0] = LOAD_1();
	int i = 0;
    i = mena();
	while ( i == 0 )
		i = mena();
    getchar();
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include <stdlib.h>
#include "information.h"
#include "linklist.h"
#include "malloc.h"
#include <string.h>

#define G ����
#define D ����
#define Z ֱ��
#define T �ؿ�
#define K ����


int mena()
{
	int a,b;
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * *            ��ӭʹ�û�Ʊ����ϵͳ         * *\n");
	printf(" * *              1.�����                     * *\n");
	printf(" * *              2.�ͻ���                     * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" * *                                           * *\n");
	printf(" * *              0.�˳�                       * *\n");
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

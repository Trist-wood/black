#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("*****************************\n");
	printf("****   1.play 	0.exit   ****\n");
	printf("*****************************\n");
}

void game()
{
	//1.生成一个随机数
//时间戳
	int guess = 0;
	int ret = rand() % 100 + 1;//生成1-100的随机数
	while (1)
	{
		printf("请猜数字：>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜对了\n");
			break;
		}
	}
	//2.猜数字

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//数字游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}

#include "Game.h"


void menu()
{
	printf("******************************\n");
	printf("*****  1.paly    0.exit  *****\n");
	printf("******************************\n");
}

void game()
{
	char ret = 0;
	srand((unsigned int)time(NULL));//随机数
	char board[ROW][COL] = { 0 };//创建ROW行，COL列的数组
	Initboard(board, ROW, COL);//界面初始化
	Display(board, ROW, COL);//打印界面
	while (1)
	{
		Playermove(board, ROW, COL);//玩家移动
		ret = Iswin(board, ROW, COL);//判断输赢：‘O’玩家赢，‘X’电脑赢，‘D’平局，‘C’继续
		if (ret != 'C')
		{
			break;
		}
		Display(board, ROW, COL);//打印界面
		Computermove(board, ROW, COL);//电脑移动
		ret = Iswin(board, ROW, COL);//判断输赢
		if (ret != 'C')
		{
			break;
		}
		Display(board, ROW, COL);//打印界面
	}
	if (ret == 'O')
	{
		printf("玩家赢\n");
	}
	else if (ret == 'X')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
	Display(board, ROW, COL);
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择》：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重选!");
			break;
		}
	} while (input);
}



int main()
{
	test();
	return 0;
}
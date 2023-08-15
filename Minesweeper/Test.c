//函数主体
#include "game.h"
#include <stdio.h>


menu()
{
	printf("*******************************\n");
	printf("******      1.Play       ******\n");
	printf("******      0.Exit       ******\n");
	printf("*******************************\n");
}

void game()
{
	//雷的信息储存
	//1.布置雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2.展示雷的信息
	char show[ROWS][COLS] = { 0 };
	//扫雷初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');//初始化为'0'和'*'
	//打印界面
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
}

void test()
{

	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
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
			printf("输入错误，请重新选择：");
			break;
		}
	} while (input);

}


int main()
{
	test();
	return 0;
}
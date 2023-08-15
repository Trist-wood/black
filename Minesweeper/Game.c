//函数定义
#include "game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	//这里打印上面一行数字
	printf("|");
	for (j = 0; j <= col; j++)
	{
		printf(" %-2d |", j);
	}
	printf("\n");


	for (i = 1; i <= row; i++)
	{
		printf("|");
		for (j = 0; j <= col; j++)
		{
			printf("----|");//打印两行之间的分割线
		}
		printf("\n");

		printf("|");
		printf(" %-2d |", i);//打印左边一列数字

		for (j = 1; j <= col; j++)
		{
			printf(" %2c |", board[i][j]);//打印show数组

		}
		printf("\n");
	}

}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int win)
{

	if (x >= 1 && x <= ROW && y >= 1 && y <= COL) //限制在棋盘内展开，防止越界
	{
		int count = get_mine_count(mine, x, y);//获取雷数

		if (count == 0) //四周没雷，进入递归展开
		{
			show[x][y] = ' ';//四周没雷的改为 空格  ' '


			int i = 0;
			//向四周共8个位置递归
			for (i = x - 1; i <= x + 1; i++)
			{
				int j = 0;
				for (j = y - 1; j <= y + 1; j++)
				{

					//只对 '*' 进行展开，防止死循环
					if (show[i][j] == '*')
					{
						expand(mine, show, i, j, win);
					}

				}
			}
		}
		else   //四周有雷显示雷数
		{
			show[x][y] = count + '0';
		}

		//记录展开的数量
		win++;
	}
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//踩雷
			if (mine[x][y] == '1')
			{
				printf("你踩雷了，被炸死\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			//不踩雷
			else
			{
				//递归：1，不踩雷  2.周围不是雷
				expand(mine, show, x, y, win);
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("坐标错误，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你,排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}
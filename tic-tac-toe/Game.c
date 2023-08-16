#include "Game.h"


void Initboard(char board[ROW][COL], int row, int col)//界面初始化
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Display(char board[ROW][COL], int row, int col)//打印界面
{
	//   |   |   
	//---|---|---

	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);//打印一行数据
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}

	}

}


void Playermove(char board[ROW][COL], int row, int col)//玩家移动
{
	//是否超出棋盘范围
	//打印相应坐标
	int x = 0;
	int y = 0;
	printf("玩家：\n");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
			{
				printf("坐标被占用，请重选：\n");
			}
		}
		else
		{
			printf("超出范围，请重新输入>:\n");
		}
	}

}

void Computermove(char board[ROW][COL], int row, int col)//电脑移动
{
	int x = 0;
	int y = 0;
	printf("电脑：\n");
	while (1)
	{
		x = rand() % row;//0~2
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'X';
			break;
		}
	}
}


//满了 返回 1
//没满 返回 0
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char Iswin(char board[ROW][COL], int row, int col)//判断输赢
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}

	for (j = 0; j < col; j++)
	{

		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][1] && board[0][2] != ' ')
	{
		return board[0][2];
	}

	//没有人赢，平局
	if (IsFull(board, row, col))
	{
		return 'D';//1
	}
	return 'C';//0
}
#include "Game.h"


void Initboard(char board[ROW][COL], int row, int col)//�����ʼ��
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

void Display(char board[ROW][COL], int row, int col)//��ӡ����
{
	//   |   |   
	//---|---|---

	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);//��ӡһ������
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//��ӡ�ָ���
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


void Playermove(char board[ROW][COL], int row, int col)//����ƶ�
{
	//�Ƿ񳬳����̷�Χ
	//��ӡ��Ӧ����
	int x = 0;
	int y = 0;
	printf("��ң�\n");
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
				printf("���걻ռ�ã�����ѡ��\n");
			}
		}
		else
		{
			printf("������Χ������������>:\n");
		}
	}

}

void Computermove(char board[ROW][COL], int row, int col)//�����ƶ�
{
	int x = 0;
	int y = 0;
	printf("���ԣ�\n");
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


//���� ���� 1
//û�� ���� 0
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

char Iswin(char board[ROW][COL], int row, int col)//�ж���Ӯ
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
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][1] && board[0][2] != ' ')
	{
		return board[0][2];
	}

	//û����Ӯ��ƽ��
	if (IsFull(board, row, col))
	{
		return 'D';//1
	}
	return 'C';//0
}
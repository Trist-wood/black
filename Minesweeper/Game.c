//��������
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

	//�����ӡ����һ������
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
			printf("----|");//��ӡ����֮��ķָ���
		}
		printf("\n");

		printf("|");
		printf(" %-2d |", i);//��ӡ���һ������

		for (j = 1; j <= col; j++)
		{
			printf(" %2c |", board[i][j]);//��ӡshow����

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

	if (x >= 1 && x <= ROW && y >= 1 && y <= COL) //������������չ������ֹԽ��
	{
		int count = get_mine_count(mine, x, y);//��ȡ����

		if (count == 0) //����û�ף�����ݹ�չ��
		{
			show[x][y] = ' ';//����û�׵ĸ�Ϊ �ո�  ' '


			int i = 0;
			//�����ܹ�8��λ�õݹ�
			for (i = x - 1; i <= x + 1; i++)
			{
				int j = 0;
				for (j = y - 1; j <= y + 1; j++)
				{

					//ֻ�� '*' ����չ������ֹ��ѭ��
					if (show[i][j] == '*')
					{
						expand(mine, show, i, j, win);
					}

				}
			}
		}
		else   //����������ʾ����
		{
			show[x][y] = count + '0';
		}

		//��¼չ��������
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
		printf("���������꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����
			if (mine[x][y] == '1')
			{
				printf("������ˣ���ը��\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			//������
			else
			{
				//�ݹ飺1��������  2.��Χ������
				expand(mine, show, x, y, win);
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("�����������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ��,���׳ɹ�\n");
		DisplayBoard(mine, ROW, COL);
	}
}

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
	srand((unsigned int)time(NULL));//�����
	char board[ROW][COL] = { 0 };//����ROW�У�COL�е�����
	Initboard(board, ROW, COL);//�����ʼ��
	Display(board, ROW, COL);//��ӡ����
	while (1)
	{
		Playermove(board, ROW, COL);//����ƶ�
		ret = Iswin(board, ROW, COL);//�ж���Ӯ����O�����Ӯ����X������Ӯ����D��ƽ�֣���C������
		if (ret != 'C')
		{
			break;
		}
		Display(board, ROW, COL);//��ӡ����
		Computermove(board, ROW, COL);//�����ƶ�
		ret = Iswin(board, ROW, COL);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
		Display(board, ROW, COL);//��ӡ����
	}
	if (ret == 'O')
	{
		printf("���Ӯ\n");
	}
	else if (ret == 'X')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	Display(board, ROW, COL);
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ�񡷣�\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ!");
			break;
		}
	} while (input);
}



int main()
{
	test();
	return 0;
}
//��������
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
	//�׵���Ϣ����
	//1.�����׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//2.չʾ�׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//ɨ�׳�ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');//��ʼ��Ϊ'0'��'*'
	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//����
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//ɨ��
	FindMine(mine, show, ROW, COL);
}

void test()
{

	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
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
			printf("�������������ѡ��");
			break;
		}
	} while (input);

}


int main()
{
	test();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct Stu
{
	char name[20];//����
	int age;//����
	char sex[10];//�Ա�

};

typedef struct Node//�ṹ��������
{
	int date;
	struct Node* next;
}Node;

int main()
{
	struct Stu s2;
	//�ṹ���ʼ��
	struct Stu s1 = { "����",23,"��" };
	printf("%s %d\n", s1.name, s1.age);

	return 0;
}


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
	char password[20] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("���������룺");
		scanf("%s", &password);
		if (strcmp(password, "123456") == 0)
		{
			printf("����ɹ�\n");
			break;
		}
		else
		{
			printf("���������������������:\n");
		}
	}
	if (i == 3)
	{
		printf("��������������˳�����\n");
	}
	return 0;
}


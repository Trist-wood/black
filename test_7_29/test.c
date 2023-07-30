#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//enum Sex
//{
//	Male,
//	Female,
//	Secret
//};
//
//enum Color
//{
//	Red,
//	Green,
//	Blue
//};
//
//int main()
//{
//	enum Sex s = Male;
//	enum Color c = Blue;
//
//
//	return 0;
//}



//联合体

//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union Un u;
//	printf("%d\n", sizeof(u));
//
//	return 0;
//}

int check_sys()
{
	/*int a = 1;
	return *(char*)&a;*/

	union Un
	{
		char c;
		int i;
	}u;
	u.i = 1;
	return u.c;//返回1，小端；返回0，大端
}

int main()
{
	int a = 1;
	int ret = check_sys();
	if (1 == ret)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
}


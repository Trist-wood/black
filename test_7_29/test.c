#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct Stu
{
	char name[20];//名字
	int age;//年龄
	char sex[10];//性别

};

typedef struct Node//结构体自引用
{
	int date;
	struct Node* next;
}Node;

int main()
{
	struct Stu s2;
	//结构体初始化
	struct Stu s1 = { "张三",23,"男" };
	printf("%s %d\n", s1.name, s1.age);

	return 0;
}


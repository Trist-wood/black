#pragma once
#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3


enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT,//6
	SAVE//7
};

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};


//通讯录类型
struct Contact
{
	int size;//记录当前已经有的元素个数
	int capacity;//当前容量
	struct PeoInfo* data;//存放信息
};

//函数声明
//通讯录初始化
void InitContact(struct Contact* ps);

//增加用户信息
void AddContact(struct Contact* ps);

//打印用户信息
void ShowContact(const struct Contact* ps);

//删除指定用户信息
void DelContact(struct Contact* ps);

//查找用户信息
void SearchContact(const struct Contact* ps);

//修改用户信息
void ModifyContact(struct Contact* ps);

//排序用户信息
void SortContact(struct Contact* ps);

//释放动态开辟的空间
void realseContact(struct Contact* ps);

//保存文件信息
void saveContact(struct Contact* ps);

//加载文件信息到通讯录
void LoadContact(struct Contact* ps);
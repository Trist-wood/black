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


//ͨѶ¼����
struct Contact
{
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
	int capacity;//��ǰ����
	struct PeoInfo* data;//�����Ϣ
};

//��������
//ͨѶ¼��ʼ��
void InitContact(struct Contact* ps);

//�����û���Ϣ
void AddContact(struct Contact* ps);

//��ӡ�û���Ϣ
void ShowContact(const struct Contact* ps);

//ɾ��ָ���û���Ϣ
void DelContact(struct Contact* ps);

//�����û���Ϣ
void SearchContact(const struct Contact* ps);

//�޸��û���Ϣ
void ModifyContact(struct Contact* ps);

//�����û���Ϣ
void SortContact(struct Contact* ps);

//�ͷŶ�̬���ٵĿռ�
void realseContact(struct Contact* ps);

//�����ļ���Ϣ
void saveContact(struct Contact* ps);

//�����ļ���Ϣ��ͨѶ¼
void LoadContact(struct Contact* ps);
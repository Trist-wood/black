#include "contact.h"


void InitContact(struct Contact* ps)
{
		ps->data = (struct  PeoInfo*)malloc(3 * sizeof(struct  PeoInfo));
		if (ps->data == NULL)
		{
			return;
		}
		ps->size = 0;//����ͨѶ¼��ʼֻ��0��Ԫ��
		ps->capacity = DEFAULT_SZ;//��ʼ��Ϊ����Ϊ3
		//���ļ��д�ŵ�ͨ��¼�е���Ϣ���ص�ͨѶ¼��
		LoadContact(ps);
}



void CheckCapacity(struct Contact* ps)
{
	if (ps->capacity == ps->size)
	{
		//����
		struct  PeoInfo* ptr=realloc(ps->data, (ps->capacity + 2) * sizeof(struct  PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}

	}

}

void AddContact(struct Contact* ps)
{
		
		//��⵱ǰ����
	//1.����������ӿռ�
	//2.������ɶҲ����
		CheckCapacity(ps);
		//��������
		printf("���������֣�\n");
		scanf("%s", ps->data[ps->size].name);
		printf("���������䣺\n");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰��\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ��\n");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("��ӳɹ�\n");
}



void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		//����
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
		//����
		for (i = 0; i < ps->size; i++)
		{
			printf(" % -20s\t % -4d\t % -5s\t % -12s\t % -20s\n",ps->data[i].name,
			    ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

static int FindByname(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;//�Ҳ��������
}



void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������ɾ���˵����֣�");
	scanf("%s", name);
	//1.����Ҫɾ��������ʲôλ��
	//�ҵ������±�
	//�Ҳ�������-1
	int pos = FindByname(ps, name);
	if (-1 == pos)
	{
		printf("���˲�����\n");
	}
	
	//2.ɾ��
	else if (pos == ps->size)
	{
		printf("��Ҫɾ�����˲�����\n");
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j <ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
	
}



void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("����������˵�����\n");
	scanf("%s", name);
    int pos = FindByname(ps, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf(" % -20s\t % -4d\t % -5s\t % -12s\t % -20s\n", ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}

}



void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("�������޸��û���\n");
	scanf("%s", name);
	int pos = FindByname(ps, name);
	if (pos == -1)
	{
		printf("�û�������\n");
	}
	else
	{
		printf("���������֣�\n");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺\n");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�\n");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��\n");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��\n");
		scanf("%s", ps->data[pos].addr);

		printf("�޸����\n");
	}

}


int cmp(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}

void SortContact(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(struct PeoInfo), cmp);
	printf("�������\n");
}

void realseContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}


void saveContact(struct Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("saveContact:%s\n", strerror(errno));
		return;
	}
	//дͨѶ¼�����ݵ��ļ���
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
	printf("����ɹ�\n");
}


void CheckCapacity(struct Contact* ps);

void LoadContact(struct Contact* ps)
{
	struct PeoInfo tmp = { 0 };
	FILE* pfread = fopen("contact.dat", "rb");
	if (pfread == NULL)
	{
		printf("LoadContact:%s\n", strerror(errno));
		return;
	}
	//��ȡ�ļ�����ŵ�ͨѶ¼��
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfread))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	printf("�������\n");

	fclose(pfread);
	pfread = NULL;
}
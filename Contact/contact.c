#include "contact.h"


void InitContact(struct Contact* ps)
{
		ps->data = (struct  PeoInfo*)malloc(3 * sizeof(struct  PeoInfo));
		if (ps->data == NULL)
		{
			return;
		}
		ps->size = 0;//设置通讯录初始只有0个元素
		ps->capacity = DEFAULT_SZ;//初始化为容量为3
		//把文件中存放的通信录中的信息加载到通讯录中
		LoadContact(ps);
}



void CheckCapacity(struct Contact* ps)
{
	if (ps->capacity == ps->size)
	{
		//增容
		struct  PeoInfo* ptr=realloc(ps->data, (ps->capacity + 2) * sizeof(struct  PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}

	}

}

void AddContact(struct Contact* ps)
{
		
		//检测当前容量
	//1.如果满，增加空间
	//2.不满，啥也不干
		CheckCapacity(ps);
		//增加数量
		printf("请输入名字：\n");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄：\n");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别：\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话：\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址：\n");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("添加成功\n");
}



void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		//标题
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
		//数据
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
	return -1;//找不到的情况
}



void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入删除人的名字：");
	scanf("%s", name);
	//1.查找要删除的人在什么位置
	//找到返回下标
	//找不到返回-1
	int pos = FindByname(ps, name);
	if (-1 == pos)
	{
		printf("此人不存在\n");
	}
	
	//2.删除
	else if (pos == ps->size)
	{
		printf("你要删除的人不存在\n");
	}
	else
	{
		//删除数据
		int j = 0;
		for (j = pos; j <ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
	
}



void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入查找人的名字\n");
	scanf("%s", name);
    int pos = FindByname(ps, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
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
	printf("请输入修改用户名\n");
	scanf("%s", name);
	int pos = FindByname(ps, name);
	if (pos == -1)
	{
		printf("用户不存在\n");
	}
	else
	{
		printf("请输入名字：\n");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄：\n");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别：\n");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话：\n");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址：\n");
		scanf("%s", ps->data[pos].addr);

		printf("修改完成\n");
	}

}


int cmp(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}

void SortContact(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(struct PeoInfo), cmp);
	printf("排序完成\n");
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
	//写通讯录的数据到文件中
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
	printf("保存成功\n");
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
	//读取文件，存放到通讯录中
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfread))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	printf("加载完成\n");

	fclose(pfread);
	pfread = NULL;
}
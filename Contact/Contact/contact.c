#include"contact.h"

//初始化通讯录
void InitContact(Contact* ps)
{
	ps->data = (PeoInFo *)calloc(DEFAULT_SZ, sizeof(PeoInFo));
	if (ps->data == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	//把文件中存放的信息加载到通讯录
	LoadContact(ps);

}

void LoadContact(Contact* ps)
{
	PeoInFo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//读取文件，放到通讯录中
	while (fread(&tmp, sizeof(PeoInFo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}

	fclose(pfRead);
	pfRead = NULL;
}

void CheckCapacity(Contact* ps)
{
	//每次扩容双倍
	if (ps->size == ps->capacity)
	{
		struct PeoInFo* ptr = realloc(ps->data, (ps->capacity * 2) * sizeof(struct PeoInFo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity *= 2;
			printf("扩容成功！\n");
		}
	}
}

//1.添加联系人信息
void AddContact(Contact* ps)
{
	assert(ps != NULL);
	//检测通讯录容量，如果满了就增加空间
	CheckCapacity(ps);
	//添加信息
	printf("请输入姓名：>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄：>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别：>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话：>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入住址：>");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	printf("添加成功！\n");

}

//查找联系人姓名
static int FindByName(const Contact* ps, char* name)
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
			return i;
	}

	return -1;//未找到返回-1
}

//2.删除联系人信息
void DelContact(Contact* ps)
{
	assert(ps != NULL);
	char name[MAX_NAME];

	if (ps->size == 0)
	{
		printf("通讯录为空，无法删除信息！\n");
		return;
	}
	printf("请输入要删除的人姓名：>");
	scanf("%s", name);

	//寻找
	int pos = FindByName(ps, name);
	//删除
	if (pos == -1)
	{
		printf("查无此人！\n");
	}
	else
	{
		for (int j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功！\n");
	}
}

//3.查询联系人信息
void SearchContact(const Contact* ps)
{
	assert(ps != NULL);
	char name[MAX_NAME];

	if (ps->size == 0)
	{
		printf("通讯录为空！\n");
		return;
	}
	printf("请输入要查询的人姓名：>");
	scanf("%s", name);
	
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("查无此人！\n");
	}
	else
	{
		printf("%-20s\t%-3s\t%-5s\t%-12s\t%-10s\t\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-3d\t%-5s\t%-12s\t%-10s\t\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

//4.修改联系人信息
void ModifyContact(Contact* ps)
{
	assert(ps != NULL);
	char name[MAX_NAME];

	if (ps->size == 0)
	{
		printf("通讯录为空，无法修改信息！\n");
		return;
	}

	printf("请输入要修改的人姓名：>");
	scanf("%s", name);

	//寻找
	int pos = FindByName(ps, name);
	//修改
	if (pos == -1)
	{
		printf("查无此人！\n");
		return;
	}
	else
	{
		printf("请输入要修改的信息：1-名字\t2-年龄\t3-性别\t4-电话\t5-住址:>");
		int msg;
		scanf("%d", &msg);
		switch (msg)
		{
		case 1:
			printf("请输入修改后姓名:>");
			scanf("%s", ps->data[pos].name);
			break;
		case 2:
			printf("请输入修改后年龄:>");
			scanf("%d", &ps->data[pos].age);
			break;
		case 3:
			printf("请输入修改后性别:>");
			scanf("%s", ps->data[pos].sex);
			break;
		case 4:
			printf("请输入修改后电话:>");
			scanf("%s", ps->data[pos].tele);
			break;
		case 5:
			printf("请输入修改后地址:>");
			scanf("%s", ps->data[pos].addr);
			break;
		default:
			printf("输入有误，修改失败\n");
			return;
		}
		printf("修改成功！\n");
	}
}

//5.显示联系人信息
void ShowContact(const Contact* ps)
{
	assert(ps != NULL);
	if (ps->size == 0)
	{
		printf("通讯录为空！\n");
	}
	else
	{
		printf("%-20s\t%-3s\t%-5s\t%-12s\t%-10s\t\n", "姓名", "年龄", "性别", "电话", "住址");
		for (int i = 0; i < ps->size;  i++)
		{
			printf("%-20s\t%-3d\t%-5s\t%-12s\t%-10s\t\n", 
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//6.排序联系人信息
void SortContact(Contact* ps)
{
	assert(ps != NULL);
	int i, j;
	struct PeoInFo tmp;

	if (ps->size == 0)
	{
		printf("通讯录为空!\n");
		return;
	}
	//排序
	for (i = 0; i < ps->size - 1; i++)
	{
		for (j = 0; j < ps->size - 1 - i; j++)
		{
			if (strcmp(ps->data[j].name, ps->data[j + 1].name) > 0)
			{
				tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
			}
		}
	}
	printf("排序成功！\n");
	//显示
	ShowContact(ps);
}

//7.清空联系人信息
void ClearContact(Contact* ps)
{
	ps->data = (PeoInFo *)calloc(DEFAULT_SZ, sizeof(PeoInFo));
	if (ps->data == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	printf("已清空通讯录！\n");
}

//销毁通讯录
void DestroyContact(Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//8.保存通讯录
void SaveContact(Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	//将通讯录中的信息写入到文件
	for (int i = 0; i < ps->size; i++)
	{
		fwrite(&ps->data[i], sizeof(PeoInFo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
	printf("保存成功！\n");
}
#include"contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷���ӣ�\n");
	}
	else
	{
		printf("������������>");
		scanf("%s", ps->data[ps->size].name);
		printf("���������䣺>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰��>");
		scanf("%s", ps->data[ps->size].tele);
		printf("������סַ��>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("��ӳɹ���\n");
	}

}

static int FindByName(const struct Contact* ps, char* name)
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
			return i;
	}

	return -1;//δ�ҵ�����-1
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ������������>");
	scanf("%s", name);

	//Ѱ��
	int pos = FindByName(ps, name);
	//ɾ��
	if (pos == -1)
	{
		printf("���޴��ˣ�\n");
	}
	else
	{
		for (int j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
	}
	printf("ɾ���ɹ���\n");
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ��ѯ����������>");
	scanf("%s", name);
	
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("���޴��ˣ�\n");
	}
	else
	{
		printf("%-20s\t%-3s\t%-5s\t%-12s\t%-10s\t\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-20s\t%-3d\t%-5s\t%-12s\t%-10s\t\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���������>");
	scanf("%s", name);

	//Ѱ��
	int pos = FindByName(ps, name);
	//�޸�
	if (pos == -1)
	{
		printf("���޴��ˣ�\n");
	}
	else
	{
		printf("�������޸ĺ�������>");
		scanf("%s", ps->data[pos].name);
		printf("�������޸ĺ����䣺>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������޸ĺ��Ա�>");
		scanf("%s", ps->data[pos].sex);
		printf("�������޸ĺ�绰��>");
		scanf("%s", ps->data[pos].tele);
		printf("�������޸ĺ�סַ��>");
		scanf("%s", ps->data[pos].addr);
	}
	printf("�޸ĳɹ���\n");
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
	}
	else
	{
		printf("%-20s\t%-3s\t%-5s\t%-12s\t%-10s\t\n", "����", "����", "�Ա�", "�绰", "סַ");
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

void SortContact(struct Contact* ps)
{
	int i, j;
	struct PeoInFo tmp;

	//����
	for (i = 0; i < ps->size; i++)
	{
		for (j = i; j < ps->size; j++)
		{
			if (strcmp(ps->data[i].name, ps->data[j].name) > 0)
			{
				tmp = ps->data[i];
				ps->data[i] = ps->data[j];
				ps->data[j] = tmp;
			}
		}
	}
	printf("����ɹ���\n");
	//��ʾ
	ShowContact(ps);
}
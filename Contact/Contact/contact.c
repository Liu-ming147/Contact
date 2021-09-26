#include"contact.h"

//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}

//1.�����ϵ����Ϣ
void AddContact(struct Contact* ps)
{
	assert(ps != NULL);
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

//������ϵ������
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

//2.ɾ����ϵ����Ϣ
void DelContact(struct Contact* ps)
{
	assert(ps != NULL);
	char name[MAX_NAME];

	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ����Ϣ��\n");
		return;
	}
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

//3.��ѯ��ϵ����Ϣ
void SearchContact(const struct Contact* ps)
{
	assert(ps != NULL);
	char name[MAX_NAME];

	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
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

//4.�޸���ϵ����Ϣ
void ModifyContact(struct Contact* ps)
{
	assert(ps != NULL);
	char name[MAX_NAME];

	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷��޸���Ϣ��\n");
		return;
	}

	printf("������Ҫ�޸ĵ���������>");
	scanf("%s", name);

	//Ѱ��
	int pos = FindByName(ps, name);
	//�޸�
	if (pos == -1)
	{
		printf("���޴��ˣ�\n");
		return;
	}
	printf("������Ҫ�޸ĵ���Ϣ��1-����\t2-����\t3-�Ա�\t4-�绰\t5-סַ:>");
	int msg;
	scanf("%d", &msg);
	switch (msg)
	{
	case 1:
		printf("�������޸ĺ�����:>");
		scanf("%s", ps->data[pos].name);
		break;
	case 2:
		printf("�������޸ĺ�����:>");
		scanf("%d", &ps->data[pos].age);
		break;
	case 3:
		printf("�������޸ĺ��Ա�:>");
		scanf("%s", ps->data[pos].sex);
		break;
	case 4:
		printf("�������޸ĺ�绰:>");
		scanf("%s", ps->data[pos].tele);
		break;
	case 5:
		printf("�������޸ĺ��ַ:>");
		scanf("%s", ps->data[pos].addr);
		break;
	default:
		printf("���������޸�ʧ��\n");
		return;
	}
	printf("�޸ĳɹ���\n");
}

//5.��ʾ��ϵ����Ϣ
void ShowContact(const struct Contact* ps)
{
	assert(ps != NULL);
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

//6.������ϵ����Ϣ
void SortContact(struct Contact* ps)
{
	assert(ps != NULL);
	int i, j;
	struct PeoInFo tmp;

	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��!\n");
		return;
	}
	//����
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
	printf("����ɹ���\n");
	//��ʾ
	ShowContact(ps);
}

//7.�����ϵ����Ϣ
void ClearContact(struct Contact* ps)
{
	InitContact(ps);
	printf("�����ͨѶ¼��\n");
}
#include<stdio.h>
#include<string.h>
#include<assert.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option
{
	EXIT,//0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	CLEAR
};

struct PeoInFo
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
	struct PeoInFo data[MAX];//���1000����Ϣ
	int size;//��¼��ǰ���е�Ԫ�ظ���
};

//��������
//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);

//�����ϵ��
void AddContact(struct Contact* ps);
//ɾ����ϵ��
void DelContact(struct Contact* ps);
//��ѯ��ϵ��
void SearchContact(const struct Contact* ps);
//�޸���ϵ��
void ModifyContact(struct Contact* ps);
//��ʾ��ϵ��
void ShowContact(const struct Contact* ps);
//������ϵ��, ������������ĸ��С��������
void SortContact(struct Contact* ps);
//�����ϵ��
void ClearContact(struct Contact* ps);
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>

#define DEFAULT_SZ 3	//ͨѶ¼��ʼ����
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
	CLEAR,
	SAVE
};

typedef struct PeoInFo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInFo;

//ͨѶ¼����
typedef struct Contact
{
	struct PeoInFo *data;//�����ϵ����Ϣ
	int size;//��¼��ǰ���е�Ԫ�ظ���
	int capacity;//��¼ͨѶ¼�������
}Contact;

//��������
//��ʼ��ͨѶ¼
void InitContact(Contact* ps);

//�����ϵ��
void AddContact(Contact* ps);
//ɾ����ϵ��
void DelContact(Contact* ps);
//��ѯ��ϵ��
void SearchContact(const Contact* ps);
//�޸���ϵ��
void ModifyContact(Contact* ps);
//��ʾ��ϵ��
void ShowContact(const Contact* ps);
//������ϵ��, ������������ĸ��С��������
void SortContact(Contact* ps);
//�����ϵ��
void ClearContact(Contact* ps);
//����ͨѶ¼
void DestroyContact(Contact* ps);
//����ͨѶ¼
void SaveContact(Contact* ps);
//���ͨѶ¼�Ƿ���Ҫ����
void CheckCapacity(Contact* ps);
//����ͨѶ¼
void LoadContact(Contact* ps);
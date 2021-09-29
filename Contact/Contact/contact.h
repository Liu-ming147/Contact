#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>

#define DEFAULT_SZ 3	//通讯录初始容量
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

//通讯录类型
typedef struct Contact
{
	struct PeoInFo *data;//存放联系人信息
	int size;//记录当前已有的元素个数
	int capacity;//记录通讯录最大容量
}Contact;

//声明函数
//初始化通讯录
void InitContact(Contact* ps);

//添加联系人
void AddContact(Contact* ps);
//删除联系人
void DelContact(Contact* ps);
//查询联系人
void SearchContact(const Contact* ps);
//修改联系人
void ModifyContact(Contact* ps);
//显示联系人
void ShowContact(const Contact* ps);
//排序联系人, 根据姓名首字母从小到大排序
void SortContact(Contact* ps);
//清空联系人
void ClearContact(Contact* ps);
//销毁通讯录
void DestroyContact(Contact* ps);
//保存通讯录
void SaveContact(Contact* ps);
//检测通讯录是否需要扩容
void CheckCapacity(Contact* ps);
//加载通讯录
void LoadContact(Contact* ps);
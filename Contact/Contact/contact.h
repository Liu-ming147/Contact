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

//通讯录类型
struct Contact
{
	struct PeoInFo data[MAX];//存放1000个信息
	int size;//记录当前已有的元素个数
};

//声明函数
//初始化通讯录
void InitContact(struct Contact* ps);

//添加联系人
void AddContact(struct Contact* ps);
//删除联系人
void DelContact(struct Contact* ps);
//查询联系人
void SearchContact(const struct Contact* ps);
//修改联系人
void ModifyContact(struct Contact* ps);
//显示联系人
void ShowContact(const struct Contact* ps);
//排序联系人, 根据姓名首字母从小到大排序
void SortContact(struct Contact* ps);
//清空联系人
void ClearContact(struct Contact* ps);
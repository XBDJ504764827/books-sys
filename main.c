#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//图书的结构体
struct bookInfo
{
	char name[20];			//书名
	char author[20];		//作者名
	float price;			//价格
	int num;				//数量
};
//链表结构体
struct Node
{
	struct bookInfo date;				//数据域
	struct Node* next;					//指针域
};
//创建全局链表
struct Node* list = NULL;
//创建链表
struct Node* createHead()
{
	struct Node* HeadNode = (struct Node*)malloc(sizeof(struct Node));			//动态申请内存
	HeadNode->next = NULL;			//初始化
	return HeadNode;
}
//创建节点
struct Node* createNode(struct bookInfo date)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->date = date;
	newNode->next = NULL;
	return newNode;
};
//打印链表
void printList(struct Node* headNode)
{
	//当前位置不为NULL时打印，当pMove->next为NULL时为表位，链表打印完成
	struct Node* pMove = headNode->next;
	printf("书名\t作者\t价格\t数量\n");
	while (pMove != NULL)
	{
		printf("%s\t%s\t%.2f\t%d\n", pMove->date.name, pMove->date.author, pMove->date.price, pMove->date.num);
		pMove = pMove->next;
	}
}
//头插法插入数据
void insertNodeByHead(struct Node* HeadNode, struct bookInfo date)			//参数:插入的链表,插入的数据
{
	struct Node* newNode = createNode(date);
	newNode->next = HeadNode->next;
	HeadNode->next = newNode;
}
//尾插法插入数据
void insertNodeByTail(struct Node* HeadNode, struct bookInfo date)
{
	struct Node* pMove = HeadNode;
	while (pMove->next != NULL)
	{
		pMove = pMove->next;
	}
	struct Node* newNode = createNode(date);
	pMove->next = newNode;
}
//指定位置删除
void deleteNodeByDate(struct Node* headNode, char* name)
{
	struct Node* posLefrNode = headNode;			//删除节点左侧指针
	struct Node* posNode = headNode->next;
	//需要删除的节点不为空并且数据不等于posDate
	while (posNode != NULL && strcmp(posNode->date.name, name))			//比较指定位置name和传入的图书名
	{
		posLefrNode = posNode;
		posNode = posLefrNode->next;
	}
	if (posNode == NULL)					//需要删除的节点不为空时,需要删除节点的左侧节点的下一个为需要删除节点的下一个
	{
		return;
	}
	else
	{
		posLefrNode->next = posNode->next;
		free(posNode);						//释放malloc分配的内存空间
		posNode = NULL;
	}
}
//菜单
void makeMenu()
{
	printf("--------------------------\n");
	printf("\t图书管理系统\n");
	printf("\t1.显示图书信息\n");
	printf("\t2.添加图书\n");
	printf("\t3.删除图书\n");
	printf("\t0.退出\n");
	printf("--------------------------\n");
	printf("请输入编号\n");
}
//按键控制
void key()
{
	int ch = 0;
	struct bookInfo tempBook;			//临时变量存储书籍信息
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:	//显示图书
		printList(list);		//打印链表
		system("pause");
		break;
	case 2:	//添加图书
		printf("请以空格作为间隔输入需要添加书籍的信息(名字,作者,价格,数量)\n");
		printf("例如:xxx xxx 10 10\n");
		scanf("%s%s%f%d", tempBook.name, tempBook.author, &tempBook.price, &tempBook.num);
		insertNodeByHead(list, tempBook);
		system("pause");
		break;
	case 3:	//删除图书
		printf("请输入需要删除图书的名字\n");
		scanf("%s", tempBook.name);
		deleteNodeByDate(list, tempBook.name);
		system("pause");
		break;
	case 0:	//退出
		exit(0);
		break;
	default:
		break;
	}
}
int main()
{
	list = createHead();
	while (1)
	{
		makeMenu();
		key();
	}
	return 0;
}
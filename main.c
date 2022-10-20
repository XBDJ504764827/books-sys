#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ͼ��Ľṹ��
struct bookInfo
{
	char name[20];			//����
	char author[20];		//������
	float price;			//�۸�
	int num;				//����
};
//����ṹ��
struct Node
{
	struct bookInfo date;				//������
	struct Node* next;					//ָ����
};
//����ȫ������
struct Node* list = NULL;
//��������
struct Node* createHead()
{
	struct Node* HeadNode = (struct Node*)malloc(sizeof(struct Node));			//��̬�����ڴ�
	HeadNode->next = NULL;			//��ʼ��
	return HeadNode;
}
//�����ڵ�
struct Node* createNode(struct bookInfo date)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->date = date;
	newNode->next = NULL;
	return newNode;
};
//��ӡ����
void printList(struct Node* headNode)
{
	//��ǰλ�ò�ΪNULLʱ��ӡ����pMove->nextΪNULLʱΪ��λ�������ӡ���
	struct Node* pMove = headNode->next;
	printf("����\t����\t�۸�\t����\n");
	while (pMove != NULL)
	{
		printf("%s\t%s\t%.2f\t%d\n", pMove->date.name, pMove->date.author, pMove->date.price, pMove->date.num);
		pMove = pMove->next;
	}
}
//ͷ�巨��������
void insertNodeByHead(struct Node* HeadNode, struct bookInfo date)			//����:���������,���������
{
	struct Node* newNode = createNode(date);
	newNode->next = HeadNode->next;
	HeadNode->next = newNode;
}
//β�巨��������
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
//ָ��λ��ɾ��
void deleteNodeByDate(struct Node* headNode, char* name)
{
	struct Node* posLefrNode = headNode;			//ɾ���ڵ����ָ��
	struct Node* posNode = headNode->next;
	//��Ҫɾ���Ľڵ㲻Ϊ�ղ������ݲ�����posDate
	while (posNode != NULL && strcmp(posNode->date.name, name))			//�Ƚ�ָ��λ��name�ʹ����ͼ����
	{
		posLefrNode = posNode;
		posNode = posLefrNode->next;
	}
	if (posNode == NULL)					//��Ҫɾ���Ľڵ㲻Ϊ��ʱ,��Ҫɾ���ڵ�����ڵ����һ��Ϊ��Ҫɾ���ڵ����һ��
	{
		return;
	}
	else
	{
		posLefrNode->next = posNode->next;
		free(posNode);						//�ͷ�malloc������ڴ�ռ�
		posNode = NULL;
	}
}
//�˵�
void makeMenu()
{
	printf("--------------------------\n");
	printf("\tͼ�����ϵͳ\n");
	printf("\t1.��ʾͼ����Ϣ\n");
	printf("\t2.���ͼ��\n");
	printf("\t3.ɾ��ͼ��\n");
	printf("\t0.�˳�\n");
	printf("--------------------------\n");
	printf("��������\n");
}
//��������
void key()
{
	int ch = 0;
	struct bookInfo tempBook;			//��ʱ�����洢�鼮��Ϣ
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:	//��ʾͼ��
		printList(list);		//��ӡ����
		system("pause");
		break;
	case 2:	//���ͼ��
		printf("���Կո���Ϊ���������Ҫ����鼮����Ϣ(����,����,�۸�,����)\n");
		printf("����:xxx xxx 10 10\n");
		scanf("%s%s%f%d", tempBook.name, tempBook.author, &tempBook.price, &tempBook.num);
		insertNodeByHead(list, tempBook);
		system("pause");
		break;
	case 3:	//ɾ��ͼ��
		printf("��������Ҫɾ��ͼ�������\n");
		scanf("%s", tempBook.name);
		deleteNodeByDate(list, tempBook.name);
		system("pause");
		break;
	case 0:	//�˳�
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
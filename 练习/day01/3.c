#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	3.创建一个单项链表排序
*/

typedef struct lnode{
	int data;
	int num;
	struct lnode* next;
}lnode, *linklist;


//初始化头节点
lnode* linklist_init()
{
	lnode* head = (lnode*)malloc(sizeof(lnode));
	if ( head == NULL)
	{
		printf("创建头节点失败!\n");
		return NULL;
	}

	head->next = NULL;
}

//初始化新节点
lnode* linklist_new_node( int data)
{
	lnode* new = (lnode*)malloc(sizeof(lnode));

	if ( new == NULL)
	{
		printf("创建一个新节点!\n");
		return NULL;
	}

	new->data = data;
	new->next = NULL;
	return new;
}

//插入新结点
void linklist_insert_tail(linklist head, linklist new)
{
	lnode* p=head;
	for ( p=head; p->next!=NULL; p=p->next);
	new->next = p->next;
	p->next = new;
}

//输入结点
void linklist_scanf(linklist head)
{
	int input = 0;

	while (1)
	{
		printf("请输入一个数(0为结束)>");
		scanf("%d", &input);
		if (input == 0)
		{
			break;
		}
		lnode* new = linklist_new_node( input);
		linklist_insert_tail(head, new);
	}
}


//打印
bool linklist_print(linklist head)
{
	if (head == NULL)
	{
		printf("表空!\n");
		return false;
	}

	lnode* p = head;
	for (p=head->next; p!=NULL; p=p->next)
	{
		printf("%d\t", p->data);
	}
	printf("\n");
	return true;
}

// void linklist_find()
int main(int argc, char const *argv[])
{
	lnode* head = linklist_init();

	linklist_scanf( head);
	linklist_print( head);
	linklist_MaxData_MaxNode( head);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lnode{
	int data;
	struct lnode* next;
}lnode, *linklist;


//创建头节点
lnode* linklist_create()
{
	lnode* head = (lnode*)malloc(sizeof(lnode));
	if (head == NULL)
	{
		printf("创建头节点失败!\n");
		return NULL;
	}

	head->next = NULL;
	return head;
}

//创建新节点
lnode* linklist_new_lnode(int data)
{
	lnode* new = (lnode*)malloc(sizeof(lnode));
	if (new == NULL)
	{
		printf("新节点创建失败!\n");
		return NULL;
	}

	new->data = data;
	new->next = NULL;
	return new;
}

//尾插法
lnode* linklist_InsertTail(linklist head, linklist new_node)
{
	for (lnode* p=head; p->next!=NULL; p=p->next);
	new_node->next = p->next;
	p->next = new_node;
}

//头插法
lnode* linklist_InsertHead(linklist head, linklist new_node)
{
	new_node->next = head->next;
	head->next = new_node;
}

//遍历
bool linklist_print(linklist head)
{
	if (head->next == NULL)
	{
		printf("表空!\n");
		return false;
	}

	for (lnode* p=head->next; p!=NULL; p=p->next)
	{
		printf("%d\t", p->data);
	}

	return true;
}


int main(int argc, char const *argv[])
{
	;
	return 0;
}
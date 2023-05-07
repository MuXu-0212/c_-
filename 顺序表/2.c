#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	2.数三出局
*/

typedef struct lnode{
	int data;
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
int linklist_scanf(linklist head)
{
	int input = 0;
	lnode* new = NULL;
	printf("请输入\"数三出局\"的游戏人数>");
	scanf("%d", &input);

	for (int i=1; i<=input; i++)
	{
		new = linklist_new_node( i);
		linklist_insert_tail( head, new);
	}
	return input;
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

//len为总人数
int game(linklist head, int len) 
{
	lnode* pre = head;
	lnode* p = head->next;
	int count = 1;

	while (len != 1)
	{
		if (p->next != NULL)
		{
			pre = pre->next;
			p = p->next;
		}
		else
		{
			pre = head;
			p = head->next;
		}

		count++;
		if (count == 3)
		{
			pre->next = p->next;
			free(p);
			len--;

			if (pre->next == NULL)
			{
				pre = head;
				p = head->next;
			}

			p = pre->next;
			count = 1;
		}
	} //while (len != 1)
	printf("%d\n", head->next->data);
	return 1;
}

int main(int argc, char const *argv[])
{
	lnode* head = linklist_init();  //初始化链表

	int len = linklist_scanf( head);  
	linklist_print( head);  //打印链表

    game( head, len) ;
	// linklist_print( head);  //打印链表

	
	return 0;
}
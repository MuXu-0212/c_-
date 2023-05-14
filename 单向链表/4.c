#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


/*
	3.设计一个空链表,以正数作为结点
		,向单链表中不断插入结点, 完成链表的建立
		,逆转链表中的结点.
	例如:(原有4,2,8,6,1,逆转后,变成1,6,8,2,4)
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
	int i=0;
	srand(time(NULL));
	int len = rand()%8+5;

	for (i=0; i<len ;i++)
	{
		lnode* new = linklist_new_node( rand()%100+1);
		linklist_insert_tail( head, new);
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

//4.尾插
void linklist_TailAdd(lnode* head, lnode* p)
{
	lnode* temp = head;

	for (temp=head; temp->next!=NULL; temp=temp->next);

	temp->next = p; 
}

bool linklist_reverse(linklist head)
{
	if (head->next == NULL || head->next->next == NULL)
	{
		return false;
	}

	int len=0;

	//找到链表中最后一个节点last
	lnode* last = head;
	for ( last=head->next; last->next!=NULL; last=last->next)
	{
		len++;
	}

	lnode* pre = head;
	lnode* p = head->next;

	while (len--)
	{
		while (p->next != last)
		{
			p=p->next;
			pre=pre->next;
		}
		pre->next = last;
		p->next = NULL;
        linklist_TailAdd(last, p);

        pre = head;
        p = head->next;
	}


	return true;

}


int main(int argc, char const *argv[])
{
	lnode* head = linklist_init();

	linklist_scanf( head);
	linklist_print( head);

	printf("逆序后\n");
	linklist_reverse( head);
	linklist_print( head);



	return 0;
}



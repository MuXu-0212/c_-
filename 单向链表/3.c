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

//排序
bool linklist_sort(linklist head)
{
	if (head->next == NULL)
	{
		printf("表空!\n");
		return false;
	}

	lnode* pre = NULL;	//当前需要对比的节点
	lnode* p = NULL;	//用于寻找比后面序列中比pre小的值
	lnode* p_temp = NULL; //记录最小值节点的地址
	int min = 0;	//储存最小值

	//固定pre,移动p
	for (pre=head->next; pre!=NULL; pre=pre->next)
	{
		min = pre->data;
		p_temp = pre;
		for (p=pre->next; p!=NULL; p=p->next)
		{
			if (min > p->data)
			{
				min = p->data;	//记录最小数值
				p_temp = p;		//记录最小值节点的地址
				// printf("%d\n", min);
			}
		}

		//节点的值交换
		p_temp->data = pre->data;	
		pre->data = min;
	}

	return true;

}
int main(int argc, char const *argv[])
{
	lnode* head = linklist_init();

	linklist_scanf( head);
	linklist_print( head);

	linklist_sort( head);
	printf("排序后\n");
	linklist_print( head);

	return 0;
}
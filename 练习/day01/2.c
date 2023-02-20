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

bool linklist_destroy(linklist pre, linklist head)
{

    return true;
}

//len为总人数
int game(linklist head, int len) 
{
	// printf("len = %d\n", len);
	if (head->next == NULL)
	{
		printf("无人参加!\n");
		return 0;
	}

	int i = 0;
	lnode* p = head->next;
	lnode* pre = head;
	while (1)
	{
		i++; //记录编号(1~3)

		if (i==3)
		{
		//删除
			lnode* pp = p;
			lnode* ppre = pre;

			// if (pre->next == NULL)
			// {
			// 	ppre = head;
			// 	pp = head->next;
			// }
		    ppre->next = pp->next;
		    free(pp); //删除

			i=0;
			len--;
			printf("len = %d\n", len);
			linklist_print( head);  //打印链表
		}

		pre=pre->next;
		p=p->next;

		//从头开始,重新循环一圈
		if (p == NULL || pre == NULL) 
		{
			pre = head;
			p = head->next;
		}
		if (len == 1)  //剩最后一个人, 退出循环
		{
			break;
		}
	}
	printf("pre->next->data=%d\n", pre->next->data); 

	return pre->next->data;
}

int main(int argc, char const *argv[])
{
	lnode* head = linklist_init();  //初始化链表

	int len = linklist_scanf( head);  
	linklist_print( head);  //打印链表


	printf("最后一个人的编号是%d\n ", game( head, len));

	
	return 0;
}
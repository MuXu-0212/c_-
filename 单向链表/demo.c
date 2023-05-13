#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FIND_DATA 	1
#define MOVE_NODE 	2
#define FREE_NODE 	3
#define CHANGE_DATA 4

//1.设计节点
typedef struct node
{
	int data;
	struct node *next;
}list_s,*list_p;


//2.初始化头节点
list_p Creat_Head(void)
{
	list_p head = (list_p)malloc(sizeof(list_s));
	if (head != NULL)
	{
		head->next = head; //让该头节点自己指向自己
		return head;
	}

	return NULL;
}

//2.初始化新节点
list_p Creat_New_Node(int new_data)
{
	list_p new_node = (list_p)malloc(sizeof(list_s));
	if (new_node != NULL)
	{
		new_node->data = new_data;
		new_node->next = new_node; //让该头节点自己指向自己
		return new_node;
	}
	return NULL;
}

//3.尾插
void Inset_List_Tail(list_p head, list_p new_node)
{
	list_p p = NULL;
	for (p = head->next; p->next != head; p = p->next);

	//1.让新节点指向头节点
	new_node->next = p->next;
	p->next = new_node;
}

//头插
void Inset_List_Head(list_p head, list_p new_node)
{
	new_node->next = head->next;
	head->next     = new_node;
}

// FIND_DATA 	1
// MOVE_NODE 	2
// FREE_NODE 	3
// CHANGE_DATA  4
list_p Find_Set(list_p head,int set_data, int cmd)
{
	if (head->next == head)
	{
		return NULL;
	}

	list_p pos = head;
	for (list_p p = head->next; p != head; p = p->next, pos = pos->next)
	{
		if (p->data == set_data)
		{
			switch(cmd)
			{
				case FIND_DATA:
					printf("%d\n", p->data);
					return NULL;
				case MOVE_NODE:
					pos->next = p->next;
					p->next = NULL;
					return p;
				case FREE_NODE:
					pos->next = p->next;
					p->next = NULL;
					free(p);
					return NULL;
				case CHANGE_DATA:
					printf("请输入新的数据：\n");
					scanf("%d",&p->data);
					printf("修改数据成功\n");
					return NULL;
				default:
					printf("参数有误 !~\n");
					return NULL;
			}
		}
	}

	printf("没有找到该节点.\n");
}


//4.遍历链表
int Show_List(list_p head)
{
	//说明该头节点后面是一个节点都没有
	if (head->next == head)
	{
		return -1;
	}

	for (list_p p = head->next; p != head; p = p->next)
	{
		printf("%d ", p->data);
	}
	printf("\n");
}


//5.销毁整条链表
void Delete_List(list_p head)
{
	list_p p = head->next;
	while( p != head)
	{
		head->next = p->next;
		p->next = NULL;
		free(p);
		p = head->next;
	}

	free(head);
}

int main(int argc, char const *argv[])
{
	list_p head = Creat_Head();
	list_p new_node = NULL;

	for (int i = 0; i < 10; ++i)
	{
		new_node = Creat_New_Node(i+1);
		Inset_List_Tail(head,new_node);
	}

	Show_List(head);

	// 查找数据 Find_Set(head, 3, FIND_DATA);
	// 取出一个节点
	// list_p p = Find_Set(head, 3, MOVE_NODE);
	// Inset_List_Tail(head, p);

	//删除节点
	//Find_Set(head, 4, FREE_NODE);

	//修改数据
	//Find_Set(head, 4, CHANGE_DATA);


	Show_List(head);
	Delete_List(head);
	return 0;
}
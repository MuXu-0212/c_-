#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//设计节点
typedef struct node
{
	int data;
	struct node	*prev;
	struct node	*next;
}list_s,* list_p;


#define MOVE_NODE 1
#define FREE_NODE 2
#define FIND_NODE 3
#define CHANGE_NODE 4

//创建头节点
list_p Creat_Head(void)
{
	list_p head = (list_p)malloc(sizeof(list_s));
	if (head != NULL)
	{
		head->prev = head;
		head->next = head;
		return head;
	}
}

//创建新的节点
list_p Creat_New_Node(int new_data)
{
	list_p new_node = (list_p)malloc(sizeof(list_s));
	if (new_node != NULL)
	{
		new_node->data = new_data;
		new_node->prev = new_node;
		new_node->next = new_node;
		return new_node;
	}
}

//头插
void Inset_List_Head(list_p head, list_p new_node)
{
	new_node->prev 		 = head;
	new_node->next 		 = head->next;
	head->next     		 = new_node;
	new_node->next->prev = new_node;
}

//尾插
void Inset_List_Tail(list_p head, list_p new_node)
{
	new_node->prev 		= head->prev;
	new_node->next 		= head;
	head->prev->next 	= new_node;
	head->prev     		= new_node;
}

//向后遍历
int Next_Show_List(list_p head)
{
	if (head->next == head || head->prev == head)
	{
		return -1;
	}

	list_p p = NULL;
	for (p = head->next; p != head; p = p->next)
	{
		printf("%d ", p->data);
	}
	printf("\n");
}

//向前遍历
int Prev_Show_List(list_p head)
{
	if (head->next == head || head->prev == head)
	{
		return -1;
	}

	list_p p = NULL;
	for (p = head->prev; p != head; p = p->prev)
	{
		printf("%d ", p->data);
	}
	printf("\n");
}

//取下节点
list_p Move_Node(list_p p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	p->prev = p;
	p->next = p;
	return p;
}

//查改
list_p Find_Set(list_p head, int data, int cmd)
{
	if (head->next == head || head->prev == head)
	{
		return NULL;
	}

	list_p p = NULL;
	for (p = head->next; p != head; p = p->next)
	{
		if (p->data == data)
		{
			switch(cmd)
			{
				case MOVE_NODE:
					return Move_Node(p);
				case FREE_NODE:
					free(Move_Node(p));
					return NULL;
				case FIND_NODE:
					printf("%d\n", p->data);
					return NULL;
				case CHANGE_NODE:
					printf("请输入新的数据\n");
					scanf("%d",&p->data);
					printf("修改成功\n");
					return NULL;
				default:
					return NULL;
			}
		}
	}
	printf("没有找到该节点\n");
}

int Delete_List(list_p head)
{

	list_p p = head->next;
	while(p != head)
	{
		free(Move_Node(p));
		p = head->next;
	}

	if (head->prev == head || head->next == head)
	{
		free(head);
		return 1;
	}
}

//选择排序: 每次比较一轮,选择无序序列当中的最大或最小的数据
bool Sort(list_p head)
{
	//没有节点或只有一个节点的时候是不需要排序的
	if ((head->next == head || head->prev == head) && (head->next->next == head))
	{
		return false;
	}


	//1.结束条件
	//2.插入的基准点
	list_p p = head->next;
	int len = 0;
	//计算出链表的总节点个数
	while( p != head)
	{
		len++;
		p = p->next;
	}
	len = len - 1;

	list_p t = head; //插入基准点
	list_p tmp = NULL;
	int min = 0;

	//比较的轮数
	while(len--)
	{
		min = t->next->data;
		//去寻找一组无序序列当中最小或最大的数据
		for (p = t->next->next; p != head; p = p->next)
		{
			if (min > p->data)
			{
				min = p->data;
				tmp = p;
			}
		}

		if (tmp != NULL)
		{
			Inset_List_Head(t,Move_Node(tmp));
			tmp = NULL;
		}
		t = t->next;
	}
	return true;

}




int main(int argc, char const *argv[])
{
	list_p head = Creat_Head();
	list_p new_node = NULL;

	srand(time(NULL));
	for (int i = 0; i < rand()%30+5; ++i)
	{
		new_node = Creat_New_Node(rand()%100);
		Inset_List_Tail(head,new_node);
	}


	Next_Show_List(head);

	Sort(head);

	Next_Show_List(head);

	Delete_List(head);
	
	//删除整条链表
	//改查
	//取下节点

	return 0;
}
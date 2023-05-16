#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1.设计节点
struct node
{
	int data;
	struct node *next;
};

//2.头节点初始化
struct node *Creat_Head(void)
{
	struct node * head = (struct node *)malloc(sizeof(struct node));
	if (head != NULL)
	{
		head->next = NULL;
		return head;
	}
	return NULL;
}

//3.创建新的节点
struct node *Creat_New_Node(int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	if (new_node != NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
		return new_node;
	}
	return NULL;
}

//4.尾插
void Inset_List_Tail(struct node * head, struct node *new_node)
{
	struct node * p = head;

	while(p->next != NULL)
	{
		p = p->next;
	}

	p->next = new_node;
}

//头插
void Inset_List_Head(struct node * head, struct node *new_node)
{
	new_node->next = head->next;
	head->next     = new_node;
}

//删除节点
int Delete_Node(struct node * head, int delete_data)
{
	if (head->next == NULL)
	{
		return 0;
	}


	struct node *tmp = head;
	for (struct node *p = head->next; p != NULL; p = p->next,tmp = tmp->next)
	{
		if (delete_data == p->data)
		{
			tmp->next = p->next;
			p->next   = NULL;
			free(p);
			return 1;
		}
	}

	printf("找不到要删除的节点\n");
}

//移动节点
struct node *Move_Node(struct node * head, int move_data)
{
	if (head->next == NULL)
	{
		return NULL;
	}

	struct node *tmp = head;
	for (struct node *p = head->next; p != NULL; p = p->next,tmp = tmp->next)
	{
		if (move_data == p->data)
		{
			tmp->next = p->next;
			p->next   = NULL;
			return p;
		}
	}

	printf("找不到要移动的节点\n");
}


//查数据
int Find_Node(struct node * head, int find_data)
{
	if (head->next == NULL)
	{
		return 0;
	}

	for (struct node *p = head->next; p != NULL; p = p->next)
	{
		if (find_data == p->data)
		{
			printf("该数据为:%d\n", p->data);
			return 1;
		}
	}

	printf("没有找到该数据\n");
}

//修改数据
int Change_Node(struct node * head, int change_data)
{
	if (head->next == NULL)
	{
		return 0;
	}

	for (struct node *p = head->next; p != NULL; p = p->next)
	{
		if (change_data == p->data)
		{
			printf("请输入新的数据：\n");
			scanf("%d",&p->data);
			printf("修改成功\n");
			return 1;
		}
	}
	printf("没有找到该数据\n");
}

int Show_List(struct node * head)
{
	if (head->next == NULL)
	{
		return -1;
	}

	for (struct node * p = head->next; p != NULL; p = p->next)
	{
		printf("%d ",p->data);
	}
	printf("\n");
}

void Delete_List(struct node * head)
{
	struct node * p =  head->next;
	while(p != NULL)
	{
		head->next = p->next;
		p->next = NULL;
		free(p);
		p = head->next;
	}


	free(head);
}

int Find_Max_Data(struct node * head)
{
	int max = head->next->data;

	for (struct node *p = head->next->next; p != NULL; p = p->next)
	{
		if (max < p->data)
		{
			max = p->data;
		}
	}

	return max;
}


void Find_Max_Number(struct node * head)
{
	int max_data = Find_Max_Data(head);
	int i = 1;
	for (struct node *p = head->next; p != NULL; p = p->next,i++)
	{
		if (max_data == p->data)
		{
			break;
		}
	}
	printf("最大数据为 %d, 最大数据下标为 %d\n",max_data,i);
}

int Sort(struct node * head,int len)
{
	//如果只有一个节点 就没必要排序
	if (head->next == NULL || head->next->next == NULL)
	{
		return -1;
	}

	struct node *p = NULL;     //用于遍历
	struct node *t = NULL;     //记录指针p前面一个节点的
	struct node *prev = NULL;  //指向最小节点的上一个节点
	struct node *pos = head;   //头插的基准点
	int min = 0;    //用于记录最小的那个数据节点

	while(len--)
	{
		t = pos->next;   //保持在头插的后一位
		min = t->data;   //每次都假设pos后一位是最小的数据
		prev = NULL;

		for (p = t->next; p != NULL; p = p->next, t = t->next)
		{
			if (min > p->data)
			{
				min = p->data; 	//记录最小数据的节点
				prev = t;		//记录最小数据节点的前一个节点
			}
		}
		if (prev != NULL)
		{
			p = prev->next;			//记录让p指向要插入的节点
			prev->next = p->next;   //保持链表不断
			Inset_List_Head(pos, p); //把数据进行头插
		}

		pos = pos->next;  //移动头插的基准点
	}
}

//逆序节点
int nixu(struct node * head, int len)
{
	if (head->next == NULL && head->next->next == NULL)
	{
		return -1;
	}

	//找到到尾部的节点
	struct node *pos = head->next;

	//寻找到最后一个节点为基准点
	while(pos->next != NULL)
	{
		pos = pos->next;
	}
	//把pos前面的一个节点移动pos后面去
	struct node *p = head->next;
	struct node *t = head;
	len = len - 1;

	while(len--)
	{
		//p找到pos的前一个节点 t记录p前面一个节点
		while(p->next != pos )
		{
			p = p->next;
			t = t->next;
		}
		t->next = pos;
		p->next = NULL;
		Inset_List_Tail(pos, p);

		p = head->next;
		t = head;
	}

}

void Game(struct node * head, int n)
{
	struct node *t = head;
	struct node *p = head->next;
	int conut = 1;

	while( n != 1 )
	{
		if (p->next != NULL)  //如果不是最后一个节点,则往后移动
		{
			t = t->next;
			p = p->next;
		}
		else				 //如果是p到达最后一个节点，则需要回到起始地点
		{
			t = head;
			p = head->next;
		}
		conut++;    //计数
		if (conut == 3)
		{
			t->next = p->next;   //取下P节点进行释放
			free(p);
			n--;  //参与游戏的人数减少1

			if (t->next == NULL) //如果出局的是人最后一个节点,则让指针回到初始地点
			{
				t = head;
				p = head->next;
			}
			
			p = t->next; //释放p指针后 把p指针拉回 t 指针的后面.
			conut = 1;
		}
	}
	printf("%d\n",head->next->data);
}


int main(int argc, char const *argv[])
{
	
	struct node * head = Creat_Head();
	struct node * new_node = NULL;

	srand(time(NULL));
	int len = 7;

	for (int i = 0; i < len; ++i)
	{
		new_node = Creat_New_Node(i+1);
		Inset_List_Tail(head, new_node);
	}

	Show_List(head);
	/*
		作业1
		Find_Max_Number(head);
		Delete_List(head);*/

	/*
		作业3：
		选择排序： 每次选择一组无序的数列当中最小的或最大的数据，进行排序
		Sort(head,len);
	*/

	/*
		作业4：逆序节点
		nixu(head,len);
	*/
	Game(head,len);

	Show_List(head);
	
	return 0;
}
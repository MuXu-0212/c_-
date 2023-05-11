#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//节点的设计
typedef struct node
{
	int data;
	struct node *next;
}node_s,*node_p;

typedef struct queue
{
	struct node *front; //指向队列的头节点
	struct node *rear;  //指向队列的尾节点
}sq_s,*sq_p;


//创建一条队列
sq_p Creat_List_Queue(void)
{
	sq_p link = (sq_p)malloc(sizeof(sq_s));
	if (link != NULL)
	{
		//申请一个头节点
		link->front = (node_p)malloc(sizeof(node_s));
		link->rear  = link->front; //让两个指针重合表示为空队列
		link->front->next = NULL;  //让头节点的指针域指向空
		return link;
	}
}

//入队
bool En_Queue(sq_p link,int data)
{
	//1.创建一个节点
	node_p node = (node_p)malloc(sizeof(node_s));
	if (node != NULL)
	{
		node->data = data; 			//给新节点的数据域进行赋值
		node->next = NULL; 			//初始化新的节点指针域
		link->rear->next = node; 	//让rear指针指向新的节点
		link->rear = node;          //更新rear指针的位置
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Is_Empty(sq_p link)
{
	return link->front == link->rear;
}

//出队
bool Out_Queue(sq_p link, int *data)
{
	if (Is_Empty(link))
	{
		return false;
	}

	*data = link->front->next->data;	//1.保存即将要出队的数据
	node_p temp = link->front->next; 	//2.保存该节点的位置
	link->front->next = temp->next;		//3.与要出队的节点断开练习
	temp->next = NULL;					
	free(temp);							//4.释放掉节点

	//如果我们出队的节点为最后一个节点,
	//则需要把最后一个节点拉回到front的位置,表示为空队列
	if (link->front->next == NULL)
	{
		link->rear = link->front;
	}
	return true;
}

bool Show_Queue(sq_p link)
{
	if (Is_Empty(link))
	{
		return false;
	}
	node_p p = link->front->next;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return true;
}

int main(int argc, char const *argv[])
{
	sq_p link = Creat_List_Queue();

	for (size_t i = 0; i < 5; i++)
	{
		En_Queue(link, i+1);
	}

	Show_Queue(link);
	int data;
	
	while(Out_Queue(link,&data));

	free(link->front);
	free(link);

	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//链表节点结构体
typedef struct node
{
	int data;
	struct node *next;
}node_s,* node_p;

//定义链式队列结构体
typedef struct queue
{
	node_p front;
	node_p rear;
}link_s,* link_p;

//判断链式队列是否为NULL
bool is_empty(link_p link)
{
	return link->front == link->rear;
}

//空队列
link_p init_link_queue(void)
{
	link_p link = malloc(sizeof(link_s));
	if(link != NULL)
	{
		link->front = (node_p)malloc(sizeof(node_s));   //指向数据链表节点的头节点
		link->rear  = link->front;			//指向数据链表的头节点
		link->rear->next = NULL;			//数据节点里的next指向NULL
		return link;
	}
}

//遍历
void show_queue(link_p link)
{
	node_p p = link->front->next;
	
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

//入队
bool en_queue(link_p link, int data)
{
	node_p new_node = (node_p)malloc(sizeof(node_s));
	if(new_node == NULL)
	{
		return false;
	}
	new_node->data = data;			//数据赋值
	new_node->next = NULL;			//数据节点指向NULL
	link->rear->next = new_node;  	        //新节点里的next针指向新的节点
	link->rear = new_node;			//队列尾指针偏移
	return true;
}

//出队
bool out_queue(link_p link, int *data)
{
	if(is_empty(link))
		return false;
	
	*data = link->front->next->data;               //队头元素
	
	node_p tmp = link->front->next;               //保存节点
	link->front->next = link->front->next->next;  //下一个节点
	
	free(tmp);
 
	if(link->front->next == NULL)
	{
		link->rear = link->front;    //让尾指针指向头节点
	}
	return true;
}



int main(void)
{
	//1.申请空队列
	link_p link = init_link_queue();
	int data;
	while(1)
	{
		if(scanf("%d",&data) == 1)
		{
			if(!en_queue(link, data))
			{
				printf("en queue failed\n");
				return -1;
			}
			else
			{
				show_queue(link);
			}
		}
		else
		{
			int m;
			if(!out_queue(link, &m))
			{
				printf("out queue failed\n");
				return -2;
			}
			else
			{
				printf("%d is out of queue\n",m);
				show_queue(link);
			}
			while(getchar() != '\n');
		}
	}
	
	return 0;
}
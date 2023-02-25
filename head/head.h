#ifndef __head_h_
#define __head_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*---------------------双循环链表----------------------*/
/*定义一个头节点*/
typedef struct DNode
{
	int data;
	struct DNode* next;
	struct DNode* prev;
}DNode, *Dlinklist;

/*初始化一个双向循环链表*/
extern DNode* Dlinklist_create();

/*创建一个新节点*/
extern DNode* Dlinklist_NewNode( int data);

/*双向循环链表尾插*/
extern void Dlinklist_InsertTail( Dlinklist head, Dlinklist NewNode);

/*双向循环链表头插*/
extern void Dlinklist_InsertHead(Dlinklist head, Dlinklist new);

/*双向循环链表向前遍历*/
extern bool Dlinklist_PreOrder(Dlinklist head);

/*双向循环链表向后遍历*/
extern bool Dlinklist_LastOrder(Dlinklist head);

/*随机赋值, len为随机个数*/
extern void Dlinklist_RandScanf(Dlinklist head, int len);

/*取下指定双循环链表的节点*/
extern bool Dlinklist_UnbringHead(Dlinklist p, int* data);

/*双循环链表地址排序*/
extern bool Dlinklist_sort(Dlinklist head);




/*---------------------链队----------------------*/
/*定义队列节点*/
typedef struct node{
	int data;
	struct node* next;
}node, *queue;

/*定义一个存储队头和队尾的指针*/
typedef struct{
	queue front;
	queue rear;
}Queue;

/*初始化带头结点的队列*/
extern Queue* linkqueue_init();

/*判断队空*/
extern bool linkqueue_IsEmpty(Queue q);

/*入队*/
extern bool linkqueue_enter(Queue* q, int data);

/*出队*/
extern bool linkqueue_out(Queue* q, int* data);

/*打印队列*/
extern bool linkqueue_print(Queue q);

/*随机队列数据*/
extern void linkqueue_RandScanf(Queue* q, int len);



#endif
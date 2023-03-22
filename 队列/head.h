#ifndef __head_h_
#define __head_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


//定义一个头节点
typedef struct DNode
{
	int data;
	struct DNode* next;
	struct DNode* prev;
}DNode, *Dlinklist;

DNode* Dlinklist_create()
{
	DNode* head = (DNode*)malloc(sizeof(DNode));
	if ( head != NULL)
	{
		head->prev = head;
        head->next = head;
		return head;
	} 
	return NULL;
}

DNode* Dlinklist_NewNode( int data)
{
	DNode* NewNode = (DNode*)malloc(sizeof(DNode));
    if (NewNode != NULL)
    {
    	NewNode->data = data;
    	NewNode->next = NewNode;
    	NewNode->prev = NewNode;
    	return NewNode;
    }
    return NULL;
}

void Dlinklist_InsertTail( Dlinklist head, Dlinklist NewNode)
{
    NewNode->next = head; 
    NewNode->prev = head->prev;
    head->prev->next = NewNode;
    head->prev = NewNode;
}

bool Dlinklist_PreOrder(Dlinklist head)
{
	if (head->prev == head)
	{
		return false;
	}
	DNode* p = head;
	for (p=head->prev; p!=head; p=p->prev)
	{
		printf("%d  ", p->data);
	}
	printf("\n");
	return true;
}

bool Dlinklist_LastOrder(Dlinklist head)
{
	if (head->next == head)
	{
		return false;
	}

	DNode* p = head;

	for (p=head->next; p!=head; p=p->next)
	{
		printf("%d  ", p->data);
	}
	printf("\n");
}

void Dlinklist_InsertHead(Dlinklist head, Dlinklist new)
{
	new->prev = head;
	new->next = head->next;
	head->next->prev = new;
	head->next = new;
}

void Dlinklist_scanf(Dlinklist head)
{
	srand(time(NULL));
	int len = 10;
	int i=0;
	DNode* new = NULL;
	for (i=0; i<len; i++)
	{
		new = Dlinklist_NewNode( rand()%100+1);
		Dlinklist_InsertHead(head, new);
	}
}

bool Dlinklist_UnbringHead(Dlinklist p, int* data)
{
	if (p != NULL)
	{
		*data = p->data;
		return true;
	}
	return false;
}

bool Dlinklist_sort(Dlinklist head)
{
    if (head->next==head || head->next->next==head)
    {
    	return false;
    }

    DNode* head_t = head;
    DNode* pre = head;
    DNode* p = pre->next;
    DNode* p_m = NULL;
    int min = 0;
    int len = 0;

    while (pre->next != head)
    {
    	len++;
    	pre=pre->next;
    }
    pre = head->next;

    while (head_t->next != head)
    {
    	// printf("len = %d\n", len);
    	pre = head_t->next;
    	min = pre->data;
    	p_m = head;

    	for (p=pre->next; p!=head; p=p->next, pre=pre->next)
    	{
    		if (min > p->data)
    		{
    			min = p->data;
    			p_m = pre;
    		}
    	}
    	if (p_m != head)
    	{
    		p = p_m->next;
    		p_m->next = p->next;
    		p->next->prev = p_m;
    		Dlinklist_InsertHead(head_t, p);
    	}
    	head_t = head_t->next;



    }
    return true;
}

#endif
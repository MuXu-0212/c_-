#include "head.h"


/*-------------------双向循环链表-------------------*/
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

// void Dlinklist_InsertHead( Dlinklist head, Dlinklist NewNode)
// {
//     NewNode->prev = head;
//     NewNode->next = head->next;
//     head->next->prev = NewNode;
//     head->next = NewNode;
// }

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

bool Is_odd(int num)
{
	if (num % 2 == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Dlinklist_swap(Dlinklist head, Dlinklist p)
{
	DNode* temp = p;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	p->prev = head->prev;
	p->next = head;
	
	head->prev->next = p;
	head->prev = p;
}

bool Dlinklist_OddAndEven(Dlinklist head)
{
	if (head->next == head || head->next->next == head)
	{
		return false;
	}

	int len = 0; //数据总数
	int even = 0; //偶数个数

	DNode* p = NULL;

	for ( p=head->next; p!=head; p=p->next)
	{
		len++;
		if (!Is_odd(p->data))
		{
			p->prev->next = p->next; 
			Dlinklist_InsertTail( head, p);
			p = p->prev;
		}
	}

	return true;

}


int main(int argc, char const *argv[])
{
	DNode* head = Dlinklist_create();
	Dlinklist_scanf( head);
	Dlinklist_PreOrder( head);

	//1.使用双向链表，把一组无序节点从大到小的进行排序 
	//(双向不循环链表)
	// printf("从小到大排序后\n");
	// Dlinklist_sort( head);
	// Dlinklist_LastOrder( head);


	//2.使用随机数生成10个节点，
	//把所有的节点把一个链表内的数据分为奇偶，奇数升序，
	//偶数降序(双向循环链表)
	Dlinklist_OddAndEven( head);
	Dlinklist_PreOrder( head);


	return 0;
}


/*-------------------双向链表-------------------*/

// typedef struct DNode{
// 	int data;
// 	struct DNode* prev;
// 	struct DNode* next;
// }DNode, *linklist;

// DNode* Dlinklist_create()
// {
// 	DNode* head =  (DNode*)malloc(sizeof(DNode));
// 	if (head != NULL)
// 	{
// 		;
// 	}
// }

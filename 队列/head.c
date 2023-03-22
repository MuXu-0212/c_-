#include "head.h"


/*---------------------双循环链表----------------------*/
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

void Dlinklist_scanf(Dlinklist head, int len)
{
	srand(time(NULL));
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

/*---------------------链队----------------------*/
/*初始化带头结点的队列*/
Queue* linkqueue_init()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (q != NULL)
	{
		q->front = (node*)malloc(sizeof(node));
		q->rear = q->front;
		q->front->next = NULL;
		// printf("1111\n");
		return q;		
	}
	return NULL;
}

/*判断队空*/
bool linkqueue_IsEmpty(Queue q)
{
	if (q.front == q.rear)
	{
		return true;
	}
	return false;
}

/*入队*/
bool linkqueue_enter(Queue* q, int data)
{
	// printf("1111\n");
	node* new = (node*)malloc(sizeof(node));
	if (new != NULL)
	{
		new->data = data;
		new->next = NULL;
		q->rear->next = new;
		q->rear = new;
		// printf("q->rear = %p\n", q->rear);
		// printf("q->front->next->data = %d\n", q->front->next->data);
		return true;
	}
	return false;
}

/*出队*/
bool linkqueue_out(Queue* q, int* data)
{
	if (linkqueue_IsEmpty(*q))
	{
		return false;
	}

	*data = q->front->next->data;
	node* temp = q->front->next;
    q->front->next = temp->next;
    temp->next = NULL;
    if (q->rear == temp)
    {
    	q->rear = q->front;
    }
    free(temp);

    return true;
}

/*打印队列*/
bool linkqueue_print(Queue q)
{
	int i=0;
	if (linkqueue_IsEmpty(q))
	{
		printf("表空!\n");
		return false;
	}
	node* p = q.front->next;
	while (p != NULL)
	{
		i++;
        printf("%d\t",p->data);
        p = p->next;
        // if ( i == 5)
        // {
        // 	i=0;
        // 	printf("\n");
        // }
	}
	printf("\n");
	return true;
}

/*随机队列数据*/
void linkqueue_RandScanf(Queue* q, int len)
{
	int i = 0;
	int data = 0;

	srand(time(NULL));

	for (i=0; i<len; i++)
	{
		data = rand()%999+1;
		// printf("%d\n", data);
		linkqueue_enter(q, data);
	}
	printf("\n");
}
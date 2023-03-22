#include "head.h"

typedef struct node{
	int data;
	struct node* next;
}node, *queue;

typedef struct{
	queue front;
	queue rear;
}Queue;

//初始化带头结点的队列
Queue* queue_init()
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

//判断队空
bool queue_IsEmpty(Queue q)
{
	if (q.front == q.rear)
	{
		return true;
	}
	return false;
}

bool queue_enter(Queue* q, int data)
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

bool queue_out(Queue* q, int* data)
{
	if (queue_IsEmpty(*q))
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

bool queue_print(Queue q)
{
	int i=0;
	if (queue_IsEmpty(q))
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

void queue_scanf(Queue* q)
{
	int i = 0;
	int data = 0;

	srand(time(NULL));
	int len = rand()%50+30;

	for (i=0; i<len; i++)
	{
		data = rand()%999+1;
		// printf("%d\n", data);
		queue_enter(q, data);
	}
	// printf("\n");
}

bool Is_char( char c)
{
	if (c>='a' && c<='z')
	{
		return true;
	}

	if (c>='A' && c<='Z')
	{
		return true;
	}

	return false;
}

//1.用链队输入数字入队，输入字母出队
int queue_DataIo(Queue* q)
{
	int flag=0, i=10;
	char input=0;
	int data = 0;
	while (1)
	{
		printf("输入数字进队,输入字符出队(输入0退出)>");
		scanf("%c", &input);
		while (getchar() != '\n');
		if (Is_char(input) )
		{
			if (input -'0' == 0)
			{
				printf("5555\n");
				return 1;
			}
			//getchar();
			flag = 0;
		}
		else
		{
			flag = 1;
		}
		// printf("flag:%d\n", flag);

		switch(flag)
		{
			printf("%d\n", flag);
			case 1:
				queue_enter(q , input-'0');
				break;
			case 0:
				queue_out(q , &data);
				break;
		}
		queue_print(*q);
	}
}

// Queue* queue_sort(Queue* q)
// {
// 	if (queue_IsEmpty( *q))
// 	{
// 		return NULL;
// 	}

// 	Queue* temp = queue_init();
// 	Queue* new_q = queue_init();

// 	int min = 0;
// 	int data = 0;

// 	queue_out( q, &data);
// 	min = data;
// 	queue_out( q, &data);
// 	if (min>data)
// 	{
// 		queue_enter( temp, min);
// 		queue_enter( q, data);
// 	}
// 	else
// 	{
// 		queue_enter( q, min);
// 		queue_enter( temp, data);
// 	}

// 	while (!queue_IsEmpty(*q) || !queue_IsEmpty(*temp))
// 	{
// 		//
// 		if (!queue_IsEmpty(*q) )
// 		{
// 			queue_out( q, &data);
// 			min = data;
// 			queue_enter( q, data);
// 		}
// 		while (!queue_IsEmpty(*q) )
// 		{
// 			// printf("11111\n");
// 			queue_out( q, &data);
// 			if (min > data)
// 			{
// 				queue_enter( temp, min);
// 				min = data;
// 			}
// 			else
// 			{
// 				queue_enter( temp, data);
// 			}
// 		}

// 		if (!queue_IsEmpty(*temp))
// 		{
// 			queue_out( temp, &data);
// 			queue_enter( q, data);
// 		}
// 		queue_enter( new_q, min);

// 		//
// 		if (!queue_IsEmpty(*temp) )
// 		{
// 			queue_out( temp, &data);
// 			min = data;
// 			queue_enter( temp, data);
// 		}
// 		while (!queue_IsEmpty(*temp))
// 		{
// 			queue_out( temp, &data);
// 			// printf("data = %d\n", data);
// 			if (min > data)
// 			{
// 				queue_enter( q, min);
// 				min = data;
// 			}
// 			else
// 			{
// 				queue_enter( q, data);
// 			}
// 		}
// 		if (!queue_IsEmpty(*q))
// 		{
// 			queue_out( q, &data);
// 			queue_enter( temp, data);
// 		}
// 		queue_enter( new_q, min);
// 	} //while (!queue_IsEmpty(*q) && !queue_IsEmpty(*new_q))

// 	return new_q;
// }

// linklist_sort()

//2.有序拆分链表
bool queue_divide(Queue* qq)
{
	if (queue_IsEmpty(*qq))
	{
		printf("表空！\n");
		return false;
	}

	int data = 0;	//储存队列和链表里取出来的数据
	Queue* q = queue_init();  //存放排序好的数据
	DNode* head = Dlinklist_create(); //新建一个链表

	//将队列中的数据转到链表中
	while (!queue_IsEmpty(*qq))	
	{
		queue_out( qq, &data);	//出队
		DNode* new = Dlinklist_NewNode( data);
		Dlinklist_InsertHead(head, new);
	}

	Dlinklist_sort( head);  //用链表排序

	//将链表中排序好的数转到队列中
	DNode* p = head->next;
	while (p != head)
	{
		Dlinklist_UnbringHead( p, &data);
		queue_enter( q, data);
		p = p->next;
	}


	//分别存放一位，两位，三位数
	Queue* q1 = queue_init(); 
	Queue* q2 = queue_init(); 
	Queue* q3 = queue_init(); 
	while (!queue_IsEmpty(*q))
	{
		queue_out(q, &data);
		if (data>=0 && data<=9)
		{
			queue_enter(q1, data);
		}
		if (data>=10 && data<=99)
		{
			queue_enter(q2, data);
		}
		if (data>=100 && data<=999)
		{
			queue_enter(q3, data);
		}
	}

	//打印结果
	printf("\n\n一位数:\n");
	queue_print(*q1);
	printf("二位数:\n");
	queue_print(*q2);
	printf("三位数:\n");
	queue_print(*q3);


	return true;
}

int main(int argc, char const *argv[])
{
	Queue* q = queue_init();
	queue_scanf( q);
	printf("当前随机列表\n");
	queue_print( *q);

/*1.用链式队列.用户从键盘中输入整数，
		程序将其入队，用户输入字母，程序将队头元素出队，并
		在每一次出队和入队之后打印队列元素*/
	// queue_DataIo( q);

/*2.设有一条链表,
		使用随机数给该链表添加30-50个节点
		每个节点的取值范围是1 - 1000之间
		需要把这一条链表进行有序的差分
		使用队列把这一条链表的1位数、2位数及3位数进行拆分
		出队时分别存放在3条链表中。*/
	queue_divide( q);

	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//定义一个节点
typedef struct lnode{
	int data;
	struct lnode* next;
}lnode, *linklist;

//初始化一个头节点
lnode* linklist_create()
{
	lnode* head = (lnode*)malloc(sizeof(lnode));

	if (head != NULL)
	{
		head->next = head;
		return head;
	}

	printf("插入失败!\n");
	return NULL;
}

//定义一个新节点
lnode* linklist_NewLnode(int data)
{
	lnode* new = (lnode*)malloc(sizeof(lnode));
	if (new != NULL)
	{
		new->data = data;
		new->next = new;
		return new;
	}

	printf("创建失败!\n");
	return NULL;
}


//尾插
void linklist_InsertTail(linklist head, linklist new)
{
	lnode* p = head;
    for (p = head; p->next != head; p = p->next);

    new->next = head;
	p->next = new;
}

//头插
void linklist_InsertHead(linklist head, linklist new)
{
	new->next = head->next;
	head->next = new;
}

//遍历
bool linklist_show(linklist head)
{
	if (head->next == head)
	{
		return false;
	}

	lnode* p = head;

	for ( p = head->next; p != head; p = p->next)
	{
		printf("%d\t", p->data);
	}

	printf("\n");
	return true;
}

//销毁整条链表
void linklist_delete(linklist head)
{
	lnode* p = head->next;

	while (p != head)
	{
		head->next = p->next;
		p->next = NULL;
		free(p);
		p = head->next;
	}
	free(head);
}

bool linklist_scanf(linklist head)
{
	if (head->next == NULL)
	{
		return false;
	}

	lnode* p = head;
	srand(time(NULL));

	int len = rand()%10+5;

	while (len--)
	{
		lnode* new = linklist_NewLnode( rand()%100+10);
        linklist_InsertTail( head, new);
	}

	return true;
}

//1.
bool linklist_find_max(linklist head)
{
	if ( head->next == head)
	{
		printf("创建失败!\n");
		return false;
	}

	int len = 0, num = 1;
	lnode* p = head;
    int max = head->next->data;

    for (p = head->next; p != head; p = p->next)
    {
    	len++;
    	if (max < p->data)
    	{
    		max = p->data;
    		num = len;
    	}
    }

    printf("第%d个节点值最大, %d\n", num, max);
    return true;
}

//3.
bool sort(linklist head)
{
	//判断,链表为空,则退出
	if (head->next == head)	
	{
		return false;  
	}

	//定义两个辅助指针
	lnode* pre = head;	//移动一次pre,p往其后遍历一次
	lnode* p = head;	//遍历

	int min = pre->data;	//把当前节点当最小值存放
	lnode* temp = pre;		//存放后续节点中最小值所在的节点地址
	for ( pre = head->next; pre != head; pre = pre->next)
	{
		min = pre->data;
		temp = pre;
		for ( p = pre->next; p != head; p = p->next)
		{
			if ( min > p->data)
			{
				min = p->data;
				temp = p;
			}
		}
		temp->data = pre->data;
		pre->data = min;
	}

	return true;
}

void linklist_insert_tail(linklist head, linklist new)
{
	lnode* p=head;
	for ( p=head; p->next!=head; p=p->next);
	new->next = p->next;
	p->next = new;
}

//4.
bool Dlinklist_reverse(linklist head)
{
	if (head->next == head || head->next->next == head)
	{
		return false;
	}

	int len=0;

	//找到链表中最后一个节点last
	lnode* last = head;
	for ( last=head->next; last->next!=head; last=last->next)
	{
		len++;
	}

	lnode* pre = head;
	lnode* p = head->next;

	while (len--)
	{
		while (p->next != head)
		{
			p=p->next;
			pre=pre->next;
		}
		pre->next = last;
		p->next = last;
        linklist_InsertHead(last, p);

        pre = head;
        p = head->next;
	}

	return true;

}

int main(int argc, char const *argv[])
{
	lnode* head = linklist_create();
    linklist_scanf( head);
    linklist_show( head);

	//1.创建一个有N个节 点的链表,找出这条链表的最大节点以及
	//它的编号属于多少分别已MAX_ DATA与MAX_ NODE进行记录。
	// linklist_find_max( head);

	//3.创建一个单向链表,插入数据完毕之后，从小到大排序。
    sort( head);
    printf("-------------------------------------------------\n");
    linklist_show( head);

    //4.
    // linklist_reverse( head);
    // linklist_show( head);

   
	return 0;
}
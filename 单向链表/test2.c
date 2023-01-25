#include <stdio.h>
#include <malloc.h>

#define elemtype int

typedef struct LNode{
	elemtype data;
	struct LNode* next;
}LNode, *linklist;

linklist linklist_Create()
{
	LNode* head = (LNode*)malloc(sizeof(LNode));
	if (head == NULL)
	{
		printf("创建失败!\n");
		return NULL;
	}

	head->next=NULL;
	return head;
}

int linklist_TailAdd(linklist head, elemtype num)
{
    LNode* new = (LNode*)malloc(sizeof(LNode));
    if (new == NULL)
    {
    	printf("新节点创建失败!\n");
    	return -1;
    }

    LNode* p = NULL;
    for (p=head; p->next!=NULL; p=p->next);
    
    p->next = new;
    new->next = NULL;
    new->data = num;

    return 1;

}

int linklist_print(linklist head)
{
	LNode* p = NULL;
    
    if (head == NULL)
    {
    	printf("链表为空!\n");
    	return -1;
    }
	for (p=head; p->next!=NULL; p=p->next)
	{
		printf("%d ", p->next->data);
	}

	printf("\n");
    return 1;
}

void linklist_Scanf(linklist head)
{
	int input = 0;
    
    printf("请输入要添加的数>");
    scanf("%d", &input);
	do
	{   
        linklist_TailAdd(head, input);
        linklist_print(head);
        printf("请输入要添加的数>");
        scanf("%d", &input);
	}while(input);
}

linklist linklist_Connect(linklist head1, linklist head2)
{
    LNode* p = NULL;
    for (p=head1; p->next!=NULL; p=p->next);

    p->next = head2->next;
    free(head2);

    return head1;
}


linklist linklist_partition(linklist head)
{
	int input = 0, flag = 0;
	LNode* p = NULL;
	printf("请输入起始数据>");
	scanf("%d", &input);
    
    for (p=head; p->next!=NULL; p=p->next)
    {
    	if (input == p->next->data)
    	{
    		flag = 1;
    		break;
    	}
    }

    if (flag)
    {
    	LNode* h = (LNode*)malloc(sizeof(LNode));
    	h->next = p->next;
    	p->next = NULL;
    	return h;
    }
    else
    {
    	printf("分割失败!\n"); 
    	return NULL;
    }
}

int linklist_Reverse(linklist head)
{
	if (head == NULL)
	{
		printf("表空,无法逆转!\n");
		return -1;
	}

	LNode *p=head, *pre=head->next;
	int temp=0, i=0;
    int len = 0, count = 0;

    // for (p=head; p->next!=NULL; p=p->next);
    //     temp = head->next;
    //     p->next = head->next;
    //     head->next  = temp->next;
    //     temp->next = NULL;
    
    for (p=head ; p->next!=NULL; p=p->next)
    {
    	len++;
    }

    //printf("len = %d\n", len);
    
    while (count <= len/2)
    {
    	p = head;
        for (i = 1; i<=len-count; i++)
        {
            p=p->next;
        }
        temp = pre->data;
        pre->data = p->data;
        p->data = temp;

        pre = pre->next;
        count++;
        //printf("count = %d\n", count);

    }

    return 1;
}

int linklist_Destroy(linklist head)
{
	if (head == NULL)
	{
		return -1;
	}

	LNode* p=head->next;
	while (p!=NULL)
	{
        head->next=p->next;
        free(p);
        p=head->next;
	}
	free(head);
    return 1;
}

int main(int argc, char const *argv[])
{
	LNode* L1 = linklist_Create();
	linklist_Scanf(L1);
 //    LNode* L2 = linklist_Create();
	// linklist_Scanf(L2);

	
	//linklist_print(linklist_partition(L1));

	linklist_Reverse(L1);
	linklist_print(L1);
	

	return 0;
}


//===========================链表的基础知识=======================================================
//
// typedef struct lnode{
// 	int data;
// 	struct lnode* next;
// }lnode, *linklist;

// linklist linklist_create()
// {
// 	lnode* L = (lnode*)malloc(sizeof(lnode));
// 	if (L == NULL)
// 	{
// 		printf("创建失败!\n");
// 		return NULL;
// 	}
// 	L->next = NULL;
// 	return L;
// }

// int linklist_print(linklist head)
// {
// 	if (head->next == NULL)
// 	{
// 		printf("链表为空!\n");
// 		return -1;
// 	}
//     lnode* p = head->next;
//     for (p=head->next; p!=NULL; p=p->next)
//     {
//     	printf("%d ", p->data);
//     }
//     printf("\n");
// }

// int linklist_HeadAdd(linklist L, elemtype num)
// {
//     lnode* new = (lnode*)malloc(sizeof(lnode));

//     if (new == NULL)
//     {
//     	printf("新节点创建失败!\n");
//         return -1;
//     }
//     new->data = num;
//     new->next = L->next;
//     L->next = new;
//     return 1;
// }

// int linklist_TailAdd(linklist L, elemtype num)
// {
// 	lnode* new = (lnode*)malloc(sizeof(lnode));
// 	if (new == NULL)
// 	{
// 		printf("新节点创建失败!\n");
// 		return -1;
// 	}
// 	lnode* p=NULL;
// 	for (p = L; p->next!=NULL; p = p->next);

// 	new->data = num;
//     p->next = new;
//     new->next = NULL;
//     return 1;
// }

// int linklist_OrderAdd(linklist L, elemtype num)
// {
// 	lnode* new = (lnode*)malloc(sizeof(lnode));
// 	if (new == NULL)
// 	{
// 		printf("新节点创建失败!\n");
// 		return -1;
// 	}

// 	new->data = num;
// 	lnode* p = NULL;

// 	for (p=L; p->next!=NULL; p=p->next)
// 	{
//         if (num < p->next->data)
//         {
//         	break;
//         }
// 	}

// 	new->next = p->next;
// 	p->next = new;

// 	return 1;
// }

// int linklist_SelectDelete(linklist L, elemtype num)
// {
//     if (L->next == NULL)
//     {
//     	printf("表空!\n");
//     	return -1;
//     }

//     lnode* p=NULL, *temp=NULL;
//     int flag = 0;

//     for (p = L; p->next!=NULL; p=p->next)
//     {
//         if (p->next->data == num)
//         {
//         	flag = 1;
//              break;   
//         }
//     }

//     if (flag)
//     {
// 	    temp=p->next;
// 	    p->next = p->next->next;
// 	    free(temp);
// 	    return 1;
//     }
//     else
//     {
//     	printf("输入错误!\n");
//     	return -1;
//     }
// }

// int linklist_Delete(linklist head)
// {
// 	if (head->next == NULL)
// 	{
// 		free(head);
// 		return -1;
// 	}

//     linklist temp=NULL, p=NULL;

//     for (p=head; p->next!=NULL; p=p->next)
//     {
//         temp = p->next;
//         head->next = temp->next;
//         free(temp);
//     }

//     free(head);
// }

// int main(int argc, char const *argv[])
// {
// 	lnode* L = linklist_create();
//     int input = 1;
// 	do
// 	{
// 		printf("请输入一个添加的数>");
// 		scanf("%d", &input);
// 		if (input == 0)
// 		{
// 			;
// 		}
// 		else
// 		{
//             linklist_OrderAdd(L, input);
//             linklist_print(L);
// 		}

// 	}while(input);

// 	linklist_Delete(L);
//     linklist_print(L);

// 	// input = 1;
// 	// do
// 	// {
// 	// 	printf("请输入一个删除的数>");
// 	// 	scanf("%d", &input);
// 	// 	if (input == 0)
// 	// 	{
// 	// 		;
// 	// 	}
// 	// 	else
// 	// 	{
//  //            linklist_Delete(L);
//  //            linklist_print(L);
// 	// 	}

// 	// }while(input);
// 	return 0;
// }
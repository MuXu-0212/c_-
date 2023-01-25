#include <stdio.h>
#include <malloc.h>

#define elemtype int

typedef struct DNode{
	elemtype data;
	struct DNode* prior, *next;
}DNode, *Dlinklist;


Dlinklist Dlinklist_Create()
{
	DNode* head = (DNode*)malloc(sizeof(DNode));
	if (head == NULL)
	{
		printf("新链表创建失败!\n");
		return NULL;
	}

	head->prior=head;
	head->next=head;

	return head;
}

int Dlinklist_TailAdd(Dlinklist head, elemtype num)
{
	DNode* new = (DNode*)malloc(sizeof(DNode));

	if (new == NULL)
	{
        printf("创建错误!\n");
        return -1;
	}

    DNode* p = head->prior;
    // DNode* temp = NULL;
    new->data = num;
    new->next = p->next;
    new->prior = p;
    head->prior = new;
    p->next = new;
    
    return 1;
}

int Dlinklist_HeadAdd(Dlinklist head, elemtype num)
{
	DNode* new = (DNode*)malloc(sizeof(DNode));

	if (new == NULL)
	{
		printf("新节点创建失败!\n");
		return -1;
	} 

    new->data = num;
    new->next = head->next;
    new->prior = head;
    head->next->prior = new;
    head->next = new;

    return 1;

}

int Dlinklist_OderAdd(Dlinklist head, elemtype num)
{
	DNode* new = (DNode*)malloc(sizeof(DNode));

	if (new == NULL)
	{
		printf("新节点创建失败!\n");
		return -1;
	}

	DNode* p = NULL;

	for (p=head; p->next!=head; p=p->next)
	{
		if ( num < p->next->data)
		{
			break;
		}
	}
    
    new->data = num;
    new->next = p->next;
    new->prior = p;
    p->next->prior = new;
    p->next = new;

}


void Dlinklist_Print(Dlinklist head)
{
	
	if (head->next == head )
	{
        printf("表空!\n");
	}
    else
    {
        DNode* p=head->next;
        while (p != head)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void Dlinklist_Scanf(Dlinklist head)
{
    int input = 0;
    
    printf("请输入要添加的数>");
    scanf("%d", &input);
	do
	{   
        Dlinklist_OderAdd(head, input);
        Dlinklist_Print(head);
        printf("请输入要添加的数>");
        scanf("%d", &input);
	}while(input);

}

int Dlinklist_Delete(Dlinklist head)
{
    elemtype input = 0, flag=0;

    printf("请输入要删除的数>");
    scanf("%d", &input);

    do
    {
        DNode* p = head;

        if (p->next == head)
	    {
	    	free(head);
	    	printf("双循环链表已销毁!\n");
	    	return 1;
	    }

        while (p->next!=head)
	    {
	    	
	    	if (p->next->data == input)
	    	{
	    		flag = 1;
	    		//printf("1\n");
	    		break;
	    	}
	    	p=p->next;
	    }
	    //printf("2\n");

	    if (flag)
	    {
	    	DNode* temp = p->next;
	    	temp->next->prior = p;
	    	p->next = temp->next;
	    	free(temp);
	    	//printf("3\n");
	    }
	    else
	    {
	    	printf("输入错误!\n");
	    }
        
        Dlinklist_Print(head);
    	printf("请输入要删除的数>");
        scanf("%d", &input);
	    
    }while(input);
    return 1;
}

int main(int argc, char const *argv[])
{
	DNode* L = Dlinklist_Create();
    
    Dlinklist_Scanf(L);
    Dlinklist_Print(L);
    
    Dlinklist_Delete(L);
    Dlinklist_Print(L);

	return 0;
}
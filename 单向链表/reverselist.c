#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode {
	int val;
	struct ListNode *next;
}linknode;

int linklist_tailadd(linknode* head, int data)
{
	linknode* new = (linknode*)malloc(sizeof(linknode));
	if (new != NULL)
	{
		new->next = NULL;
		new->val = data;
	}
	else
	{
		return 0;
	}

	linknode* p = head;

	for (p = head; p->next != NULL; p = p->next);

	p->next = new;
	
	return 1; 

}

int linklist_scanf(linknode* head)
{
	int input = 0;

	while (1)
	{
		printf("请输入一个数(-1为结束)>");
		scanf("%d", &input);

		if (input == -1)
		{
			return 0;
		}

		linklist_tailadd( head, input);
	}

	return 1;

}

void linklist_print(linknode* head)
{
	//printf("22222\n");
	linknode* p = head;
	for ( p=head; p->next != NULL ; p = p->next)
	{
		printf("%d\n", p->next->val);
	}
}


struct ListNode* inverseList(struct ListNode* pHead ) 
{
	if (pHead->next == NULL)
	{
		printf("表空\n");
		return NULL;
	}

    // write code here
    struct ListNode* head = pHead;
    struct ListNode* pre = head->next;
    struct ListNode* p = pre->next;
    struct ListNode* tail = head->next;
    
    while (p != NULL)
    {
    	// printf("55555\n");
    	tail->next = p->next;
        head->next = p;
        p->next = pre;

        // printf("p=%d\n", p->val);
        // printf("pre=%d\n", pre->val);

        p = tail->next;
        pre = head->next;
        
    }

    return head;

}


int main(int argc, char const *argv[])
{
	linknode* head = (linknode*)malloc(sizeof(linknode));

	linklist_scanf( head);
	linklist_print( head);

	printf("11111\n");

	ReverseList( head);
    linklist_print( head);
	return 0;
}

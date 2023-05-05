#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node_st,* node_p;

node_p head_init(void)
{
	node_p head = malloc(sizeof(node_st));
	if (head == NULL)
	{
		printf("malloc head failed\n");
		return NULL;
	}

	head->next = head;
	return head;
}

node_p new_node_init(int n)
{
	node_p new_node = malloc(sizeof(node_st));
	if (new_node == NULL)
	{
		printf("malloc new_node failed\n");
		return NULL;
	}
	new_node->data = n;
	new_node->next = new_node;
	return new_node;
}


void insert_tail(node_p head, node_p new_node)
{
	if (head->next == head)
	{
		head->next = new_node;
		new_node->next = head;
		return;
	}

	node_p pos = head;
	while(pos->next != head)
	{
		pos = pos->next;
	}

	pos->next = new_node;
	new_node->next = head;

}

void show_list(node_p head)
{
	if(head->next == head)
	{
		return;
	}
	node_p pos = head->next;
	while(pos != head)
	{
		printf("%d ", pos->data);
		pos = pos->next;
	}
	printf("\n");
}

//数三出局
void Three_out(node_p head,int n)
{
	if (head->next == head)
	{
		printf("没有人参与该游戏\n");
		return;
	}

	node_p tmp = NULL;
	node_p pos = head;

	int cont = 0;

	while(n != 1)
	{
		if(pos->next != head)
		{
			cont++;
		}
		else
		{
			pos = pos->next;
			continue;
		}

		if(cont % 3 == 0)
		{
			tmp = pos->next;
			pos->next = tmp->next;
			printf("出局数据为 %d\n",tmp->data);
			free(tmp);
			n--;
		}
		else
		{
			pos = pos->next;
		}
	}
	printf("剩余的人为：%d\n", head->next->data);
}


int main(int argc, char const *argv[])
{
	node_p head = head_init();

	int n;
	printf("请输入参与游戏的人数：\n");
	scanf("%d",&n);

	for (int i = 1; i <= n; ++i)
	{
		node_p new_node = new_node_init(i);
		insert_tail(head,new_node);
	}
	show_list(head);

	Three_out(head,n);
	free(head->next);
	free(head);

	return 0;
}
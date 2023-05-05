#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//设计节点
typedef struct node
{
	int data;
	struct node *next;
}node_s,*node_p;

//栈
typedef struct stack
{
	struct node *top;  //记录栈顶的节点
	int size;          //记录栈当中的节点个数
}stack_s,*stack_p;


//初始化栈
stack_p Creat_Stack(void)
{
	stack_p s = (stack_p)malloc(sizeof(stack_s));
	if (s != NULL)
	{
		s->size = 0;
		s->top  = NULL;
		return s;
	}
}

bool Is_Empty(stack_p s)
{
	return s->size == 0;
}

//入栈
bool Push(stack_p s,int data)
{
	//创建新的节点
	node_p new_node = (node_p)malloc(sizeof(node_s));
	if(new_node != NULL)
	{
		new_node->data = data;   //1,给新的节点赋值
		new_node->next = s->top; //2,用新节点的指针指向top 加入栈当中
		s->top = new_node;       //3,更新栈顶
		s->size++;               //4,总的节点个数据进行+1
		return true;
	}
	return false;
}

//出栈
bool Pop(stack_p s, int *m)
{
	if (Is_Empty(s))
	{
		return false;
	}
	
	node_p p = s->top;  		//1,记录即将要出栈的节点
	s->top   = s->top->next;	//2,更新栈顶位置
	s->size--;					//3,节点个数 -1
	*m = p->data;               //4,获取到即将要出栈的节点数据
	free(p);                    //释放节点

	return true;
}

int main(int argc, char const *argv[])
{
	stack_p s = Creat_Stack();
	int delete;
	printf("请输入一个数据\n");
	int data;
	scanf("%d",&data);

	while(data != 0)
	{
		if(Push(s, data % 2))
		{
			data = data / 2 ;
		}
		else
		{
			while(Pop(s,&delete));
			free(s);
		}
	}

	while(Pop(s,&delete))
	{
		printf("%d ",delete);
	}

	printf("\n");


	return 0;
}

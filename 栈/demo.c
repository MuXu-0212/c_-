#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//设计栈
typedef struct stack
{
	int size; //栈的总大小
	int last; //用于记录下标的
	int *stack_addr; //记录栈空间的首地址
}stack_s,*stack_p;

//创建出一个栈
stack_p Creat_Stack(int size)
{
	stack_p stack = (stack_p)malloc(sizeof(stack_s));
	if (stack != NULL)
	{
		//初始化
		stack->size = size;
		stack->last = -1;
		//申请一个栈空间用于存放数据
		stack->stack_addr = (int *)calloc(size,sizeof(int));
		if (stack->stack_addr == NULL)
		{
			free(stack);
			return NULL;
		}
		return stack;
	}
}
//判断栈是否为满
bool Is_Full(stack_p stack)
{
	if (stack->last == stack->size -1)
	{
		return true;
	}
	return false;
}
//判断栈是否为NULL
bool Is_Empty(stack_p stack)
{
	if (stack->last == -1)
	{
		return true;
	}
	return false;
}
//插入数据了
bool Push(stack_p stack, int data)
{
	//先判断该栈是否为满
	if (Is_Full(stack))
	{
		printf("栈已满,无法插入数据\n");
		return false;
	}

	//原本下标为-1,每添加一个数据进行+1操作
	stack->last++;
	stack->stack_addr[stack->last] = data;
	return true; //如果函数结束没有返回真,那么该函数默认返回假(false);
}
//出栈
bool Pop(stack_p stack,int *m)
{
	//判断站是否为空
	if (Is_Empty(stack))
	{	
		printf("\n栈已空,没有数据了！~\n");
		return false;
	}
	//记录即将要出栈的数据
	*m = stack->stack_addr[stack->last];
	//last应该往栈底移动一位
	stack->last--;

	return true;
}

bool Show_Stack(stack_p stack)
{
	if (Is_Empty(stack))
	{
		return false;
	}

	for (size_t i = 0; i <= stack->last; i++)
	{
		printf("%d ",stack->stack_addr[i]);
	}
	printf("\n");
	return true;
}

int main(int argc, char const *argv[])
{
	stack_p stack = Creat_Stack(10);
	int data;
	printf("请输入一个数据\n");
	scanf("%d",&data);
	//压栈
	while (data != 0)
	{
		if(Push(stack,data%2) == false)
		{
			break;
		}
		data = data / 2;
	}
	int m;
	//出栈
	while (1)
	{
		if(Pop(stack, &m) == true)
		{
			printf("%d ",m);
		}
		else
		{
			break;
		}
	}
	
	free(stack->stack_addr);
	free(stack);

	return 0;
}

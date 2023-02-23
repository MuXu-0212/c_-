#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//定义一个链栈
typedef struct stack{
	int maxsize;
	int last;
	int* pointer;
}stack, *linkstack;

//链栈的初始化
stack* linkstack_create(int size)
{
	stack* s = (stack*)malloc(sizeof(stack));
	if (s != NULL)
	{
		s->maxsize = size;
		s->last = -1;

		s->pointer = (int*)calloc(size, sizeof(int));
	    if (s->pointer == NULL)
		{
			free(s);
			return NULL;
		}

		return s;
	}
	return NULL;
} 

//判断链栈是否满
bool linkstack_Is_Full(linkstack stack)
{
	if (stack->last == stack->maxsize-1)
	{
		return true;
	}
	return false;
}

//判断链栈是否空
bool  linkstack_Is_Empty(linkstack stack)
{
	if (stack->last == -1)
	{
		return true;
	}
	return false;
}

//入栈
bool Push(linkstack stack, int data)
{
	if (linkstack_Is_Full(stack))
	{
		return false;
	}
	stack->pointer[++stack->last] = data;
	return true;
}

//出栈
bool Pop(linkstack stack, int* data)
{
	if (linkstack_Is_Empty(stack))
	{
		// printf("栈空!\n");
		return false;
	}
	*data = stack->pointer[stack->last--];
	return true;
}

//打印链栈
bool stack_print(linkstack stack)
{
	int i=0;

	for (i=0; i<=stack->last; i++)
	{
		printf("%d ", stack->pointer[i]);
	}
	printf("\n");
	return true;
}

//链栈随机赋值
bool stack_scanf(linkstack stack)
{
	if (linkstack_Is_Full(stack))
	{
		return false;
	}
    
    srand(time(NULL));
    int i=0;
    for (i=0; i<10; i++)
    {
    	Push(stack, rand()%100+5);
    }
}

//用链栈转换十六进制数
bool stack_convertion(linkstack stack)
{
    int num=0;
    printf("请输入一个数>");
    scanf("%d", &num);

    //入栈
    while (num != 0)
    {
        if (Push(stack, num%16) == false)
        {
        	break;
        }
        num /= 16;
    }
    printf("0x");
    //出栈
    while (Pop(stack, &num) == true)
    {
    	printf("%X", num);
    }
    printf("\n");

    return true;
}

int main(int argc, char const *argv[])
{
	//用栈将十进制数转换为十六进制
	stack* s = linkstack_create(10);
	stack_convertion( s);
	// stack_scanf( s);
	// stack_print( s);
	return 0;
}

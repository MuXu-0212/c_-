#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5   

//1.设计队列
typedef struct sequeue
{
	int data[SIZE];		//整个顺序队列大小
	int front;  		//记录队首的下标元素
	int rear;   		//记录队尾的下标元素
}seq_s,*seq_p;


//创建一个队列
seq_p Creat_Sequeue(void)
{
	seq_p sq = (seq_p)malloc(sizeof(seq_s));
	if (sq != NULL)
	{
		sq->front = SIZE-1; 
		sq->rear  = SIZE-1;
		return sq;
	}
}

bool Is_Full(seq_p sq)
{
	return (sq->rear + 1) % SIZE == sq->front;
}

bool Is_Empty(seq_p sq)
{
	return sq->rear == sq->front;
}

//入队
bool Inset_Queue(seq_p sq,int data)
{
	if (Is_Full(sq))
	{
		return false;
	}
	//1.移动队尾的下标
	sq->rear = (sq->rear +1 ) % SIZE;
	//2.将数据进行存放
	sq->data[sq->rear] = data;
	return true;
}

//出队
bool Out_Queue(seq_p sq,int *data)
{
	if (Is_Empty(sq))
	{
		return false;
	}
	//1.移动front下标,再进行释放数据
	sq->front = (sq->front + 1) % SIZE;
	//2.取出值
	*data = sq->data[sq->front];
	return true;
}


//遍历
bool Show_Queue(seq_p sq)
{
	if (Is_Empty(sq))
	{
		return false;
	}

	int i;
	for (i = (sq->front + 1)% SIZE ; i != sq->rear; i = (i + 1)%SIZE)
	{
		printf("%d ",sq->data[i]);
	}
	printf("%d\n",sq->data[i]);
	return true;
}



int main(int argc, char const *argv[])
{
	seq_p sq = Creat_Sequeue();

	return 0;
}

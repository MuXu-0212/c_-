#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX 10

//1.设计顺序表
typedef struct list
{
	int arr[MAX];
	int last;  	//记录已经储存的最后一个下标元素
}list_s, *list_p;


//2.初始化数据
list_p Init_List(void)
{
	list_p p = (list_p)malloc(sizeof(list_s));
	if (p != NULL)
	{
		memset(p->arr, 0 , sizeof(p->arr));
		p->last = -1;
		return p;
	}
	return NULL;
}


bool Is_Full(list_p list)
{
	if (list->last == MAX-1)
	{
		return true;
	}
	return false;
}

bool Is_Empty(list_p list)
{
	if (list->last == -1)
	{
		return true;
	}
	return false;
}

//添加数据
bool Inset_Data_List(list_p list, int data)
{
	if (Is_Full(list) != true)
	{
		list->last++;
		list->arr[list->last] = data;
		return true;
	}
	return false;
}

//遍历
void Show_List(list_p list)
{
	if (Is_Empty(list) != true)
	{
		for (int i = 0; i <= list->last; ++i)
		{
			printf("%d\t", list->arr[i]);
		}
		printf("\n");
	}
}


int main(int argc, char const *argv[])
{
	list_p list = Init_List();


	for (int i = 0; i < MAX; ++i)
	{
		Inset_Data_List(list, i + 1);
	}

	Show_List(list);
	return 0;
}
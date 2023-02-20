#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//定义一个顺序表
typedef struct sqlist{
    int last;
    int maxsize;
    int* data;
}list, *sqlist;

//顺序表初始化
list* sqlist_init(int maxsize)
{
	 
	list* head = (list*)malloc(sizeof(list));
	if (head == NULL)
	{
		printf("头节点创建失败!\n");
		return NULL;
	}

	// printf("22222\n");
	head->maxsize = maxsize;
	head->last = -1;

	head->data = (int*)calloc(maxsize, sizeof(int));
	if (head->data == NULL)
	{
		printf("堆空间申请失败!\n");
		return NULL;
	}

	return head;
}


//判断是否表满
bool sqlist_IsFull( sqlist head)
{
	if (head->last >= head->maxsize)
	{
		printf("表满!\n");
		return true;
	}
	return false;
}


//判断是否表空
bool sqlist_IsEmpty( sqlist head)
{
	if ( head->last == -1)
	{
		printf("表空!\n");
		return true;
	}
	return false;
}

//插入数据
bool sqlist_InsertData(sqlist head, int data)
{
	if(sqlist_IsFull(head))
	{
		printf("添加失败!\n");
		return false;
	}
	// printf("44444\n");
	// printf("%d\n", head->last);
	head->last++;
	head->data[head->last] = data;
	return true;
}

//删除数据
bool sqlist_DeleteData(sqlist head, int data)
{
    if ( sqlist_IsEmpty(head) )
    {
    	printf("删除:表空!\n");
    	return false;
    }

    for (int i=0; i <= head->maxsize; i++)
    {
    	if (head->data[i] == data)
    	{
    		for (int j=i; j<head->maxsize; j++)
    		{
    			head->data[j] = head->data[j+1];
    		}

    		head->last--;
    		printf("删除成功!\n");
    		return true;
    	}
    }

    printf("删除失败!\n");
    return false;
}

bool sqlist_FindData( sqlist head, int data)
{
	if ( sqlist_IsEmpty( head))
	{
		printf("查找:表空!\n");
		return false;
	}
	for (int i=0; i<head->maxsize; i++)
	{
		if (head->data[i] == data)
		{
			printf("该数据在第%d个位置\n", i+1);
			return true;
		}
	}
    
    printf("未找到该数据!\n");
	return false;
}

bool sqlist_revise(sqlist head, int data)
{
	if ( sqlist_IsEmpty(head))
	{
		printf("修改:表空!\n");
		return false;
	}

	for (int i=0; i<head->maxsize; i++)
	{
		if (head->data[i] == data)
		{
			int input = 0;
			printf("请输入要改成的值>");
			scanf("%d", &input);
			head->data[i] = input;
			printf("修改成功!\n");
			return true;
		}
	}

	printf("修改失败!\n");
	return false;
}

bool sqlist_print(sqlist head)
{
	if ( sqlist_IsEmpty(head) )
	{
		printf("打印:表空!\n");
		return false;
	}

	// printf("33333\n");

	for (int i=0; i<head->maxsize; i++)
	{
		printf("%d\t", head->data[i]);
	}
	printf("\n");
	return true;
}

bool sqlist_scanf(sqlist head)
{
	if ( sqlist_IsFull(head) )
	{
		printf("表满,无法添加!\n");
		return false;
	}

	 // printf("11111\n");
	int input = 0;
	for (int i=0; i<=head->maxsize; i++)
	{
		sqlist_InsertData( head, i+2);
	}
	return true;
}


int main(int argc, char const *argv[])
{
	int num = 0;

	printf("请输入元素个数>");
	scanf("%d", &num);
	list* head = sqlist_init(num);
	// printf("head->data[1]:%d\n", head->data[1]);

	sqlist_scanf( head);
	sqlist_print( head);


	return 0;
}


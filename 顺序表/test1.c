#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 20

typedef struct sqlist{
	int data[MAXSIZE];
    int length;
}sqlist, *sql;


void sqlist_print(sql sq)
{
	int i = 0 ;
	for (i = 0; i < sq->length; i++)
	{
        printf("%d ", sq->data[i]);
	}
	printf("\n");
}


sql sqlist_create()
{
	sql sq = (sqlist*)malloc(sizeof(sqlist));
	sq->length = 0;
	return sq;
}

int sqlist_Add(sql sq, int i)
{
	if (sq->length == MAXSIZE)
	{
		printf("表满!\n");
		return 0;
	}
	sq->data[sq->length++] = i;
    return 1;
}

int sqlist_Delete(sql sq)
{
	if (sq->length == 0)
	{
		printf("表空!\n");
		return 0;
	}
    
    int j = 0, k = 0, n = 0, exit = 1, flag = 1;
    do
    {
        printf("需要删除的数>");
        scanf("%d", &n);

        if (n < 0)
        {
        	n = -1*n;
        }
        if (n == 0)
        {
            exit = 0;
        }
        else
        {
		    for (j = 0; j<sq->length; j++)
		    {
		    	if (sq->data[j] == n)
		    	{
		    		flag = 0;
		    		for (k = j; k < sq->length-1; k++)
		    		{
		                sq->data[k] = sq->data[k+1];
		                //printf("\ndata[%d]%d \n", k, sq->data[j]);
		    		}
		    		sq->length--;
		    		sqlist_print(sq);
		    	}
		    }
		    if (flag)
		    {
		    	printf("没有该数!\n");
		    }        	
        }
    }while(exit);

    return 1;
}


void sqlist_Destroy(sql sq)
{
	free(sq);
}

void sqlist_scanf(sql sq)
{
	int n = 0, exit = 1;
	do
	{
		printf("请输入一个数(0结束)>");
		scanf("%d", &n);
		if (n == 0)
		{
			exit = 0;
		}
		else
		{
			sqlist_Add(sq, n);
			sqlist_print(sq);
		}
	}while(exit);
}



int main(int argc, char const *argv[])
{
	sql sq = sqlist_create();
	sqlist_scanf(sq);
    
    sqlist_Delete(sq);

    sqlist_Destroy(sq);
    sqlist_print(sq);

	return 0;
}
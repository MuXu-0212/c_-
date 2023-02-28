#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "drawtree.h"

//设计二叉树节点
typedef struct tree_node
{
	int data;
	struct tree_node *left;   //指向左
	struct tree_node *right;  //指向右
	
}tree_s, *tree_p;

//初始化根节点
tree_p Creat_Tree_Node(int data)
{
	tree_p node = (tree_p)malloc(sizeof(tree_s));
	if(node != NULL)
	{
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	return NULL;
} 
//插入
int Inset_Node_Tree(tree_p root, int data)
{
	tree_p new_node = Creat_Tree_Node(data);
	if(new_node == NULL)
	{
		return -1;
	}
	tree_p p = root;
	while(1)
	{
		if(new_node->data < root->data)
		{
			if(p->left != NULL)
			{
				p = p->left;
			}
			else
			{
				p->right = new_node;
				return 1;
			}
			root->left = new_node;
		}
		else if(new_node->data > root->data)
		{
			if(new_node->data > root->data)
			{
				if(p->right != NULL)
				{
					p = p->right;
				}
				else
				{
					p->right = new_node;
					return 1;
				}
			}
		}
	}
}

//递归插入
tree_p Inset_Node_Tree_Dg(tree_p root, int data)
{
	if(root == NULL)
	{
		return Creat_Tree_Node(data);
	}
	else if(data < root->data)
	{
		root->left = Inset_Node_Tree_Dg(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = Inset_Node_Tree_Dg(root->right, data);
	}
	else
	{
		printf("节点数据重复，无法插入\n");
	}
	return root;
}


tree_p Find_Node_Dg(tree_p root, int data)
{
	if(root == NULL || root->data == data)
	{
		return root;
	}
	if(data < root->data)
	{
		return Find_Node_Dg(root->left, data);
	}
	return Find_Node_Dg(root->right, data);
}

tree_p Detele_Node(tree_p tree, int data)
{
	if(tree == NULL)
	{
		return tree;
	}
	if(data < tree->data)
	{
		tree->left = Detele_Node(tree->left, data);
	}
	else if(data > tree->data)
	{
		tree->right = Detele_Node(tree->right, data);
	}
	//已找到需删除数据位置
	else
	{
		tree_p temp = NULL;
		if(tree->left != NULL)
		{
			temp = temp->left;
			while(temp->left != NULL)
			{
				temp = temp->right;
			}
			tree->data = temp->data;
			tree->left = Detele_Node(tree->left,temp->data);
		}
		else if(tree->right != NULL)
		{
			temp = tree->right;
			while(temp->right != NULL)
			{
				temp = temp->right;
			}
			tree->data = temp->data;
			tree->right = Detele_Node(tree->right,temp->data);
		}
		else
		{
			free(tree);
			return NULL;
		}
	}
}

//先序遍历
void preorder(tree_p root)
{
	if(root != NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
//中序遍历
void inrder(tree_p root)
{
	if(root != NULL)
	{
		inrder(root->left);
		printf("%d ",root->data);
		inrder(root->right);
	}
}
//后序遍历
void postorder(tree_p root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

//在二叉排序树中插入关键字为k的新结点（递归）
//最坏空间复杂度：O(h)
bool BST_Insert(tree_p* T, int k){
   if((*T)==NULL){           //原树为空，新插入的结点为根结点
      (*T) = (tree_p)malloc(sizeof(tree_s));
      (*T)->data = k;
      // printf("k=%d\n", k);
      (*T)->left = (*T)->right = NULL;
      return true;                       //插入成功
   }
   else if( k == (*T)->data)               //树中存在相同关键字的结点，插入失败
      return false;
   else if(k < (*T)->data)                 
      return BST_Insert(&(*T)->left,k);
   else 
      return BST_Insert(&(*T)->right,k);
}

int main(int argc, char const *argv[])
{
	// printf("0000\n");
	tree_p root = Creat_Tree_Node(5);
	tree_p p = root;

	// Inset_Node_Tree_Dg(p,2);
	// Inset_Node_Tree_Dg(p,9);
	// Inset_Node_Tree_Dg(p,0);
	// Inset_Node_Tree_Dg(p,4);
	// Inset_Node_Tree_Dg(p,3);
	// Inset_Node_Tree_Dg(p,7);
	// Inset_Node_Tree_Dg(p,8);

	BST_Insert(&root,2);
	BST_Insert(&root,9);
	BST_Insert(&root,0);
	BST_Insert(&root,4);
	BST_Insert(&root,3);
	BST_Insert(&root,7);
	BST_Insert(&root,8);

	// preorder(p);
	// printf("\n");

	// inrder(p);
	// printf("\n");

	postorder(p);
	printf("\n");

	// draw(p);

	return 0;
}

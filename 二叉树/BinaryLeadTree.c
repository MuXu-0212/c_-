#include <stdio.h>
#include <stdlib.h>



//二叉线索树
#include <stdio.h>
#include <stdlib.h>
// 定义二叉线索树结点
typedef struct ThreadedNode {
    int data;                  // 数据
    struct ThreadedNode* left; // 左子树指针
    struct ThreadedNode* right; // 右子树指针
    int ltag;                  // 左标志
    int rtag;                  // 右标志
} ThreadedNode;
// 定义全局变量
ThreadedNode* pre = NULL;
// 中序遍历二叉树，并进行线索化
void InOrderThread(ThreadedNode* p) {
    if (p != NULL) {
        InOrderThread(p->left);    // 递归遍历左子树
        if (p->left == NULL) {     // 如果没有左子树，将左指针指向前驱结点
            p->left = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->right == NULL) {  // 如果前驱结点没有右子树，将右指针指向当前结点
            pre->right = p;
            pre->rtag = 1;
        }
        pre = p;                   // 更新前驱结点
        InOrderThread(p->right);   // 递归遍历右子树
    }
}
// 创建二叉线索树
ThreadedNode* CreateThreadedTree() {
    ThreadedNode* root = (ThreadedNode*)malloc(sizeof(ThreadedNode));
    root->data = 1;
    ThreadedNode* node2 = (ThreadedNode*)malloc(sizeof(ThreadedNode));
    node2->data = 2;
    root->left = node2;
    ThreadedNode* node3 = (ThreadedNode*)malloc(sizeof(ThreadedNode));
    node3->data = 3;
    root->right = node3;
    node2->left = NULL;
    node2->right = NULL;
    node2->ltag = 0;
    node2->rtag = 0;
    node3->left = NULL;
    node3->right = NULL;
    node3->ltag = 0;
    node3->rtag = 0;
    return root;
}
// 中序遍历二叉线索树
void InOrderTraverse(ThreadedNode* root) {
    ThreadedNode* p = root->left;   // 指向第一个结点
    while (p != root) {
        while (p->ltag == 0) {      // 如果左标志为0，继续往左遍历
            p = p->left;
        }
        printf("%d ", p->data);      // 输出结点数据
        while (p->rtag == 1 && p->right != root) { // 如果右标志为1，继续往右遍历
            p = p->right;
            printf("%d ", p->data);  // 输出结点数据
        }
        p = p->right;               // 指向下一个结点
    }
}
int main() {
    ThreadedNode* root = CreateThreadedTree();
    root->left->right = root;
    root->left->rtag = 1;
    root->right->left = root;
    root->right->ltag = 1;
    InOrderThread(root);            // 中序遍历二叉树，并进行线索化
    InOrderTraverse(root);          // 中序遍历二叉线索树
    printf("\n");
    return 0;
}


/*
//链表的增删改查
// 定义链表结点
typedef struct ListNode {
    int data;               // 数据
    struct ListNode* next;  // 指向下一个结点的指针
} ListNode;
// 创建链表
ListNode* CreateList() {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); // 创建头结点
    head->next = NULL;      // 头结点的指针指向NULL
    return head;
}
// 添加结点
void AddNode(ListNode* head, int data) {
    ListNode* p = head;     // 指向头结点
    while (p->next != NULL) {   // 找到最后一个结点
        p = p->next;
    }
    ListNode* node = (ListNode*)malloc(sizeof(ListNode)); // 创建新结点
    node->data = data;      // 存储数据
    node->next = NULL;      // 新结点的指针指向NULL
    p->next = node;         // 插入到链表末尾
}
// 删除结点
void DeleteNode(ListNode* head, int data) {
    ListNode* p = head;     // 指向头结点
    while (p->next != NULL && p->next->data != data) {    // 找到要删除的结点
        p = p->next;
    }
    if (p->next != NULL) {  // 如果找到了要删除的结点
        ListNode* temp = p->next;   // 暂存要删除的结点
        p->next = temp->next;       // 从链表中删除结点
        free(temp);                 // 释放结点的内存
    }
}
// 修改结点
void ModifyNode(ListNode* head, int oldData, int newData) {
    ListNode* p = head;     // 指向头结点
    while (p->next != NULL && p->next->data != oldData) {   // 找到要修改的结点
        p = p->next;
    }
    if (p->next != NULL) {  // 如果找到了要修改的结点
        p->next->data = newData;    // 修改结点的数据
    }
}
// 查找结点
ListNode* FindNode(ListNode* head, int data) {
    ListNode* p = head->next;   // 指向第一个结点
    while (p != NULL && p->data != data) {  // 找到要查找的结点
        p = p->next;
    }
    return p;   // 返回结点指针
}
// 输出链表
void PrintList(ListNode* head) {
    ListNode* p = head->next;   // 指向第一个结点
    while (p != NULL) {         // 遍历链表
        printf("%d ", p->data); // 输出结点数据
        p = p->next;
    }
    printf("\n");
}
int main() {
    ListNode* head = CreateList();  // 创建链表
    AddNode(head, 1);              // 添加结点
    AddNode(head, 2);
    AddNode(head, 3);
    AddNode(head, 4);
    printf("原链表：");
    PrintList(head);               // 输出原链表
    DeleteNode(head, 2);           // 删除结点
    printf("删除结点后：");
    PrintList(head);               // 输出删除结点后的链表
    ModifyNode(head, 1, 5);        // 修改结点
    printf("修改结点后：");
    PrintList(head);               // 输出修改结点后的链表
    ListNode* node = FindNode(head, 5); // 查找结点
    if (node != NULL) {
        printf("查找到结点：%d\n", node->data);
    } else {
        printf("未找到结点\n");
    }
    return 0;
}
*/


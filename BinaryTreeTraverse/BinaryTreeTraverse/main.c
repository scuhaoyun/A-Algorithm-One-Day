//
//  main.c
//  BinaryTreeTraverse
//
//  Created by 郝赟 on 16/6/2.
//  Copyright © 2016年 haoyun. All rights reserved.
//参考:http://blog.csdn.net/sjf0115/article/details/8645991

#include <stdio.h>
#include <stdlib.h>
//二叉树定义
typedef struct BinaryNode{
    char data;
    struct BinaryNode *lchild,*rchild;
}BinaryNode,*BinaryTree;

//按照先序序列创建二叉树
BinaryTree createBinaryTree(BinaryTree T)
{
    char ch;
    ch=getchar();
    if(ch=='#')T = NULL;
    else
    {
        if(!(T=(BinaryNode *)malloc(sizeof(BinaryNode))))
            printf("Error!");
        T->data=ch;
        T->lchild = createBinaryTree(T->lchild);
        T->rchild = createBinaryTree(T->rchild);
    } 
    return T;  
}//先序遍历:递归
void preOrder(BinaryTree T){
    if (T != NULL) {
        printf("%c ",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}
//中序遍历:递归
void midOrder(BinaryTree T){
    if (T != NULL) {
        midOrder(T->lchild);
        printf("%c ",T->data);
        midOrder(T->rchild);
    }
}
//后序遍历:递归
void lastOrder(BinaryTree T){
    if (T != NULL) {
        lastOrder(T->lchild);
        lastOrder(T->rchild);
        printf("%c ",T->data);
    }
}
//层次遍历
/*第一种方法，就是利用递归的方法，按层进行打印，我们把根节点当做第0层，之后层次依次增加，如果我们成功的打印了给定的层次，那么就返回非0
 的正值，如果失败返回0。有了这个思路，我们就可以应用一个循环，来打印这颗树的所有层的节点，但是有个问题就是我们不知道这棵二叉树的深度，
 怎么来控制循环使其结束呢，仔细看一下print_at_level，如果指定的Tree是空的，那么就直接返回0，当返回0的时候，我们就结束循环，说明没有
 节点可以打印了。
void print_by_level_1(Tree T) {
    int i = 0;
    for (i = 0; ; i++) {
        if (!print_at_level(T, i))
            break;
    }
    cout << endl;
}
void print_by_level_2(Tree T) {
    deque<tree_node_t*> q_first, q_second;
    q_first.push_back(T);
    while(!q_first.empty()) {
        while (!q_first.empty()) {
            tree_node_t *temp = q_first.front();
            q_first.pop_front();
            cout << temp->data << " ";
            if (temp->lchild)
                q_second.push_back(temp->lchild);
            if (temp->rchild)
                q_second.push_back(temp->rchild);
        }
        cout << endl;
        q_first.swap(q_second);
    }
  }
}
*/
//第二种方法，用数组模拟队列。首先将树的根节点入队，每次执行出队操作，并将出队的左右结点入队，直到队列中没有元素为止。
void LevelTraverse(BinaryNode *root)
{
    if(root == NULL)
        return;
    BinaryNode* a[30];
    a[0] = root;
    int beg = 0;     //表示该层的第一个元素
    int end = 0;     //表示该层的最后一个元素
    int pos_end = 0; //表示目前访问的元素存放的位置
    while(beg <= end)
    {
        if(a[beg]->lchild != NULL)
            a[++pos_end] = a[beg]->lchild;
        if(a[beg]->rchild != NULL)
            a[++pos_end] = a[beg]->rchild;
        printf("%c ",a[beg]->data);
        ++beg;
        if(beg > end)
        {
            end = pos_end;
            printf("\n");
        }
    }
}
//输入:ABC##DE#G##F###
int main(int argc, const char * argv[]) {
    BinaryTree T;
    T = createBinaryTree(T);
    printf("先序遍历序列:");
    preOrder(T);
    printf("中序遍历序列:");
    midOrder(T);
    printf("后序遍历序列:");
    lastOrder(T);
    printf("层次遍历序列:");
    LevelTraverse(T);

    printf("\n");
    return 0;
}

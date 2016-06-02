//
//  main.c
//  BinaryTreeTraverse
//
//  Created by 郝赟 on 16/6/2.
//  Copyright © 2016年 haoyun. All rights reserved.
//

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

int main(int argc, const char * argv[]) {
    BinaryTree T;
    T = createBinaryTree(T);
    printf("先序遍历序列:");
    preOrder(T);
    printf("中序遍历序列:");
    midOrder(T);
    printf("后序遍历序列:");
    lastOrder(T);
    printf("\n");
    return 0;
}

//
//  main.c
//  寻找单链表中环的入口
//
//  Created by 郝赟 on 16/6/4.
//  Copyright © 2016年 haoyun. All rights reserved.
//
/*
寻找链表中环的起始位置
解法如下：
定义两个指针：p1和p2，当p2按照每次2步，p1每次一步的方式走，发现p2和p1重合，确定了单向链表有环路了。
接下来，让p2回到链表的头部，重新走，每次步长不是走2了，而是走1，那么当p1和p2再次相遇的时候，就是环路的入口了。
证明:在p2和p1第一次相遇的时候，假定p1走了n步骤，环路的入口是在p步的时候经过的，那么有
p1走的路径： p+c ＝ n；        (1)  c为p1和p2相交点，距离环路入口的距离
p2走的路径： p+c+k*L = 2*n；   (2) L为环路的周长，k是整数
显然，如果从p+c点开始，p1再走n步骤的话，还可以回到p+c这个点。原因:将(1)代入（2）可得k*L=n,即n为环的步数的整数倍
同时p2从头开始走的话，经过n步，也会达到p+c这点，原因:(1)
显然在这个步骤当中p1和p2只有前p步骤走的路径不同，所以当p1和p2再次重合的时候，必然是在链表的环路入口点上。原因:环的终点相同，
起点也肯定相同
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode{
    int data;
    struct ListNode *next;
}*List,ListNode;
//使用一个数组创建包含环的单向链表，loopPort为环入口的下标，从0开始
ListNode* createLoopList(int *array, int length, int loopPort){
    if (length < 1 || length - 1 < loopPort || loopPort < 0) {
        return NULL;
    }
    ListNode *head = (List)malloc(sizeof(ListNode));
    head->data = array[0];
    ListNode *foreTemp = head;
    ListNode *portNode = NULL;
    for (int i = 1; i < length; i++) {
        ListNode *node = (List)malloc(sizeof(ListNode));
        node->data = array[i];
        if (foreTemp) {
            foreTemp->next = node;
        }
        if (i == loopPort) {
            portNode = node;
        }
        foreTemp = node;
    }
    foreTemp->next = portNode;
    return head;
}
//寻找单链表中环的入口
ListNode* findLoopPortInList(ListNode *head){
    if (head == NULL) {
        return NULL;
    }
    //第一步，找出相遇的环中的节点
    ListNode *x = head;
    ListNode *y = head;
    do{
        x = x->next;
        y = y->next->next;
    }while (x != y && y != NULL);
    if (x == NULL || y == NULL) {
        return NULL;
    }
    //第二部，将每次移动两部的指针移动到头结点，每次移动一步
    y = head;
    do{
        x = x->next;
        y = y->next;
    }while(x != y);
    return x;
}
int main(int argc, const char * argv[]) {
    int data[25] = {1,56,89,4,5,69,5,2,78,5,989,63,9,8,7,9,89,56,8,9,56,78,51,23,47};
    int count = sizeof(data)/sizeof(data[0]);
    List head = createLoopList(data, count, 15);
    ListNode *portNode = findLoopPortInList(head);
    printf("环的入口节点的值为:%d",portNode->data);
    printf("\n");
    return 0;
}

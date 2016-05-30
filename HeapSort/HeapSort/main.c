//
//  main.c
//  HeapSort
//
//  Created by 郝赟 on 16/5/30.
//  Copyright © 2016年 haoyun. All rights reserved.
/*
1.堆
堆实际上是一棵完全二叉树，其任何一非叶节点满足性质：
Key[i]<=key[2i+1]&&Key[i]<=key[2i+2]或者Key[i]>=Key[2i+1]&&key>=key[2i+2]
即任何一非叶节点的关键字不大于或者不小于其左右孩子节点的关键字。
堆分为大顶堆和小顶堆，满足Key[i]>=Key[2i+1]&&key>=key[2i+2]称为大顶堆，满足 Key[i]<=key[2i+1]&&Key[i]<=key[2i+2]称为小顶堆。
由上述性质可知大顶堆的堆顶的关键字肯定是所有关键字中最大的，小顶堆的堆顶的关键字是所有关键字中最小的。

2.堆排序的思想
利用大顶堆(小顶堆)堆顶记录的是最大关键字(最小关键字)这一特性，使得每次从无序中选择最大记录(最小记录)变得简单。
其基本思想为(大顶堆)：
1)将初始待排序关键字序列(R1,R2....Rn)构建成大顶堆，此堆为初始的无序区；
2)将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,......Rn-1)和新的有序区(Rn),且满足R[1,2...n-1]<=R[n];
3)由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,......Rn-1)调整为新堆，然后再次将R[1]与无序区最后一个元素交换，
得到新的无序区(R1,R2....Rn-2)和新的有序区(Rn-1,Rn)。不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。
操作过程如下：
1)初始化堆：将R[1..n]构造为堆；
2)将当前无序区的堆顶元素R[1]同该区间的最后一个记录交换，然后将新的无序区调整为新的堆。
因此对于堆排序，最重要的两个操作就是构造初始堆和调整堆，其实构造初始堆事实上也是调整堆的过程，只不过构造初始堆是对所有的非叶节点都进行调整。
 
3.堆排序其实也是一种选择排序，是一种树形选择排序。只不过直接选择排序中，为了从R[1...n]中选择最大记录，需比较n-1次，然后从R[1...n-2]中选择
最大记录需比较n-2次。事实上这n-2次比较中有很多已经在前面的n-1次比较中已经做过，而树形选择排序恰好利用树形的特点保存了部分前面的比较结果，
因此可以减少比较次数。对于n个关键字序列，最坏情况下每个节点需比较log2(n)次，因此其最坏情况下时间复杂度为nlogn。堆排序为不稳定排序，不适合
记录较少的排序。
参考：http://jingyan.baidu.com/article/5225f26b057d5de6fa0908f3.html
 */

#include <stdio.h>
//调整堆：该堆是第i个节点为根节点的堆，size为堆的总节点个数(数组长度)
void heapAdjust(int array[],int i,int size){
    int lChildIndex = 2*i;
    int rChildIndex = 2*i + 1;
    int maxIndex = i; //临时变量
    int temp;
    if (i <= size/2) {
        if (lChildIndex <= size && array[lChildIndex] > array[maxIndex]) {
            maxIndex = lChildIndex;
        }
        if (rChildIndex <= size && array[rChildIndex] > array[maxIndex]) {
            maxIndex = rChildIndex;
        }
        if (maxIndex != i) {
            temp = array[i];
            array[i] = array[maxIndex];
            array[maxIndex] = temp;
            heapAdjust(array, maxIndex, size);
        }
    }
}
void buildHeap(int array[], int endIndex){
    int i = endIndex/2 ;
    for (; i >= 1; i--) {
        heapAdjust(array, i, endIndex);
    }
}
void heapSort(int array[],int endIndex) {
    int temp;
    buildHeap(array,endIndex);
    for (int i = endIndex ; i >= 1 ; i-- ) {
        temp = array[i];
        array[i] = array[1];
        array[1] = temp;
        heapAdjust(array, 1, i - 1);
    }
}

int main(int argc, const char * argv[]) {
    int testArray[] = {2,54,2,4,5,5,9,65,7,6,8,256,7,6};
    heapSort(testArray, 13);
    for(int i = 0; i < 14; i++ ){
        printf("%d ",testArray[i]);
    }
    printf("\n");
    return 0;
}

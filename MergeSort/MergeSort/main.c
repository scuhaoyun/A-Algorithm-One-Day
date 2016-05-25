//
//  main.c
//  MergeSort
//
//  Created by 郝赟 on 16/5/25.
//  Copyright © 2016年 haoyun. All rights reserved.
//
//  归并排序(自底向上)
//  基本思想:将待排序序列R[0...n-1]看成是n个长度为1的有序序列，将相邻的有序表成对归并，得到n/2个长度为2的有序表；将这些有序序列再次归并，得到n/4个长度为4的有序序列；如此反复进行下去，最后得到一个长度为n的有序序列。基本的合并算法是取两个输入数组A和B，一个输出数组C以及3个计数器(Actr,Bctr和Cctr)，他们初始位置对应于数组的开始端。A[Actr]和B[Bctr]中的较小者被复制到C中的下一个位置，相关计数器向前推进一步。当其中一个用完时，将另一个表中的剩余部分拷贝到C中。该算法是经典的分治算法。
//  最好，最坏和平均时间复杂度:O(n*logn)
//  空间复杂度:O(n)
//  算法思维方式: 利用递归的思想，首先对整个数组二分分割，再二分分割，直到分割成单个值的子数组，然后将子数组合并
#include <stdio.h>

//合并一个局部有序数组(从midIndex分开前后的两个子数组是有序的)
void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i] >= sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    //将剩余部分拷入C中
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}

//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = (startIndex + endIndex) / 2;
        //此处利用递归MergeSort函数(包含了Merge函数)将数组自顶向下分割到单个值的子数组，再自底向上将两两子数组合并
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

int main(int argc, char * argv[])
{
    int a[11] = {11,8,2,7,10,5,6,9,13,20,2};
    int i, b[11];
    MergeSort(a, b, 0, 10);
    for(i=0; i<11; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
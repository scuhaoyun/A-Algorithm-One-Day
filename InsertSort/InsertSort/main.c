//
//  main.c
//  InsertSort
//
//  Created by 郝赟 on 16/5/26.
//  Copyright © 2016年 haoyun. All rights reserved.
//
//  直接插入排序
//  基本思想:将n个元素分为有序和无序两个部分(本算法为有序序列在前，无序序列在后)，每次处理就是将无序序列的第一个值插入到有序序列内，该过程执行n-1次，
//  直到所有元素到插入完毕。
//  平均时间复杂度:O(n^2)
//  空间复杂度:O(1)
//  折半插入排序
//  折半插入排序（binary insertion sort）是对插入排序算法的一种改进，由于排序算法过程中，就是不断的依次将元素插入前面已排好序的序列中。由于前半部
//  分为已排好序的数列，这样我们不用按顺序依次寻找插入点，可以采用折半查找的方法来加快寻找插入点的速度。折半查找只是减少了比较次数，但是元素移动次数不变

#include <stdio.h>
void directInsertSort(int array[], int length){
    int i,j,temp;
    for (i = 1; i < length; i++) {
        temp = array[i];
        for (j = i; j >0 && array[j - 1] > temp; j--) {
            array[j] = array[j-1];
        }
        array[j] = temp;
    }
}
void binaryInsertSort(int array[], int length){
    int i,j,temp;
    int low,high;
    for (i = 1; i < length; i++) {
        temp = array[i];
        low = 0;
        high = i - 1;
        //折半查找出第i个元素应该插入的位置，为low或者high
        while (low <= high) {
            if (array[(low + high)/2] < temp){
                low = (low + high)/2 + 1 ;
            }
            else {
                high = (low + high)/2 - 1 ;
            }
        }
        //从查找的位置依次将后面的元素向后移动一位
        for (j = i; j > low; j--) {
            array[j] = array[j-1];
        }
        array[j] = temp;
    }
}
int main(int argc, const char * argv[]) {
    int sortArray[] = {21,2,1,45,2,14,32,14,21,45,32,14,2,9,8,75,6,52,4,6};
    directInsertSort(sortArray, 20);
    for (int i = 0; i < 20; i ++) {
        printf("%d ",sortArray[i]);
    }
    printf("\n");
    int sortArray1[] = {21,2,1,45,2,14,32,14,21,45,32,14,2,9,8,75,6,52,4,6};
    binaryInsertSort(sortArray1, 20);
    for (int i = 0; i < 20; i ++) {
        printf("%d ",sortArray1[i]);
    }
    printf("\n");
    return 0;
}

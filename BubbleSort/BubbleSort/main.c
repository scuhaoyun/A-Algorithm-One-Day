//
//  main.c
//  BubbleSort
//
//  Created by 郝赟 on 16/5/27.
//  Copyright © 2016年 haoyun. All rights reserved.
//
//  冒泡排序
//  基本思想:比较相邻的元素。如果第一个比第二个大，就交换他们两个,每趟把最大的一个冒泡到最后一个，最差的情况下要冒泡n-1趟，且每一趟平均要比较和交换（n-1）/2次。
//  最好，最坏和平均时间复杂度分别为:O(n)，O(n^2)，O(n^2)
//  稳定性：稳定
#include <stdio.h>
void bubbleSort(int array[],int length){
    //数值大的数字向后移动
    int lastLocation = length - 1;
    //用于判断是否还进行后续的比较和交换
    int exitReserve = 1;
    int temp;
    while (lastLocation > 0 && exitReserve) {
        exitReserve = 0;
        for (int i = 0; i < lastLocation; i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
                exitReserve = 1;
            }
        }
        lastLocation--;
    }
}
int main(int argc, const char * argv[]) {
    int testArray[] = {1,2,1,6,5,45,2,3,4,5,41,1,2,45,1,98,65,23,4,54,5,1,6,8,5,4,5};
    bubbleSort(testArray, 27);
    for (int i = 0; i < 27 ; i++) {
        printf("%d ",testArray[i]);
    }
    printf("\n");
    return 0;
}

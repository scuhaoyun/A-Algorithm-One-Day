//
//  main.c
//  SelectSort
//
//  Created by 郝赟 on 16/5/29.
//  Copyright © 2016年 haoyun. All rights reserved.
//  选择排序
//  基本思想:每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完。
//  最好，最坏和平均时间复杂度都为:O(n^2)
//  稳定性：不稳定
#include <stdio.h>
void selectSort(int array[], int bIndex, int eIndex) {
    if (array == NULL || (eIndex - bIndex) < 1) {
        return ;
    }
    int i ; //i的位置记录第(i+1)趟的最小值应该放的位置
    int k ; //k用来记录找到的最小值的位置
    int temp;
    for (i = bIndex;i < eIndex + 1; i++) {
        k = i;
        for (int j = i + 1; j < eIndex + 1; j++) {
            if (array[j] < array[k]) {
                k = j;
            }
        }
        if (array[k] < array[i]) {
            temp = array[k];
            array[k] = array[i];
            array[i] = temp;
        }
    }
}
int main(int argc, const char * argv[]) {
    int testArray[] = {5,12,54,2,45,2,45,54,6,9,8,4,2,5,42,45};
    selectSort(testArray, 0, 14);
    for (int i = 0; i < 15; i++) {
        printf("%d ",testArray[i]);
    }
    printf("\n");
    return 0;
}

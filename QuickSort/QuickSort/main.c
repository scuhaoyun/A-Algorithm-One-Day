//
//  main.c
//  QuickSort
//
//  Created by 郝赟 on 16/5/24.
//  Copyright © 2016年 haoyun. All rights reserved.
//

#include <stdio.h>

int main() {
    void quickSort(int *sortAarray, int left, int right);
    int numArray[] = {5,6,5,4,2,6,8,4,1,2,3,1,5,6,14,55,12,4,14,23};
    quickSort(numArray,0,20);
    for (int i = 0; i < 20; i++) {
        printf("%d ",numArray[i]);
    }
    return 0;
}
void quickSort(int *sortAarray, int left, int right){
    if (left >= right) {
        return;
    }
    int keyValue = sortAarray[left]; //将最左边的值作为基准值比较
    int i = left, j = right;
    while (i < j) {
        while (i < j && sortAarray[j] >= keyValue) {
            j--;
        }
        //交换
        sortAarray[i] = sortAarray[j];
        while (i < j && sortAarray[i] < keyValue) {
            i++;
        }
        sortAarray[j] = sortAarray[i];
    }
    sortAarray[i] = keyValue;
    quickSort(sortAarray, left, i - 1);
    quickSort(sortAarray, i + 1 , right);
    
}
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
//1.快速排序的平均时间复杂度为O（nlogn）: 快速排序会递归log(n)次(每次二分)，每次会对n个数进行处理，故时间复杂度为n*logn。
//2.最坏时间复杂度O(n^2): 快速排序每次选取的中间值都是最小值或者最大值，此时会递归n次，每次会对n个数处理。
//3.快速排序的基本思想是：每次从无序的序列中找出一个数作为中间点（可以把第一个数作为中间点），然后把小于中间点的数放在中间点的左边，把大于中间点的数放在中间点的右边；对以上过程重复log(n)次得到有序的序列。
//4.平均空间复杂度:O(logn),最坏空间复杂度:O(n),此时递归树的高度为O(n)，所需的栈空间为O(n)
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
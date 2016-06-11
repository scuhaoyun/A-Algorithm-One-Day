//
//  main.c
//  寻找满足条件的两个或多个数
//
//  Created by 郝赟 on 16/6/11.
//  Copyright © 2016年 haoyun. All rights reserved.
//寻找满足和为定值的两个或多个数
//思路:先将数组排序，然后设置开始位置的首位两个指针，向中间滑动
//
//输入两个整数 n 和 m，从数列1，2，3.......n 中 随意取几个数,
//使其和等于 m ,要求将其中所有的可能组合列出来。
//这个问题就是典型的0,1背包问题了，设函数f(n,m)就是最终的结果，那么
//f(n,m)无非由以下两种情况构成：
//1.n包含在最优解中，即：放n，n-1个数填满sum-n   f(n,m)= f(n-1,sum-n) 并 n
//2.n不包含在最优解中，即：不放n, n-1个数填满sum   f(n,m) = f(n-1, sum)
//参考:http://blog.csdn.net/v_JULY_v/article/details/6419466

#include <stdio.h>
#include <stdlib.h>

int cmp ( const void *a , const void *b){
    return *(int *)a - *(int *)b;
}
void findTwoNum(int *array, int sum, int length){
    qsort(array, length, sizeof(int), cmp);
    int i = 0;
    int j = length - 1;
    
    while (i <= j) {
        if (array[i] + array[j] == sum) {
            printf("[%d,%d]",array[i],array[j]);
            while ((i+1) < length && array[i] == array[ i + 1]) {
                i++;
                
            }
            while ((j-1) >= 0 && array[j] == array[j-1]) {
                j--;
            }
            i++;
            j--;
        }

        while (array[i] + array[j] < sum) i++;
        while (array[i] + array[j] > sum) j--;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int testArray[] = {2,18,5,15,6,12,4,5,8,9,3,45,12,8,17,14};
    findTwoNum(testArray, 20, 16);
    printf("\n");
    return 0;
}

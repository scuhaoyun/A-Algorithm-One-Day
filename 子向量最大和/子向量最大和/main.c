//
//  main.c
//  子向量最大和
//
//  Created by 郝赟 on 16/6/16.
//  Copyright © 2016年 haoyun. All rights reserved.
//

#include <stdio.h>
///第一种方法:采用分治算法
// 思想：把向量分成ab两个左右子向量，那么最大子向量要么在a中，要么在b中，要么跨越a和b的边界，此处将跨越ab边界的向量称为c。
//     分治算法将递归的计算Ma和Mb，并通过其他某种方法计算Mc，然后返回3个总和中的最大者。
//时间复杂度:O(nlogn).
//参考:编程珠玑89页
int maxSum1(int array[],int sIndex, int eIndex){
    if (sIndex > eIndex || array == NULL) return 0;
    if (sIndex == eIndex) return  0 > array[sIndex]? 0 : array[sIndex];
    int mIndex = (sIndex + eIndex) / 2;
    int lmax = 0,lsum = 0;
    for (int i = mIndex; i >= 1; i--) {
        lsum += array[i];
        lmax = lmax > lsum ? lmax : lsum;
    }
    int rmax = 0, rsum = 0;
    for (int i = mIndex + 1; i <= eIndex; i++) {
        rsum += array[i];
        rmax = rmax > rsum ? rmax : rsum;
    }
    int temp = (lmax + rmax) > maxSum1(array, 1, mIndex) ? (lmax + rmax) : maxSum1(array, 1, mIndex);
    return temp > maxSum1(array, mIndex + 1, eIndex) ? temp : maxSum1(array, mIndex + 1, eIndex);
}
///第一种方法:扫描算法
// 思想：(1)如果某个连续子向量的和大于零，则以该子向量为前缀的连续子向量的和可能会更大。
//      (2)如果某个连续子向量的和小于或等于零，则以该子向量为前缀的连续子向量的和不可能大于去掉该子向量前缀之后的子向量的和。
//时间复杂度:O(n)
//参考:http://www.cnblogs.com/lienhua34/p/3703841.html
int maxSum2(int array[], int length){
    if (array == NULL) return 0;
    //使用两个游标保存最大子向量的左右位置,maxSum用于保存最大子向量和
    int maxSIndex = -1, maxEIndex = -1, maxSum = 0;
    //使用两个游标保存当前子向量的左右位置,crurrentSum用于保存当前子向量和
    int currentSIndex = 0, currentEIndex = 0, currentSum = 0;
    while (currentEIndex < length) {
        currentSum += array[currentEIndex];
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxSIndex = currentSIndex;
            maxEIndex = currentEIndex;
        }
        else if (currentSum <= 0) {
            currentSum = 0;
            currentSIndex = currentEIndex + 1;
        }
        currentEIndex += 1;
    }
    return maxSum;
}
int main(int argc, const char * argv[]) {
    //正确值为187
    int tArray[] = {31,-41,59,26,-53,58,97,-93,-23,84};
    printf("最大子向量的值为:%d \n",maxSum1(tArray,0,9));
    printf("最大子向量的值为:%d \n",maxSum2(tArray,10));
    return 0;
}

//
//  main.c
//  字符串旋转
//
//  Created by 郝赟 on 16/6/15.
//  Copyright © 2016年 haoyun. All rights reserved.
//  本例采用两种算法进行字符串旋转，一种使用递归的思想，另一种使用反序的思想

#include <stdio.h>
//思想:旋转向量x其实就是交换向量ab的两段，这里a代表前loc个元素。假设a比b短，将b分为b(l)和b(r)，使得b(r)具有与a相同的长度，交换a和b(r)，就得到
//  b(r)b(l)a，序列a此时已经处于最终位置，因此交换b(r)和b(l)即可。 若a比b长，同理从右向左反方向思考即可。该算法需要交换n次，故时间复杂度为O(n)。
void leftRotate0(char *array, int sIndex, int loc, int length){
    if (array == NULL || loc >= length || loc < 1) {
        return;
    }
    //找出要交换的元素个数，即a和b较小者，将头尾countNum个元素交换
    int countNum = loc < (length-loc)?loc:(length-loc);
    char temp;
    for (int i = 0; i < countNum; i++) {
        temp = array[sIndex+i];
        array[sIndex+i] = array[sIndex + length - (countNum -i)];
        array[sIndex + length - (countNum -i)] = temp;
    }
    //递归交换左边
    if (loc < (length-loc)) leftRotate0(array,sIndex, loc, length-loc);
    //递归交换右边
    else if (loc > (length-loc))leftRotate0(array,sIndex + length - loc, 2*loc - length, loc);
}


///思想:将数组ab转换成ba。从ab开始，首先对a求逆，得到a[r]b,然后对b求逆，得到a[r]b[r]。最后对整体求逆，得到(a[r]b[r])[r]=ba。
void reverse(char *array,int sIndex, int eIndex){
    if (array == NULL || sIndex >= eIndex || sIndex < 0) {
        return;
    }
    char temp;
    while (sIndex <= eIndex) {
        temp = array[sIndex];
        array[sIndex]= array[eIndex];
        array[eIndex] = temp;
        sIndex ++;
        eIndex --;
    }
    
}
//该算法需要交换2*n次值，因此时间复杂度为O(n)
void leftRotate(char *array, int loc, int length){
    if (array == NULL || loc >= length || loc < 1) {
        return;
    }
    reverse(array, 0, loc - 1);
    reverse(array, loc, length - 1);
    reverse(array, 0, length - 1);
}
int main(int argc, const char * argv[]) {
    //字符数组最后一位为“\0”，所以字符数组的长度要比实际长度多1
    char testArray[] = "adbdfndfasgdfddsjksfes";
    leftRotate(testArray, 8, sizeof(testArray) - 1);
    printf("%s \n",testArray);
    char testArray1[] = "adbdfndfasgdfddsjksfes";
    leftRotate0(testArray1,0, 8, sizeof(testArray1) - 1);
    printf("%s \n",testArray1);
    
    return 0;
}

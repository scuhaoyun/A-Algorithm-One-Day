//
//  main.c
//  AddNoCorporation
//
//  Created by 郝赟 on 16/7/12.
//  Copyright © 2016年 haoyun. All rights reserved.
//

#include <stdio.h>
//判断是否是负数，0，正数
int isneg(int a)
{
    return a & 0x8000;
}
int iszero(int a)
{
    return !(a & 0xFFFF);
}
int ispos(int a)
{
    return (a&0xFFFF) && !(a&0x8000);
}

int Add(int a, int b)
{
    int sum = a ^ b;            //用sum存储a+b不进位的结果
    int carry = a & b;          //用carry存储a+b应该进位的结果
    while (carry != 0) {        //思想：可看作每次循环产生新的a和b，再将b加在a上，直到没有进位
        a = sum;
        b = carry << 1;
        sum = a ^ b;
        carry = a & b;
    }
    
    return sum;
}
//原码 -> 补码： 数值位取反加1
//补码 -> 原码： 对该补码的数值位继续 取反加1
//补码 的绝对值（称为真值）：正数的真值就是本身，负数的真值是各位（包括符号位）取反加1（即变成原码并把符号位取反）.
//b -> -b ： 各位（包括符号位）取反加1
//使用位运算，a的相反数等于 -n=~(n-1)=~n+1
int negative(int a){
    return Add(~a, 1);
}
int sub(int a,int b){
    return Add(a, negative(b));
}
//只适用于正整数
int muti(int a,int b){
    int sum = 0;
    while (b) {
        if (b&1) {
            sum = Add(sum, a);
        }
        a = (a<<1);
        b = (b>>1);
    }
    
    return sum;
}
//只适用于正整数
int divide(int a,int b){
    int count = 0;
    while (a>=b) {
        a = sub(a, b);
        count = Add(count, 1);
    }
    return count;
}
int Muti(int a,int b){
    if (iszero(a) || iszero(b)) {
        return 0;
    }
    else if (isneg(a)){
        if (isneg(b)) {
            return muti(negative(a), negative(b));
        }
        else{
            return negative(muti(negative(a),b));
        }
    }
    else if (isneg(b)) {
        return negative(muti(a, negative(b)));
    }
    else {
        return muti(a, b);
    }
}
int Divide(int a,int b){
    if (iszero(b)) {
        exit(1);
    }
    if (iszero(a)) {
        return 0;
    }
    else if (isneg(a)){
        if (isneg(b)) {
            return divide(negative(a), negative(b));
        }
        else{
            return negative(divide(negative(a),b));
        }
    }
    else if (isneg(b)) {
        return negative(divide(a, negative(b)));
    }
    else {
        return divide(a, b);
    }

}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 25;
    int b = -14;
    printf("a+b=%d\n",Add(a, b));
    printf("a-b=%d\n",sub(a, b));
    printf("a*b=%d\n",Muti(a, b));
    printf("a/b=%d\n",Divide(a, b));
    return 0;
}

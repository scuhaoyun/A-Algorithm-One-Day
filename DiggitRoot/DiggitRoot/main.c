//
//  main.c
//  DiggitRoot
//
//  Created by 郝赟 on 16/7/13.
//  Copyright © 2016年 haoyun. All rights reserved.
//

#include <stdio.h>
//123456=1*(99999+1)+2*(9999+1)+3*(999+1)+4*(99+1)+5*(9+1)+6 = (1*99999+2*9999+3*999+4*99+5*9)+(1+2+3+4+5+6）
int addDigits(int num) {
    return (num - 9*((num - 1) / 9));
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 578465;
    printf("AddDigits:%d\n",addDigits(a));
    return 0;
}

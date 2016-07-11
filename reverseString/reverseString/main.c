//
//  main.c
//  reverseString
//
//  Created by 郝赟 on 16/7/11.
//  Copyright © 2016年 haoyun. All rights reserved.
//

#include <stdio.h>
#include <string.h>
char* reverseString(char* s) {
    int len = strlen(s);
    char *start = s;
    char *end = s + len - 1;
    char temp;
    if (s != NULL) {
        while (start < end) {
            temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
    }
    return s;
}
char* reverseString1(char* s) {
    int len = strlen(s);
    int i, n = len / 2;
    char tem;
    // 第一个和最后一个交换，第二个和倒数第二个交换
    // 这样就只用交换一半
    for (i = 0; i < n; i++)
    {
        tem = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tem;
    }
    return s;
}

int main(int argc, const char * argv[]) {
    // 此处不可如下定义:char *s = "hello";
    char s[] = "a.";
    reverseString1(s);
    printf("%s",s);
    return 0;
}

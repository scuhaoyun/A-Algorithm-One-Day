//
//  main.c
//  TestCode
//
//  Created by 郝赟 on 16/6/11.
//  Copyright © 2016年 haoyun. All rights reserved.
//

#include<stdio.h> 
#include<string.h> 
int main()
{
    int a[2000];
    char *p = (char *)a;
    int i ;
    for( i = 0; i < 2000; i++){
        a[i] = -i -1;
    }
    printf("%lu\n", strlen(p));
   
    printf("%ud ",'\0');
    return 0;
}
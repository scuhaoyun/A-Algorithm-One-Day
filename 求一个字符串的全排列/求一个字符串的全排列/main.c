//
//  main.c
//  求一个字符串的全排列
//
//  Created by 郝赟 on 16/6/8.
//  Copyright © 2016年 haoyun. All rights reserved.
//

#include <stdio.h>

void Permutation1(char* pStr, char* pBegin);

/////////////////////////////////////////////////////////////////////////
// Get the permutation of a string,
// for example, input string abc, its permutation is
// abc acb bac bca cba cab
/////////////////////////////////////////////////////////////////////////
void Permutation(char* pStr)
{
    Permutation1(pStr, pStr);
}

/////////////////////////////////////////////////////////////////////////
// Print the permutation of a string,
// Input: pStr   - input string
//        pBegin - points to the begin char of string
//                 which we want to permutate in this recursion
/////////////////////////////////////////////////////////////////////////
void Permutation1(char* pStr, char* pBegin)
{
    if(!pStr || !pBegin)
        return;
    
    // if pBegin points to the end of string, // this round of permutation is finished,
    // print the permuted string
    if( *pBegin == '\0')
    {
        printf("%s  ", pStr);
    }
    // otherwise, permute string
    else
    {
        for(char* pCh = pBegin; *pCh != '\0'; ++ pCh)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
            
            Permutation1(pStr, pBegin + 1);
            
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}
int main()
{
    char strTemp[10] = "1234";
    Permutation( strTemp );
    printf("\n");
    return 0;
}

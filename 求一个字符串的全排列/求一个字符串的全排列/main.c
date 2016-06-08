//
//  main.c
//  求一个字符串的全排列
//
//  Created by 郝赟 on 16/6/8.
//  Copyright © 2016年 haoyun. All rights reserved.
//
/*
解答：这是一个很好的考察递归理解的题目。我们以字符串abc为例，来分析一下字符串的排列过程。首先我们固定第一个字符a，求后面字符串bc
的排列。我们把第一个字符a和后面的紧挨的字符b交换，得到bac，接着我们固定第一个字符b，求后面的字符串ac的排列。然后将c和第一个
位置的a交换，得到cab，我们固定c，求后面的字符串ab的排列，很显然我们在交换a和c的时候，首先要将b和a换回来，也就是说在求每个子串的排列之后，
我们应该将之前交换的字符串换回来。在这里我们需要维护两个字符串指针，一个pStr表示字符串的排列，一个pBegin表示需要固定字符的指针位置。
参考:http://www.th7.cn/Program/c/201407/228302.shtml
*/
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
    char strTemp[10] = "abcde";
    Permutation( strTemp );
    printf("\n");
    return 0;
}

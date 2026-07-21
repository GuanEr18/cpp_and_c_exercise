//本题的子集string要求元素出现顺序必须与原数列相同
#include <stdio.h>
#include <string.h>
// 判断 t 是否为 s 的子序列（字符顺序必须一致，可删除任意字符）
int isSubsequence(const char *s, const char *t) {
    const char *p=s,*q=t;
    while (*p&&*q) {
        if(*p==*q)q++;  // 匹配成功，t 向后移动
        p++;                // s 始终向后移动
    }
    return*q=='\0';      // t 被完全匹配
}
int main(void) {
    char s[502],t[502];    // 题目长度 <= 500，预留 1 位 '\0' 与越界防护

    // 多组测试，EOF 结束
    while (scanf("%501s %501s",s,t) ==2) {
        if (isSubsequence(s,t)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
//
// Created by Zheng on 2025/12/7.
//
#include <stdio.h>
int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    getchar(); //吸收换行
    char s[512];
    while (N--) {
        if (!fgets(s, sizeof(s), stdin)) break;
        //这里的！代表S没有有效输入等于“==NULL”
        size_t len = 0;
        //提前定义长度
        while (s[len] != '\0') len++;
        //计算字符串长度，包含了‘\n’
        if (len > 0 && s[len - 1] == '\n') {
            s[len - 1] = '\0';
        }
        //不让输出时出现多余换行符号
        for (size_t i = 0; s[i] != '\0'; i++) {
            if (s[i] == '0') {
                s[i] = '1';
            }
        }
        puts(s);
    }
    return 0;
}
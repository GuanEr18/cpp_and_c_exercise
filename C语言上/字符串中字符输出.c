//
// Created by Zheng on 2025/10/10.
//
#include<stdio.h>
#include<string.h>
int main() {
    int i,b;
    char a[100];
    scanf("%s",&a);
    i=strlen(a);
    for (b=0;b<i;b++){
        printf("%c %d %xH\n",a[b],a[b],a[b]);
    }

    return 0;
}
//作为for循环的演示，文件中的for循环必须遵守初始条件
//，判断条件再更新条件的顺序。循环判断是按顺序来的
//顺序相反会不成立
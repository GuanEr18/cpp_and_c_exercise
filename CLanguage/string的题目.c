#include <stdio.h>
#include <string.h>
int main() {
    char a[10];
    char b[10];
    scanf("%s",a);
    scanf("%s",b);
    int len = strlen(a);//判断a的字符串长度
    printf("%d\n",len);
    printf("%c\n",b[0]);//printf中的b字符串带的中括号中数字代表取字符串中
    //第几位字符。从0开始计数。
    return 0;
}
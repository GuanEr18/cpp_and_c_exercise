//
// Created by Zheng on 2026/3/21.
//
#include <stdio.h>
#include <string.h>
#define maxlen 200
int result[maxlen],b[maxlen];
//result表示总和，b是阶乘
//自定义乘法器
void mutify(int x) {
    int carry=0;
    for (int i=0;i<maxlen;i++) {
        long long temp=(long long)b[i]*x+carry;
        b[i]=temp%10;
        carry=temp/10;
    }
    //for循环是为了能正确进位
    //函数整体只能计算b[i]*n
    //n!的效果是通过主函数中多次调用实现的
}
//加法器
void add() {
    int carry=0;
    for (int i=0;i<maxlen;i++) {
        int temp=result[i]+carry+b[i];
        result[i]=temp%10;
        carry=temp/10;
    }
}
int main () {
    int n;
    while (scanf("%d",&n)!=EOF) {
        memset(result,0,sizeof(result));//初始化
        memset(b,0,sizeof(b));
        b[0]=1;
        for (int x=1;x<=n;x++) {
            mutify(x);
            add();
        }
        int start=maxlen-1;
        while (start>=0 && result[start]==0) {
            start--;
        }
        for (int i=start;i>=0;i--) {
            printf("%d",result[i]);
        }
        printf("\n");
    }
    return 0;
}
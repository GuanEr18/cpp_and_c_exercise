#include <stdio.h>
int sum(int n) {
    if (n<0) printf("输入1~100\n");
    if (n==0) return 1;
    int sum=0,f=1;
    for (int i=1;i<=n;i++) {
        f*=i;
        sum+=f;//这里用到的单循环表示f从1的阶乘开始sum=1！+2！……
    }
    return sum;
}
//这种分两端函数的程序最好把要输入的函数定义在main里定义在上面会变量遮蔽
int main() {
    int n;
    while (scanf("%d",&n)==1) {
        if (n<0 || n>10) {
            printf("请输入0~10的整数\n");
            continue;      // 修复：跳过本次无效输入
        }
        printf("%d\n", sum (n));
    }
    return 0;
}
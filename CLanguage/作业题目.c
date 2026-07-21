#include <stdio.h>
int main(void) {
    double x,y;
    scanf("%lf %lf", &x,&y);
    if (2.6+1.3*y/3-1.3*x==0) {
        printf("Dad win!");
    }
    else {
        printf("Child win!");
    }
    return 0;
}
//printf("内容")内容需占位如%7.3f.这代表整数部分和小数点以及小数部分有7位的长度。
//小鼠迪安后的部分代表精确到几位小数。
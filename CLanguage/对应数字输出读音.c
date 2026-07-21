#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void) {
    int c,n;
    scanf("%d",&c);
    if (c<0) {
        printf("fu ");
        c=-c;
    }
    if (c==0) {
        printf("ling");
        return 0;
    }
    for (n=1;pow(10,n)>c&&c>=pow(10,n-1);n++) {}//用于判断位数
    n=n+2;
    printf("%d",n);

    return 0;
}
#include <stdio.h>
int main(void) {
    int n,i,j,s;//i表示层数，n表示总数.总数=2*i*i-1
    char x;
    scanf("%d %c", &n, &x);
    for(i=0;2*i*i-1<=n;i++){}
    for (j=i-1;j>=1;j--) {
        for (s=i-1;s>j;s--) {
            printf(" ");//空格数判断
        }
        for (int a=1;a<=2*j-1;a++) {
            printf("%c",x);
        }
        printf("\n");//每行打印个数从多到少
    }
    for (j=2;j<=i-1;j++) {
        for (s=i-1;s>j;s--) {
            printf(" ");
        }
        for (int a=1;a<=2*j-1;a++) {
            printf("%c",x);
        }
        printf("\n");//输出部分完成
    }
    printf("%d",n-2*(i-1)*(i-1)+1);
    return 0;
}
//#include <stdio.h>
//int main() {
//    int a,x=0,y=1,c,s;
//    while(scanf("%d",&a) != EOF) {
//        while (y<=a) {
//            c=2*y-1;s=a-y;
//            while (s) {
//                printf(" ");
//                s--;
//            }
//            while (c) {
//                printf("*");
//                c--;
//            }
//            printf("\n");
//            x+=(2*y-1);
//            y++;
//        }
//        printf("stars:%d\n",x);
//        y=1;x=0;
//    }
//    return 0;
//}
//注释部分是while循环在类沙漏题目中的运用。
//是输入层数打印沙漏的。
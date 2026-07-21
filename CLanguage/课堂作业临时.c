#include <stdio.h>
#define MAX 100
int main(void) {
    int M,N;
    while (scanf("%d %d",&M,&N)==2) {
        int seat[MAX][MAX]={0};
        int sold=0;
        int a,b;
        while (scanf("%d %d",&a,&b)==2) {
            if (a==-1 && b==-1) break;
            if (a>=1 && a<=M && b>=1 && b<=N) {
                seat[a-1][b-1]=1;
                sold++;
            }
        }
        printf("seat table:\n");
        for (int i=0;i<M;++i) {
            for (int j=0;j<N;++j) {
                printf("%3d",  seat[i][j]);
            }
            putchar('\n');
        }
        double rate =M*N ? (double)sold/(M*N)*100.0 : 0.0;
        printf("the number of sold seats:%d\n", sold);
        printf("the rate of solde seats:%.2f%%\n", rate);
    }
    return 0;
}
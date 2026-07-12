//
// Created by Zheng on 2026/4/19.
//
/**
 *火车从始发站（称为第 1 站）开出，在始发站上车的人数为 a，
 *然后到达第 2 站，在第 2 站有人上、下车，但上、下车的人数相同，
 *因此在第 2 站开出时（即在到达第 3 站之前）车上的人数保持为 a 人。
 *从第 3 站起（包括第 3 站）上、下车的人数有一定规律：
 *上车的人数都是前两站上车人数之和，而下车人数等于上一站上车人数，
 *一直到终点站的前一站（第 n−1 站），都满足此规律。
 *现给出的条件是：
 *共有 n 个车站，始发站上车的人数为 a，最后一站下车的人数是 m（全部下车）。
 *试问 x 站开出时车上的人数是多少？
 */
#include<iostream>
#include<vector>
using namespace std;
struct node {
    int a;  //a代表第一站上车的人
    int y;  //x代表第二站上车的人
};

int main () {
    int a,n,m,x;
    while(cin>>a>>n>>m>>x) {
        //a,第一站上的人。n，车站数。m，终点站多少人。x，要求的站点开出时多少人
        //从第三站开始，每一站增加的人数是两站前的上车人数  让第二站上y人
        //第三站+=a。第四站+=y。第五站+=第三站上的人（a+y）
        //六+=(第四站上的人)a+y+y
        if (x==1) {
            cout<<a<<endl;
            return 0;
        }
        vector<node> up(n+1);
        vector<node> stay(n+1);
        up[1]={1,0};
        stay[1]={1,0};
        up[2]={0,1};
        stay[2]={1,0};
        for (int i=3;i<n;i++) {
            up[i].a=up[i-1].a+up[i-2].a;
            up[i].y=up[i-1].y+up[i-2].y;
            stay[i].y=stay[i-1].y+up[i].y-up[i-1].y;
            stay[i].a=stay[i-1].a+up[i].a-up[i-1].a;
        }
        int number=0;
        if (n>2) {
            if (stay[n-1].y!=0) {
                number=(m-stay[n-1].a*a)/stay[n-1].y;
            } else {
                number=0;
            }
        }
        cout<<stay[x].a*a+stay[x].y*number<<endl;
    }
    return 0;
}
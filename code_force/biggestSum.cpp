//
// Created by Zheng on 2026/4/25.
//
#include <algorithm>
#include<iostream>
using namespace std;
int main() {
    int round;
    while (cin>>round) {
        int a[7];
        for (int i=0;i<round;i++) {
            for (int j=0;j<7;j++) cin>>a[j];
            sort(a,a+7);//顺序
            cout<<-a[0]-a[1]-a[2]-a[3]-a[4]-a[5]+a[6]<<endl;
        }
    }
    return 0;
}
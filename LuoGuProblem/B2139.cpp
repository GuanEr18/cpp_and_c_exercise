//
// Created by Zheng on 2026/5/12.
//
#include <cmath>
#include <iostream>
using namespace std;
void sushu (int n,int m) {
    int count=0;
    for (int i=n;i<=m;i++) {
        for (int j=2;j<sqrt(n);j++) {
            if (n%j==0) {
                cout<<i;
                count++;
            }

        }
    }
}
int main() {
    int N,M;
    while(cin>>N>>M) {
        cout<<sushu(N,M)<<",";
    }
}
//
// Created by Zheng on 2026/7/16.
//
#include<iostream>
using namespace std;
int main() {
    int n,g,s,b;
    while(cin>>n>>g>>s>>b) {
        cout<<double(7500*g+3000*s+1500*b)/n<<endl;
    }
    return 0;
}
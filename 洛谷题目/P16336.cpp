//
// Created by Zheng on 2026/4/21.
//
#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,m,k;
        cin>>n>>m>>k;
        if(m==0) {
            cout<<n<<endl;// 情况一
        }
        else if(m>k-n%k) {
            cout<<0<<endl; // 情况二
        }
        else {
            cout<<n%k<<endl; // 情况三
        }
    }
}
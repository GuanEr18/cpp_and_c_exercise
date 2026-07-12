//
// Created by Zheng on 2026/4/25.
//
#include <iostream>
using namespace std;
int main() {
    int t;
    long long x,y;
    while(cin>>t) {
        for(int i=0;i<t;i++) {
            cin>>x>>y;
            bool found=false;
            if(2*x>=y) {
                cout<<"NO"<<endl;
            }
            else {
                int k=y/x;
                for (int j=3;j<=k;j++) {
                    if (j*x!=y) {
                        cout<<"YES"<<endl;
                        found=true;
                        break;
                    }
                }
                if (!found) {
                    cout<<"NO"<<endl;
                }
            }
        }

    }
    return 0;
}
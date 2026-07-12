//
// Created by Zheng on 2026/4/10.
//
#include <iostream>
using namespace std;
/**
int main () {
    long long a;
    while (cin >> a) {
        if (a<=0) {
            continue;
        }
        if (a==1) {
            cout<<"2(0)";
        }
        int n=-1;
        while (a>=1) {
            while (pow(2,n+1)<=a) {
                n++;
            }
            cout<<"2"<<"("<<n<<")";
            a-=pow(2,n);
            n=-1;
            if (a>=1) {
                cout<<"+";
            }
            else {
                cout<<endl;
            }
        }

    }
    return 0;
}
 */
//没有使用递归导致输出不符合格式

//高精度次方
long long pow2(long long x) {
    long long y=1;
    for (int i=1;i<x;i++) {
        y*=2;
    }
    return y;
}

void slove(int n) {

}
int main() {
    long long a;
    int n;
    while (cin>>a) {

        cout<<endl;
    }
    return 0;
}
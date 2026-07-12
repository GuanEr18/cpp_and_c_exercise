//
// Created by Zheng on 2026/4/11.
//
#include <iostream>
using namespace std;
int main () {
    long long n;
    while (std::cin >> n) {
        int i=1;
        while (n>i) {
            n-=i;
            i++;
            //最后一次执行时会多加一次,多加的1正好是分子分母和
        }
        i++;
        if (i%2==0) {
            cout<<i-n<<"/"<<n<<endl;
        }
        else {
            cout<<n<<"/"<<i-n<<endl;
        }
    }
    return 0;
}
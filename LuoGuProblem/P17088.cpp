//
// Created by Zheng on 2026/7/16.
//
#include<bits/stdc++.h>
using namespace std;
int n;
/**
 *
 * @param x 在 C++ 中，lowbit(x) 正是用来求“x
 * 的二进制表示中最低位的 1 所代表的值”，
 * 这在数学上等价于能整除 x 的最大的 2 的幂。
 * @return 能整除 x 的最大的 2 的幂
 */
int lowbit(int x) {
    return x & -x;
}
int main() {
    while(cin>>n) {
        for(unsigned int i=(1<<n)-1;i>0;i--) {
            int k = __popcount(i);
            if((1<<k) == lowbit(i)) {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
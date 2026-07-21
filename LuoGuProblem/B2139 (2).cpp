//
// Created by Zheng on 2026/6/1.
//
#include <cmath>
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> chart;
int upSideDown (int used) {
    int temp=0;
    // while (used>0) {
    //     temp += used % 10;
    //     used /= 10;
    //     temp *= 10;
    // }
    // if (temp/10==0) {
    //     temp/=10;
    // }
    while (used > 0) {
        temp = temp * 10 + used % 10; // 标准反转写法
        used /= 10;
    }
    return temp;
}
bool isPrime (int a) {
    if (a<=1) {
        return false;
    }
    bool flag=false;
    for (int i=2;i<=::sqrt(a);i++) {
        if (a%i==0) {
            flag=true;
            break;
        }
    }
    if (flag==false) {
        return true;
    } else {
        return false;
    }
}
int main() {
    int N,M;
    while (cin>>N>>M) {
        chart.clear();
        for (int i=N;i<=M;i++) {
            int temp=upSideDown(i);
            if (isPrime(i) && isPrime(temp)) {
                chart.push_back(i);
            }
        }
        if (chart.size()==0) {
            cout<<"No"<<endl;
        } else {
            sort(chart.begin(),chart.end());
            for (int i=0;i<chart.size();i++) {
                cout<<chart[i];
                if (i!=chart.size()-1) {
                    cout<<",";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
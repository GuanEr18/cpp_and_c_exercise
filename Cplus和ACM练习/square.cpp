//
// Created by Zheng on 2026/6/9.
//
#include <iostream>
#include <iomanip>
using namespace std;
int main () {
    double c;
    while (cin >> c) {
        cout <<fixed<<setprecision(2)<< c*c << endl;
    }
    return 0;
}
//
// Created by Zheng on 2026/6/4.
//
#include <cmath>
#include <iomanip>
#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double s,v;
    while(cin>>s>>v) {
        int totalTime=ceil(s/v)+10;//ceil向上取整
        int targetTime=480;
        int startTime=targetTime-totalTime;
        if(startTime<0) {
            startTime+=1440;
        }
        int hour = startTime/60;
        int minute = startTime%60;
        cout<<setfill('0')<<setw(2)<<hour<<":"<<setfill('0')<<setw(2)<<minute<<endl;
        //setfill表示不足的位数要用什么填充，setw代表目标位数
    }
    return 0;
}
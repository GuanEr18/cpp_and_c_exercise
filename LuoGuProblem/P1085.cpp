//
// Created by Zheng on 2026/4/24.
//
#include <iostream>
using namespace std;
int main () {
    int time_school[7],time_extracurricular[7];
    for (int i=0;i<7;i++) {
        cin>>time_school[i]>>time_extracurricular[i];
    }
    int temp,max=0,count=0,max_day;
    for (int i=0;i<7;i++) {
        temp=time_school[i]+time_extracurricular[i];
        if (temp>8) {
            count++;
            if (max<temp) {
                max=temp;
                max_day=i+1;
            }
            //无需写学习超时时间相同的判断，
            //因为max_day自动赋值给了靠前的一天
        }
    }
    if (count==0) {
        cout<<"0"<<endl;
        return 0;
    } else {
        cout<<max_day<<endl;
    }
    return 0;
}
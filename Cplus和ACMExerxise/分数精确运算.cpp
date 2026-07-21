//
// Created by Zheng on 2026/3/17.
//
#include<iostream>
#include<vector>
using namespace std;
//zuida gong yingshu
int GCD (int c,int b){
    int temp;
    if (c<b){
        temp=c;
        c=b;
        b=temp;
    }
    while(b!=0){
        temp=b;
        b=c%b;
        c=temp;
    }
    return c;//最大公因数
}
//zuixiao gongbeishu
int out (vector<vector<int> > &a,int n){
    int c=1;
    for(int i=0;i<n;i++){
        int b=a[1][i];
        c=c*b/GCD(c,b);
    }//temp=fenmu leicheng
    return c;
}
//C是最小公倍数
int calculate(vector<vector<int> > &a,int n) {
    int d=0,c=0,demon=out(a,n);
    //D代表分子通风后总和，C代表实数项
    for (int i=0;i<n;i++) {
        d+=a[0][i]*(demon/a[1][i]);
    }
    while (d>=demon) {
        c++;
        d-=demon;
    }
    if (d==0) {
        cout<<"int:"<<c<<endl;
    }
    //C是整数部分，D分子，OUT为分母。else部分要对小数通分
    else {
        int g=GCD(d,demon);
        cout<<"int:"<<c<<"float:"<<d/g<<"/"<<demon/g<<endl;
    }
}
int main (){
    int n;
    while(std::cin>>n){
        char c;
        int x,y;
        //x=fenzi  y=fenmu
        vector<vector<int> >a(2,vector<int>(n+1));
        //
        for(int i=0;i<n;i++){
            cin>>x>>c>>y;
            a[0][i]=x;
            a[1][i]=y;
        }
        cout<<"测试输出"<<endl;
        for(int i=0;i<n;i++){
            cout<<a[0][i]<<" "<<a[1][i]<<endl;
        }//out ceshi
        cout<<"矩阵测试完成"<<endl;
        //测试正确
        //输出最小公倍数
        cout<<out(a,n)<<endl;
        cout<<"最小公倍数测试完成"<<endl;
        calculate(a,n);
    }
}
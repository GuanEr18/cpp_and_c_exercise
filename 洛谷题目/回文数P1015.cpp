//
// Created by Zheng on 2026/4/18.
//
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string turn(const string & a) {
    string temp=a;
    reverse(temp.begin(),temp.end());
    //temp=反过来的M
    return temp;
}
//反转完成

int charToNumber(char c) {
    if (c>='0' && c<='9') return  c-'0';
    else return  c-'A'+10;
}
//字符转数字完成
char numberToChar(int n) {
    if (n>=0 && n<=9) {
        return  n+'0';
    }
    else {
        return  n-10+'A';
    }
}
//数字转字符完成

string calculate(int a,const string & b,const string & c) {
    //自定义进制计算
    int i = b.length()-1;
    int j=c.length()-1;
    int carry = 0;
    string sum="";
    //b,c长度相等
    for (int k=i;k>=0;k--) {
        int add=carry+charToNumber(b[k])+charToNumber(c[k]);
        if (add>=a) {
            add-=a;
            carry=1;
        }
        else {
            carry=0;
        }
        //这里要引用数字转字符了
        sum=numberToChar(add)+sum;
    }
    /*这个最高位进位很重要*/
    if (carry>0) {//进上最高位的1
        sum=numberToChar(carry)+sum;
    }
    return sum;
}
int main() {
    int N;
    string M;
    while(cin>>N>>M) {
        int round=0;
        while(round<=30) {
            if (M==turn(M)) {
                cout<<"STEP="<<round<<endl;
                return 0;
            }
            string reversed_M=turn(M);
            //更新M
            M=calculate(N,M,turn(M));
            round++;
        }
        cout<<"Impossible!"<<endl;
    }
}
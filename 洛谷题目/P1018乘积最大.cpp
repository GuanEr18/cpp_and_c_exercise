//
// Created by Zheng on 2026/5/1.
//
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <variant>
using namespace std;

/**
 * 以下代码中的struct部分像JAVA中的类（class BigInt）
 * 里面的operator表示符号后面跟着‘*’和‘>’这类的运算符
 * 代码中'operator*'和'operator>'额外定义了这两个运算符的方法
 * 体现了运算符重载。条件是两个BigInt型对象中间有'*'时运用额外定义的运算方法
 */

struct BigInt {
    vector<int> digits;

    /**
     * 第一个方法是构造函数
     * 把一个普通的长整型数字（比如 123）拆开，倒序放进数组里：[3, 2, 1]。
     */
    BigInt(long long num=0) {
        if (num==0) {
            digits.push_back(0);
        }
        while (num!=0) {
            digits.push_back(num%10);
            num/=10;
        }
    }
    /**
     * 用两层循环，让A的每一位去乘以B的每一位。
     * 其中奇怪点的解释：
     * 1.既然 res 是一个 BigInt 对象，而BigInt结构体里定义了vector<int> digits，
     * 那么res.digits自然就是访问这个新对象的数组。
     */
    BigInt operator*(const BigInt &a) const {
        BigInt result;
        result.digits.resize(digits.size()+a.digits.size(),0);
        for (int i=0;i<digits.size();i++) {
            for (int j=0;j<a.digits.size();j++) {
                result.digits[i+j]+=digits[i]*a.digits[j];//计算两位数相乘的结果
                result.digits[i+j+1]+=result.digits[i+j]/10;//计算进位的值
                result.digits[i+j]%=10;//计算进位后留下来的值
            }
        }
        while (result.digits.size()>1 && result.digits.back()==0) {
            result.digits.pop_back();
        }
        return result;
    }

    /**
     * Java里通常要实现 Comparable 接口
     * 这里重载>是为了让 if(total>curMax) 这句代码能跑通。
     * 先比位数（谁位数多谁大），位数一样就从高位（数组末尾）开始比
     */
    bool operator>(const BigInt& a)const {
        if (digits.size()!=a.digits.size()) {
            return digits.size()>a.digits.size();
        }
        for (int i=digits.size()-1;i>=0;i--) {
            if (digits[i]!=a.digits[i]) {
                return digits[i]>a.digits[i];
            }
        }
        return false;
    }
    void print () {
        for (int i=(int)digits.size()-1;i>=0;i--) {
            cout<<digits[i];
        }
        cout<<endl;
    }
};

string S;
int N,K;
BigInt memory[45][10];
bool visited[45][10];

BigInt stringToNumber(int l,int r) {
    string sub=S.substr(l,r-l+1);
    BigInt temp;
    temp.digits.clear();
    //l,r代表切片的限定位置
    for (int i=(int)sub.size()-1;i>=0;i--) {
        temp.digits.push_back(sub[i]-'0');
    }
    return temp;
}
BigInt DFS (int start,int remainK) {
    //remainK==0代表乘号用完了
    if (remainK==0) {
        return stringToNumber(start,N-1);
    }
    //记忆化 遇到算到过的状态直接返回
    if (visited[start][remainK]) {
        return memory[start][remainK];
    }
    BigInt curmax(0);
    //隔板法
    // 3. 遍历隔板放置位置(i 是当前段的结束位置)
    //  留出足够位置给剩下的乘号i<=N-1-remainK
    for (int i=start;i<=N-1-remainK;i++) {
        BigInt firstpart=stringToNumber(start,i);
        BigInt nextpart=DFS(i+1,remainK-1);
        BigInt total=firstpart*nextpart;
        if (total>curmax) {
            curmax=total;
        }
    }
    visited[start][remainK]=true;
    memory[start][remainK]=curmax;
    return curmax;
}
int main () {
    while (cin>>N>>K) {
        cin>>S;
        //重置记忆化数组
        for (int i=0;i<45;i++) {
            for (int j=0;j<10;j++) {
                visited[i][j]=false;
            }
        }
        BigInt result=DFS(0,K);
        result.print();
    }
    return 0;
}

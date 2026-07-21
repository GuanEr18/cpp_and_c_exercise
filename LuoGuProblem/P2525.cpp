//
// Created by Zheng on 2026/7/16.
//
#include <algorithm>
#include<iostream>
using namespace std;
int N,a[100];
bool cmp(const int & a,const int &b) {
    return a>b;
}
void solve(int x) {
    int maxNumber=0,maxPosition=x;
    // 这里position初始化变成X是防止初始化报错
    // 不初始化也没事，遇到找不到的情况就不会进这个方法
    for (int i=x+1;i<N;i++) {
        if (a[i]<a[x] && a[i] > maxNumber) {
            maxNumber=a[i];
            maxPosition=i;
        }
    }
    /**这里的if能找到后续数组中所有比原数组排序更靠前的
     * 可能。通过for循环能找到最靠后的一位数字。
     * 最靠后的一位数字交换后就是字典排序前一位数组
     */
    swap(a[x],a[maxPosition]);
    sort(a+x+1,a+N,cmp);
    // a+x+1 指向 a[x+1]
    // sort函数左闭右开，最后一个参数是改变排序方式
    // 默认升序，从小到大。传入参数后可以改变
}
int main() {
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>a[i];
    }
    cout<<"Choose your wander method by put '1' or '2'"<<endl;
    cout<<"1:普通排序寻找找方法"<<endl;
    cout<<"2:用了perv_permutation"<<endl;
    int x;
    cin>>x;
    switch (x) {
        case 1:
            for (int i=N-1;i>0;i--) {
                if(a[i] < a[i-1]) {
                    solve(i-1);
                    for (int j=0;j<N;j++) {
                        cout<<a[j]<<" ";
                    }
                    return 0;
                }
            }
            cout<<"ERROR"<<endl;
            break;
        case 2:
            if (prev_permutation(&a[0],&a[N])) {
                for (int i=0;i<N;i++) {
                    cout<<a[i]<<" ";
                }
                cout<<endl;
            }
            else {
                cout<<"ERROR"<<endl;
            }
            break;
    }
    return 0;
}
// prev_permutation()也是左开右闭，传入的两个值必须是地址。
// 如果能找到字典排序的前一位数组。就直接修改数组而且返回true。
// 找不到就返回false
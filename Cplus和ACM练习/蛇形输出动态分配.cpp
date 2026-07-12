//
// Created by Zheng on 2026/3/14.
//
#include <iostream>
#include <vector>
using namespace std;
void snake(int n) {
    vector<vector<int>>a(n,vector<int>(n));
    int top=0,bottom=n-1,left=0,right=n-1;
    int num=1;
    while (num<=n*n) {
        //最右边的那一列从上到下
        for (int i=top;i<=bottom;i++) {
            a[i][right]=num;
            num++;
        }
        right--;//最右边一行占满了
        //最底下从右到左
        for (int i=right;i>=left;i--) {
            a[bottom][i]=num;
            num++;
        }
        bottom--;
        //最左边从下到上
        for (int i=bottom;i>=top;i--) {
            a[i][left]=num;
            num++;
        }
        left++;
        //最上边从左到右
        for (int i=left;i<=right;i++) {
            a[top][i]=num;
            num++;
        }
        top++;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<a[i][j]<<"\t"
            ;
        }
        cout<<endl;
    }
}
int main() {
    int n;
    while (cin>>n) {
        snake(n);
    }
    return 0;
}
//
// Created by Zheng on 2026/4/26.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int leftRound(const vector<int>& a,int temp,int p) {
    int count=0;
    for(int i=p-1;i>=0;i--) {
        if (a[i]!=temp && a[i]!=a[p]) {
            count++;
            temp=a[i];
        } else if (a[i]!=temp) {
            temp=a[i];
        }
    }
    return count;
}
int rightRound(const vector<int>& a,int temp,int p,int n) {
    int count=0;
    for(int i=p+1;i<n;i++) {
        if (a[i]!=temp && a[i]!=a[p]) {
            count++;
            temp=a[i];
        } else if (a[i]!=temp) {
            temp=a[i];
        }
    }
    return count;
}
int main() {
    int round,n,k,p;
    cin >> round;
    while(round--) {
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            std::cin >> a[i];
        }
        cin >> p;
        p--;
        int temp = a[p];
        cout << 2*max(leftRound(a,temp,p),
        rightRound(a,temp,p,n))<< endl;
    }
    return 0;
}

/** 这里的direction代表是炒作还是右
*  int countSideBlocks(const vector<int>& a, int p, int n, int direction) {
    int blocks = 0;
    // start 是紧邻 p 的位置
    int start = (direction == -1) ? p - 1 : p + 1;
根据左右朝向定义start的位置
    for (int i = start; i >= 0 && i < n; i += direction) {
        // 如果当前位是异色位
        if (a[i] != a[p]) {
            // 如果它是这一侧的第一个元素，或者它前一个（靠近p的方向）是同色位
            // 那么这就是一个新块的开始
            int prev = i - direction;       prev代表前一步的位置
            if (prev == p || a[prev] == a[p]) {
                blocks++;
            }
            前一个判断代表就只走了一步，所以这时候不同代表异色块的开始
            后一个判断代表当前色块的颜色与标准点不同
        }
    }
    return blocks;
}
 */
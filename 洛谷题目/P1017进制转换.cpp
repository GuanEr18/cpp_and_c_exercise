//
// Created by Zheng on 2026/4/27.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 将数字转换为字符（处理 10 进制以上的情况）
char numberToChar(int n) {
    if (n >= 0 && n <= 9) return n + '0';
    return n - 10 + 'A';
}
void solve() {
    int N, base;
    // 洛谷题目通常需要处理多组或单组数据，注意格式
    while (cin >> N >> base) {
        int originalN = N;
        string result = "";
        if (N == 0) {
            result = "0";
        } else {
            while (N != 0) {
                int remainder = N % base;
                N /= base;
                // 核心修正：如果余数为负，借位处理
                if (remainder < 0) {
                    remainder -= base; // 相当于余数加了 |base|
                    N += 1;            // 商加 1
                }
                // N = R*q+remainder
                //   = R*(q+1)+(remainder-R)
                result += numberToChar(remainder);
            }
            reverse(result.begin(), result.end()); // 余数是逆序产生的，需要翻转
        }
        cout << originalN << "=" << result << "(base" << base << ")" << endl;
    }
}

int main() {
    solve();
    return 0;
}


/**  下面是我的屎山  */

// #include <iostream>
// #include <cmath>
// #include <vector>
// using namespace std;
// char numberToChar(int n) {
//
// }
// int weishu (int n,int type) {
//     if (n>=0) {
//         int i=0,temp=0;
//         while (temp<n) {
//             temp+=pow(type,i);
//             i+=2;
//         }// *******10101    奇数位上的数计算后呈正
//         return i;
//     } else {
//         int i=1;
//         while (temp>n) {
//             temp+=pow(type,i);
//             i+=2;
//         }// *******01010    偶数位上的数计算后呈负
//         return i;
//     }
// }
// vector<int> calculate (int x,int y,int wei) {
//     vector<int> a(wei,0);
//     if (x>=0) {
//         int temp=0;
//         for (int i=0;i<wei;i+=2) {
//             a[i]=abs(y)-1;
//             temp+=pow(y+1,i);
//         }   //初始赋值  获得拟合前的数值
//         //开始拟合
//         temp-=x;
//         for (int i=1;i<wei;) {
//             if (temp-=pow(y+1,i)>0) {
//                 a[i]=y+1;
//                 i+=2;
//             } else {
//                 for (int j=1;j<wei;) {
//                     if (temp-=pow(j,i)>0) {
//                         j++;
//                     }else if (temp-=pow(j,i)==0) {
//                         a[i]=j;
//                     } else {
//                         a[i]=j;
//                     }
//                 }
//             }
//         }
//     } else {
//
//     }
// }
// int main() {
//     int N,type;
//     while (cin>>N) {
//         cin>>type;
//
//         calculate(N,type,weishu(N,type));
//         if (type<=10) {
//             vector<int> result(weishu(N,type)) =
//                 calculate(N,type,weishu(N,type));
//             cout<<N<<"="<<result<<"(base"<<type<<")"<<endl;
//         } else {
//
//         }
//     }
// }

//
// Created by Zheng on 2026/5/26.
//
#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void solve (stack<vector<int>> &S,const vector<int> &A,const vector<int> &B) {
    string s1;
    cin>>s1;
    if (s1 =="PUSHA") {
        S.push(A);
    } else if (s1=="PUSHB") {
        S.push(B);
    } else if (s1=="DUP") {
        S.push(S.top());
    } else if (s1=="INTERSECT") {
        auto a=S.top();
        S.pop();
        auto b=S.top();
        S.pop();
        vector<int> result;
        set_intersection(a.begin(),a.end(),
            b.begin(),b.end()
            ,back_inserter(result));
        S.push(result);
    } else if (s1=="UNION") {
        auto a=S.top();
        S.pop();
        auto b=S.top();
        S.pop();
        vector<int> result;
        set_union(a.begin(),a.end(),
            b.begin(),b.end(),
            back_inserter(result));
        S.push(result);
    } else if (s1=="PRINTTOP") {
        auto& top=S.top();
        for (int i = 0; i < top.size(); i++) {
            cout<<top[i];
            if (i != top.size()-1) cout<<" ";
        }
        cout<<endl;
    }

}
int main() {
    int t;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>t) {
        while (t--) {
            int Alength;
            cin>>Alength;
            vector<int> A(Alength);
            for (int i = 0; i < Alength; i++) {
                cin>>A[i];
            }
            sort(A.begin(), A.end());
            int Blength;
            cin>>Blength;
            vector<int> B(Blength);
            for (int i = 0; i < Blength; i++) {
                cin>>B[i];
            }
            sort(B.begin(), B.end());
            int command;
            cin>>command;
            stack<vector<int>> S;
            while (command--) {
                solve(S,A,B);
            }
        }
    }
    return 0;
}
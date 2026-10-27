//
// Created by Zheng on 2026/6/23.
//
#include<iostream>
#include <stack>
using namespace std;
bool valid (const string &s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c =='(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            if ((c==')' && top=='(') ||
                (c==']' && top=='[') ||
                (c=='}' && top=='{')) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
    // 当stack中没有内容了才会成立
}
int main() {
    string str = "";
    int n;
    cin >> n;
    while (n--) {
        cin >> str;
        if (valid(str)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
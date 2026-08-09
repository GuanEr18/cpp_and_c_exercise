#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main () {
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (st.empty()) {
                cout << "NO" << endl;
                return 0;
            }
            char c = st.top();
            st.pop();
            
            if (s[i] == ')' && c != '(') {
                cout << "NO" << endl;
                return 0;
            }
            if (s[i] == ']' && c != '[') {
                cout << "NO" << endl;
                return 0;
            }
            if (s[i] == '}' && c != '{') {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (!st.empty()) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
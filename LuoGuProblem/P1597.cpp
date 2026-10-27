#include <iostream>
#include <string>
using namespace std;

int main() {
    int a = 0, b = 0, c = 0;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        // 寻找赋值符号 ':='
        if (s[i] == ':' && s[i + 1] == '=') {
            char left_var = s[i - 1];
            char right_val = s[i + 2];
            if (right_val >= '0' && right_val <= '9') {
                // 右边是数字，直接转换并赋值
                int num = right_val - '0';
                if (left_var == 'a') a = num;
                else if (left_var == 'b') b = num;
                else if (left_var == 'c') c = num;
            } else {
                int val = 0;
                if (right_val == 'a') val = a;
                else if (right_val == 'b') val = b;
                else if (right_val == 'c') val = c;

                if (left_var == 'a') a = val;
                else if (left_var == 'b') b = val;
                else if (left_var == 'c') c = val;
            }
        }
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    int multiplier = 1;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] != '-') {
            sum += (s[i] - '0') * multiplier;
            multiplier++;
        }
    }
    char lastChar = s[s.length() - 1];
    int checkDigit = sum % 11;
    bool isRight = false;
    if (checkDigit == 10 && lastChar == 'X') {
        isRight = true;
    } else if (checkDigit + '0' == lastChar) {
        isRight = true;
    }
    if (isRight) {
        cout << "Right" << endl;
    } else {
        cout << s.substr(0, s.length() - 1);
        // 输出正确的校验位
        if (checkDigit == 10) {
            cout << "X" << endl;
        } else {
            cout << checkDigit << endl;
        }
    }
    
    return 0;
}
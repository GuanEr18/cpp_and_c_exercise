#include <iostream>
#include <string>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string target, example;
    cin >> target;
    cin.ignore(); // 忽略换行符
    getline(cin, example);
    int count = 0;
    int firstPos = -1;
    int t_len = target.length();
    int e_len = example.length();
    for (int i = 0; i < e_len; i++) {
        if (i == 0 || example[i] == ' ') {
            int start = (i == 0) ? 0 : i + 1;
            if (start + t_len <= e_len) {
                bool isWordBoundary = (start + t_len == e_len) || (example[start + t_len] == ' ');
                if (isWordBoundary) {
                    bool flag = true;
                    for (int j = 0; j < t_len; j++) {
                        if (::tolower(example[start + j]) != ::tolower(target[j])) {
                            flag = false;
                            break;
                        }
                    }                
                    if (flag) {
                        count++;
                        if (firstPos == -1) {
                            firstPos = start; // 记录第一次出现的真实位置
                        }
                    }
                }
            }
        }
    }
    if (count == 0) {
        cout << -1 << endl;
    } else {
        cout << count << " " << firstPos << endl;
    }
    return 0;
}
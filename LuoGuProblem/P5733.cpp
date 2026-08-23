#include <iostream>
#include <cctype>
// toupper() tolower()
#include <algorithm>
using namespace std;

int main () {
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    // (头，尾，修改后从哪里开始写入，执行方法)
    cout << s;
}
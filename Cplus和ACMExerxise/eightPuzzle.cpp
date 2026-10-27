#include <iostream>
#include <string>
using namespace std;

int countInversions(const string& s) {
    int v = 0;
    for (int i = 0; i < 9; ++i) {
        if (s[i] == '0') continue;
        for (int j = i + 1; j < 9; ++j) {
            if (s[j] == '0') continue;
            if (s[i] > s[j]) {
                ++v;
            }
        }
    }
    return v;
}

int main() {
    string state;
    while (cin >> state) {
        const int target = 1; 
        int v = countInversions(state);
        if ((v % 2) == target) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
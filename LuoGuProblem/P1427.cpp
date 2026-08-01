#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main () {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        else v.push_back(n);
    }
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i] << endl;
    }
    return 0;
}
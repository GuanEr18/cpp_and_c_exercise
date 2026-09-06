#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    string x="";
    for (int i = 0; i < n;i++) {
        int temp;
        cin >> temp;
        x += temp-'0';
    }
    string change = x;
    for (int i = 0; i < n;i++) {
        reverse(change.begin()+i,change.begin()+i+k);
        
    }
    long long max;
}
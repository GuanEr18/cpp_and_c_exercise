#include <iostream>
#include <vector>
using namespace std;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(5);
    vector<int> v(5);
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (i%2==1) a[i]=str[i]-'0';
        else v[i]=str[i]-'0';
    }
    bool flag = false;
    
    
}
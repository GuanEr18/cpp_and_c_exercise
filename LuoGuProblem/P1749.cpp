#include <iostream>
using namespace std;
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        double min=k*(1+k)/2;
        if (min>n) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
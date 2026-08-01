#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double s, x;
    cin >> s >> x;
    double current_pos = 0.0; 
    double v = 7.0;
    while (true) {
        if (current_pos >= s - x) {
            if (current_pos + v*0.98 > s + x) {
                cout << "n\n";
            } else {
                cout << "y\n";
            }
            break;
        }
        current_pos += v;
        v *= 0.98;
    }
    return 0;
}

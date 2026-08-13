#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    double hp = 10.0;
    int rating = 0;
    long long exp = 0;
    while (t--) {
        double x;
        long long a;
        cin >> x >> a;
        hp -= x;
        if (hp <= 0) {
            long long temp_exp = exp;
            int temp_rating = 0;
            long long need = 1; // 2^0 = 1
            while (temp_exp >= need) {
                temp_exp -= need;
                need *= 2;
                temp_rating++;
            }
            cout << temp_rating << " " << temp_exp << endl;
            return 0;
        }
        if (hp > 10) hp = 10;
        exp += a;
    }
    long long temp_exp = exp;
    int temp_rating = 0;
    long long need = 1; // 2^0 = 1
    while (temp_exp >= need) {
        temp_exp -= need;
        need *= 2;
        temp_rating++;
    }
    cout << temp_rating << " " << temp_exp << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
int area(int num) {
    if (num <= 0) return 0;
    int i = 1;
    while ((long long)i * i * i <= num) {
        i++;
    }
    return i - 1;
}
int count_steps(int num) {
    int steps = 0;
    while (num > 0) {
        int r = area(num);
        num -= r * r * r;
        steps++;
    }
    return steps;
}
int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << count_steps(n) << endl;
    int remaining = n;
    while (remaining > 0) {
        int r = area(remaining);
        int cube_val = r * r * r;
        for (int i = 0; i < cube_val; i++) {
            if (!v.empty()) {
                cout << v[0] << " "; 
                v.erase(v.begin());
            }
        }
        cout << endl;
        remaining -= cube_val;
    }
    return 0;
}
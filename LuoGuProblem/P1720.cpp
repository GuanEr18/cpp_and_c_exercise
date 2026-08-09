#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    double sqrt5 = sqrt(5.0);
    double part1 = pow((1.0 + sqrt5) / 2.0, n);
    double part2 = pow((1.0 - sqrt5) / 2.0, n);
    double fn = (part1 - part2) / sqrt5;
    cout << fixed << setprecision(2) << fn << endl;
    return 0;
}
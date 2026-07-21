#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double EPS = 1e-6;

double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (fabs(b) < EPS) return 1e9; // 除数为0返回无效大数
            return a / b;
    }
    return 1e9;
}

int main() {
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        bool found = false;
        string ops = "+-*/";
        for (char op1 : ops) {
            if (found) break;
            for (char op2 : ops) {
                if (found) break;
                for (char op3 : ops) {
                    double res;
                    string expr;

                    res = calculate(calculate(a, b, op1), calculate(c, d, op3), op2);
                    if (fabs(res - 24.0) < EPS) {
                        cout << "(" << a << op1 << b << ")" << op2 << "(" << c << op3 << d << ")\n";
                        found = true; break;
                    }

                    res = calculate(calculate(calculate(a, b, op1), c, op2), d, op3);
                    if (fabs(res - 24.0) < EPS) {
                        cout << "((" << a << op1 << b << ")" << op2 << c << ")" << op3 << d << "\n";
                        found = true; break;
                    }

                    res = calculate(calculate(a, calculate(b, c, op2), op1), d, op3);
                    if (fabs(res - 24.0) < EPS) {
                        cout << "(" << a << op1 << "(" << b << op2 << c << "))" << op3 << d << "\n";
                        found = true; break;
                    }

                    res = calculate(a, calculate(calculate(b, c, op2), d, op3), op1);
                    if (fabs(res - 24.0) < EPS) {
                        cout << a << op1 << "((" << b << op2 << c << ")" << op3 << d << ")\n";
                        found = true; break;
                    }

                    res = calculate(a, calculate(b, calculate(c, d, op3), op2), op1);
                    if (fabs(res - 24.0) < EPS) {
                        cout << a << op1 << "(" << b << op2 << "(" << c << op3 << d << "))\n";
                        found = true; break;
                    }
                }
            }
        }
    }
    return 0;
}
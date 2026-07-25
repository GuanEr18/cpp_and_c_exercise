#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

// double eps = 1e-7;

// double f(double x, int a, int b, int c, int d)
// {
//     return (double)pow(x, 3) * a + pow(x, 2) * b + x * c + d;
// }
// double f_(double x, int a, int b, int c, int d)
// {
//     return (double)pow(x, 2) * 3 * a + x * 2 * b + c;
// }
// double delta(int a, int b, int c)
// {
//     return 4 * pow(b, 2) - 12 * a * c;
// }
// // 求单个根的简单二分法
// double bisection(double left, double right, int a, int b, int c, int d)
// {
//     double f_left = f(left, a, b, c, d);
//     double f_right = f(right, a, b, c, d);
//     if (f_left * f_right > 0)
//     {
//         return -1;
//     }
//     else
//     {
//         while ((right - left) / 2 > 1e-6)
//         {
//             double mid = (left + right) / 2;
//             double f_mid = f(mid, a, b, c, d);
//             if (abs(f_mid) < 1e-7)
//             {
//                 break;
//             }
//             if (f_mid * f_left > 0)
//             {
//                 left = mid;
//             }
//             else
//             {
//                 right = mid;
//             }
//         }
//         return left;
//     }
// }
// // 正常多根二分法
// vector<double> solveCubicAllRoots(int a, int b, int c, int d)
// {
//     vector<double> roots;
//     vector<double> points;
//     if (delta(a, b, c) > 0)
//     {
//         double x1 = (-2 * b + sqrt(delta(a, b, c))) / (6 * a);
//         double x2 = (-2 * b - sqrt(delta(a, b, c))) / (6 * a);
//         if (x1 > x2)
//             swap(x1, x2);
//         points = {-100, x1, x2, 100};
//     }
//     else if (delta(a, b, c) == 0)
//     {
//         double x = -b / (3 * a);
//         points = {-100, x, 100};
//     }
//     else
//     {
//         points = {-100, 100};
//     }
//     for (size_t i = 0; i < points.size() - 1; i++)
//     {
//         double left = points[i];
//         double right = points[i + 1];
//         double fLeft = f(left, a, b, c, d);
//         double fRight = f(right, a, b, c, d);
//         if (abs(fLeft) < eps)
//             roots.push_back(left);
//         else if (abs(fRight) < eps)
//             roots.push_back(right);
//         else if (fLeft * fRight < 0)
//         {
//             roots.push_back(bisection(left, right, a, b, c, d));
//         }
//         // 去重部分
//         sort(roots.begin(), roots.end());
//         auto last = unique(roots.begin(), roots.end(), [](double a, double b)
//                            { return abs(a - b) < 1e-5; });
//         roots.erase(last, roots.end());
//     }
//     return roots;
// }
// int main()
// {
//     int a, b, c, d;
//     while (cin >> a >> b >> c >> d)
//     {
//         double left = -100.;
//         double right = 100.;
//         vector<double> points;
//         for (double i = -100.; i <= 100.; i++)
//         {
//             if (f_(i, a, b, c, d) == 0)
//             {
//                 points.push_back(i);
//             }
//         }
//         vector<double> roots = solveCubicAllRoots(a, b, c, d);
//         for (size_t i = 0; i < roots.size(); i++)
//         {
//             cout << fixed << setprecision(2) << roots[i] << " ";
//         }
//     }
//     return 0;
// }
/**
 * 以上是在洛谷中能部分通过的代码
 */

double a, b, c, d;

double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    // 加快输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> a >> b >> c >> d)) return 0;

    int found_roots = 0;

    // 题目规定根的范围在 -100 到 100 之间，步长为 1 进行区间扫描
    for (double i = -100.0; i < 100.0; i += 1.0) {
        double x1 = i;
        double x2 = i + 1.0;
        double y1 = f(x1);
        double y2 = f(x2);

        // 情况1：如果左端点本身就是根（值为 0）
        if (abs(y1) < 1e-6) {
            cout << fixed << setprecision(2) << x1 << " ";
            found_roots++;
            if (found_roots == 3) break;
            continue;
        }
        // 情况2：如果两端点异号，说明在 (x1, x2) 之间有根，用二分法精确查找
        if (y1 * y2 < 0) {
            double left = x1, right = x2;
            while (right - left > 1e-4) {
                double mid = (left + right) / 2.0;
                if (f(mid) * f(left) <= 0) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            cout << fixed << setprecision(2) << left << " ";
            found_roots++;
            if (found_roots == 3) break;
        }
    }
    // 检查如果正好 100.0 是最后一个根
    if (found_roots < 3 && abs(f(100.0)) < 1e-6) {
        cout << fixed << setprecision(2) << 100.0 << " ";
    }
    cout << endl;
    return 0;
}

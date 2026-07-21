#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    // 读取输入的三个实数a, b, c
    scanf("%lf %lf %lf", &a, &b, &c);

    // 情况1：a=0, b=0, c=0，恒等式
    if (a == 0 && b == 0 && c == 0) {
        printf("identical equation\n");
    }
    // 情况2：a=0, b=0, c≠0，不是方程
    else if (a == 0 && b == 0 && c != 0) {
        printf("not a equation\n");
    }
    // 情况3：a=0，一元一次方程
    else if (a == 0) {
        double x = -c / b;
        printf("x=%.2f\n", x);
    }
    // 情况4：a≠0，一元二次方程
    else {
        double delta = b * b - 4 * a * c;
        // 判别式等于0，有一个实根
        if (delta == 0) {
            double x = -b / (2 * a);
            printf("x=%.2f\n", x);
        }
        // 判别式大于0，有两个实根
        else if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            // 按从大到小输出
            if (x1 < x2) {
                double temp = x1;
                x1 = x2;
                x2 = temp;
            }
            printf("x1=%.2f\nx2=%.2f\n", x1, x2);
        }
        // 判别式小于0，有两个虚根
        else {
            double real = -b / (2 * a);
            double imag = sqrt(-delta) / (2 * a);
            printf("x1=%.2f+%.2fi\nx2=%.2f-%.2fi\n", real, imag, real, imag);
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Hàm tính giá trị của f(x) = e^x - 2 - cos(e^x - 2)
double func(double x) {
    return exp(x) - 2 - cos(exp(x) - 2);
}

double bisection(double a, double b, double tol) {
    double c;
    while ((b - a) >= tol) {
        c = (a + b) / 2;
        if (func(c) == 0.0)
            break;
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

int main() {
    double a = 0.5; 
    double b = 1.5; 
    double tol = 0.00001;
    double result = bisection(a, b, tol);
    cout << "Nghiệm gần đúng của phương trình là: " << result << endl;
    return 0;
}

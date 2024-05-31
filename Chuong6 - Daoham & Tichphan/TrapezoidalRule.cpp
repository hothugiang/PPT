#include <bits/stdc++.h>
using namespace std;

double trapezoidalRule(function<double(double)> func, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));

    for (int i = 1; i < n; ++i) {
        sum += func(a + i * h);
    }

    return sum * h;
}

int main() {
    auto func = [](double x) {
        return pow(x, 4); 
    };

    double a = 0.5;
    double b = 1.0;

    int n = 1000;

    double result = trapezoidalRule(func, a, b, n);

    cout << fixed << setprecision(10);
    cout << "Gia tri xap xi cua tich phan: " << result << endl;

    return 0;
}

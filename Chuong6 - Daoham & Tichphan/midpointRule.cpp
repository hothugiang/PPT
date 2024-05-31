#include <bits/stdc++.h>
using namespace std;

double midpointRule(function<double(double)> func, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        double midpoint = a + (i + 0.5) * h;
        sum += func(midpoint);
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

    double result = midpointRule(func, a, b, n);

    cout << fixed << setprecision(10);
    cout << "Gia tri xap xi cua tich phan: " << result << endl;

    return 0;
}

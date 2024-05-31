#include <bits/stdc++.h>
using namespace std;

double simpsonRule(function<double(double)> func, double a, double b, int n) {
    if (n % 2 != 0) {
        cout << "n phải là số chẵn" << endl;
        return 0;
    }

    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for (int i = 1; i < n; i += 2) {
        sum += 4 * func(a + i * h);
    }

    for (int i = 2; i < n - 1; i += 2) {
        sum += 2 * func(a + i * h);
    }

    return sum * (h / 3);
}

int main() {
    auto func = [](double x) {
        return pow(x, 4); 
    };

    double a = 0.5;
    double b = 1.0;

    int n = 1000;

    double result = simpsonRule(func, a, b, n);

    cout << fixed << setprecision(10);
    cout << "Gia tri xap xi cua tich phan: " << result << endl;

    return 0;
}

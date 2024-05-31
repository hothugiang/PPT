#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return sin(x) * exp(2 * x);
}

double calculateFactorial(int x) {
    if (x == 0) {
        return 1.0;
    } else {
        return x * calculateFactorial(x - 1);
    }
}

int main() {
    double a = 0;
    double b = M_PI / 2;
    int n = 50; 
    double h = (b - a) / n;
    vector<double> f_values(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        f_values[i] = f(a + i * h);
    }
    
    vector<vector<double>> deltaF(n);
    for (int i = 0; i < n; ++i) {
        deltaF[i].resize(n - i);
    }

    for (int i = 0; i < n; ++i) {
        deltaF[0][i] = f_values[i + 1] - f_values[i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            deltaF[i][j] = deltaF[i - 1][j + 1] - deltaF[i - 1][j];
        }
    }

    double x = M_PI / 200;
    double s = (x - a) / h;
    double px = f_values[0];
    for (int i = 0; i < n; ++i) {
        double temp = 1.0;
        for (int j = i; j >= 0; --j) {
            temp *= (s - j);
        }
        temp /= calculateFactorial(i + 1);
        px += temp * deltaF[i][0];
    }

    cout << "Gia tri cua f(x) tinh boi da thuc noi suy la:" << endl;
    cout << fixed << setprecision(10) << px << endl;
    cout << "Sai so cua bieu thuc la:" << endl;
    cout << fixed << setprecision(10) << abs(f(x) - px) << endl;

    return 0;
}

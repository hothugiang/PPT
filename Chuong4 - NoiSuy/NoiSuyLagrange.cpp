#include <bits/stdc++.h>
using namespace std;

int num;
vector<double> x_values;
vector<double> y_values;

double f(double x) {
    return exp(2 * x);
}

string printL(int x) {
    string result = "";
    double denominator = 1;
    for (int i = 0; i < num; ++i) {
        if (i == x) continue;
        double val = x_values[i];
        double valRound = round(val * 1000000) / 1000000;
        result += "(x-" + to_string(valRound) + ")";
        denominator *= (x_values[x] - x_values[i]);
    }
    result += "/" + to_string(round(denominator * 1000000) / 1000000);
    result += " * " + to_string(round(y_values[x] * 1000000) / 1000000);
    return result;
}

double calcL(int x, double val) {
    double result = 1;
    double denominator = 1;
    for (int i = 0; i < num; ++i) {
        if (i == x) continue;
        result *= (val - x_values[i]);
        denominator *= (x_values[x] - x_values[i]);
    }
    result /= denominator;
    result *= y_values[x];
    return result;
}

int main() {
    x_values = {0, 0.25, 0.5, 0.75};
    y_values = {1, 1.64872, 2.71828, 4.48169};
    num = x_values.size();

    cout << "Da thuc noi suy cua f(x) theo phuong phap Lagrange:" << endl;
    for (int i = 0; i < num; ++i) {
        cout << printL(i);
        if (i < num - 1) cout << " + ";
        cout << endl;
    }

    double x = 0.6;
    double result = 0;
    for (int i = 0; i < num; ++i) {
        result += calcL(i, x);
    }

    cout << "Gia tri cua f(x) tai x = " << x << " tinh boi da thuc noi suy Lagrange la:" << endl;
    cout << fixed << setprecision(10) << result << endl;
    cout << "Sai so cua bieu thuc la:" << endl;
    cout << fixed << setprecision(10) << abs(f(x) - result) << endl;

    return 0;
}

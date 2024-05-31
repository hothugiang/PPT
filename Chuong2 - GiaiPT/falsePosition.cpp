#include <bits/stdc++.h>
using namespace std;

// Hàm f(x) = x^3 - 2x^2 - 5
double func(double x) {
    return pow(x, 3) - 2 * pow(x, 2) - 5;
}

// Phương pháp False Position
double falsePositionMethod(double a, double b, double tol, int max_iter) {
    double fa = func(a);
    double fb = func(b);
    double c;
    for (int i = 0; i < max_iter; ++i) {
        c = (a * fb - b * fa) / (fb - fa);
        double fc = func(c);

        if (fabs(fc) < tol)
            return c;

        if (fc * fa < 0)
            b = c;
        else
            a = c;

        fa = func(a);
        fb = func(b);
    }

    cout << "Max Iteration Reached!" << endl;
    return NAN;
}

int main() {
    double a = 1.0;
    double b = 4.0; 
    double tol = 1e-4; 
    int max_iter = 1000;

    double result = falsePositionMethod(a, b, tol, max_iter);
    if (!isnan(result)) {
        cout << "Nghiệm gần đúng của phương trình là: " << result << endl;
    }

    return 0;
}

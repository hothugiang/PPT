#include <bits/stdc++.h>
using namespace std;

// Hàm f(x) = x^3 - 2x^2 - 5
double func(double x) {
    return pow(x, 3) - 2 * pow(x, 2) - 5;
}

// Đạo hàm của f(x)
double derivative(double x) {
    return 3 * pow(x, 2) - 4 * x;
}

double newtonMethod(double x0, double tol = 1e-6, int max_iter = 1000) {
    for (int i = 0; i < max_iter; ++i) {
        double fx = func(x0);
        if (fabs(fx) < tol)
            return x0;

        double dfx = derivative(x0);
        if (dfx == 0) {
            cout << "Error: Zero derivative at x0 = " << x0 << endl;
            return NAN;
        }
        
        x0 = x0 - fx / dfx;
    };

    return NAN;
}

int main() {
    double x0 = 2.0; 
    double tol = 1e-4; 
    int max_iter = 1000;

    double result = newtonMethod(x0, tol, max_iter);
    if (!isnan(result)) {
        cout << "Nghiệm gần đúng của phương trình là: " << result << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Hàm f(x) = x^3 - 2x^2 - 5
double func(double x) {
    return pow(x, 3) - 2 * pow(x, 2) - 5;
}

double secantMethod(double x0, double x1, double tol = 1e-6, int max_iter = 1000) {
    double fx0 = func(x0);
    double fx1 = func(x1);
    double x_next;
    for (int i = 0; i < max_iter; ++i) {

        x_next = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        double fx_next = func(x_next);
        
        if (fabs(fx_next) < tol)
            return x_next;

        x0 = x1;
        x1 = x_next;
        fx0 = fx1;
        fx1 = fx_next;
    }

    cout << "Max Iteration Reached!" << endl;
    return NAN;
}

int main() {
    double a = 1.0;
    double b = 4.0; 
    double tol = 1e-4;
    int max_iter = 1000;

    double result = secantMethod(a, b, tol, max_iter);
    if (!isnan(result)) {
        cout << "Nghiệm gần đúng của phương trình là: " << result << endl;
    }

    return 0;
}

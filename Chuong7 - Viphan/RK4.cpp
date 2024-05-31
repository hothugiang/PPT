#include <bits/stdc++.h>
using namespace std;

// y" = f(x, y, y')
double f(double x, double y, double yp) {
    return 6 * exp(-x) + 3 * yp - 2 * y;
}

// RK4
void rungeKutta(double x0, double y0, double yp0, double h, double x_target) {
    double x = x0;
    double y = y0;
    double yp = yp0;
    double k1, k2, k3, k4;
    cout << "x\t y" << endl;
    cout << x << "\t" << y << endl;
    while (x < x_target - h) {
        k1 = h * yp;
        k2 = h * (yp + 0.5 * k1);
        k3 = h * (yp + 0.5 * k2);
        k4 = h * (yp + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        yp = yp + (f(x, y, yp) + f(x + h, y + h * yp, yp + k1)) / 2.0;
        x = x + h;
        cout << x << "\t" << y << endl;
    }
}

int main() {
    double x0 = 0.0; 
    double y0 = 2.0; 
    double yp0 = 2.0;
    double h = 0.1; 
    double x_target = 1.0;
    rungeKutta(x0, y0, yp0, h, x_target);
    return 0;
}

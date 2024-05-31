#include <iostream>
#include <cmath>

using namespace std;

// y' = f(x, y)
double f(double x, double y) {
    return (2.0 / x) * y + pow(x, 2) * exp(x);
}

void eulerMethod(double x0, double y0, double h, int steps) {
    double x = x0;
    double y = y0;

    cout << "x" << "\t" << "y" << endl;
    cout << x << "\t" << y << endl;

    for (int i = 0; i <= steps; ++i) {
        y = y + h * f(x, y);
        x = x + h;
        cout << x << "\t" << y << endl;
    }
}

int main() {
    double x0 = 1.0; 
    double y0 = 0.0;
    double h = 0.1; 
    int steps = (2.0 - x0) / h; 

    eulerMethod(x0, y0, h, steps);

    return 0;
}

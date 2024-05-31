#include <bits/stdc++.h>
using namespace std;

// y' = f(x, y)
double f(double x, double y) {
    return x * exp(3 * x) - 2 * y;
}

void heunMethod(double x0, double y0, double h, int steps) {
    double x = x0;
    double y = y0;

    cout << "x" << "\t" << "y" << endl;
    cout << x << "\t" << y << endl;

    for (int i = 0; i < steps; ++i) {
        double y_predict = y + h * f(x, y); 
        double y_correct = y + (h / 2.0) * (f(x, y) + f(x + h, y_predict));  
        x = x + h;
        y = y_correct;

        cout << x << "\t" << y << endl;
    }
}

int main() {
    double x0 = 0.0; 
    double y0 = 0.0;
    double h = 0.5;  
    int steps = (1.0 - x0) / h; 

    heunMethod(x0, y0, h, steps);

    return 0;
}

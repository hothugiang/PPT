#include <bits/stdc++.h>
using namespace std;

// y' = f(x, y)
double f(double x, double y) {
    return (2.0 / x) * y + pow(x, 2) * exp(x);
}

// đạo hàm bậc n của y tại x
double computeNthDerivative(int n, double x, double y, const vector<double>& derivatives) {
    if (n == 0) return y;
    if (n == 1) return f(x, y);

    if (n == 2) {
        double y1 = derivatives[1]; // y'
        return (-2.0 / (x * x)) * y + (2.0 / x) * y1 + (2.0 * x + x * x) * exp(x);
    } else if (n == 3) {
        double y1 = derivatives[1]; // y'
        double y2 = derivatives[2]; // y''
        return (6.0 / (x * x * x)) * y - (6.0 / (x * x)) * y1 + (2.0 / x) * y2 + (6.0 + 6.0 * x + x * x) * exp(x);
    } else if (n == 4) {
        double y1 = derivatives[1]; // y'
        double y2 = derivatives[2]; // y''
        double y3 = derivatives[3]; // y'''
        return (-24.0 / (x * x * x * x)) * y + (24.0 / (x * x * x)) * y1 - (12.0 / (x * x)) * y2 + (2.0 / x) * y3 + (24.0 * x + 24.0 * x * x + 12.0 * x * x * x + x * x * x * x) * exp(x);
    }
    
    return 0.0; 
}

void taylorMethod(double x0, double y0, double h, int steps, int order) {
    double x = x0;
    double y = y0;

    cout << "x" << "\t" << "y" << endl;
    cout << x << "\t" << y << endl;

    vector<double> derivatives(order + 1);
    
    for (int i = 0; i <= steps; ++i) {
        derivatives[0] = y;

        for (int j = 1; j <= order; ++j) {
            derivatives[j] = computeNthDerivative(j, x, y, derivatives);
        }

        for (int j = 1; j <= order; ++j) {
            y += pow(h, j) / tgamma(j + 1) * derivatives[j];
        }

        x += h;
        cout << x << "\t" << y << endl;
    }
}

int main() {
    double x0 = 1.0;
    double y0 = 0.0;
    double h = 0.1;  
    int steps = (2.0 - x0) / h;  
    int order;     

    cout << "Nhập bậc của phương pháp Taylor: ";
    // cin >> order;
    order = 2;

    taylorMethod(x0, y0, h, steps, order);

    return 0;
}
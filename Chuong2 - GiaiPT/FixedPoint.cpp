#include <bits/stdc++.h>
using namespace std;

// Hàm g(x) 
double g(double x) {
    return 0.5 * (x + 3.0 / x); 
}

double fixedPointIteration(double x0, double tol) {
    double x = x0;
    double x_new;

    do {
        x_new = g(x); 
        if (abs(x_new - x) < tol)
            break;
        x = x_new;
    } while (true);

    return x_new;
}

int main() {
    double initial_guess = 1.0; 
    double tol = 0.0001;

    double result = fixedPointIteration(initial_guess, tol);
    cout << "Nghiệm gần đúng của căn bậc hai của 3 là: " << result << endl;

    return 0;
}

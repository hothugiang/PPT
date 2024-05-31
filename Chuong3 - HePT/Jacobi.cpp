#include <bits/stdc++.h>
using namespace std;

double maxAbsoluteError(vector<double> x, vector<double> y) {
    double maxError = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        double error = abs(x[i] - y[i]);
        if (error > maxError) {
            maxError = error;
        }
    }
    return maxError;
}

vector<double> jacobi(vector<vector<double>> A, vector<double> b, vector<double> x0, double tol = 1e-6, int max_iter = 1000) {
    int n = A.size();
    vector<double> x = x0;
    vector<double> error(n, 0.0); 
    int iteration = 0;

    do {
        vector<double> previousX = x;

        for (int i = 0; i < n; ++i) {
            double sum = b[i];
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sum -= A[i][j] * previousX[j];
                }
            }
            x[i] = sum / A[i][i];
            error[i] = abs(x[i] - previousX[i]);
        }

        iteration++;
    } while (maxAbsoluteError(x, x0) > tol && iteration < max_iter);

    cout << "Số lần lặp: " << iteration << endl;

    return x;
}

int main() {
    // Ax = b
    vector<vector<double>> A = {
        {5, 1, 2},
        {1, 4, -2},
        {2, 3, 8}
    };
    vector<double> b = {19, -2, 39};

    vector<double> x0 = {1, 1, 1}; 

    vector<double> solution = jacobi(A, b, x0);

    cout << "Nghiệm gần đúng của hệ phương trình là:" << endl;
    for (size_t i = 0; i < solution.size(); ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}

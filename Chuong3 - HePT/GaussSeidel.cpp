#include <bits/stdc++.h>
using namespace std;

// Hàm tính giá trị lớn nhất trong vectơ lỗi
double maxError(vector<double> error) {
    double max = error[0];
    for (size_t i = 1; i < error.size(); ++i) {
        if (error[i] > max) {
            max = error[i];
        }
    }
    return max;
}

// Hàm giải hệ phương trình bằng phương pháp Gauss-Seidel
vector<double> gaussSeidel(vector<vector<double>> A, vector<double> b, vector<double> x0, double tol = 1e-6, int max_iter = 1000) {
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
                    sum -= A[i][j] * x[j];
                }
            }
            x[i] = sum / A[i][i]; 
            error[i] = abs(x[i] - previousX[i]);
        }

        iteration++;
    } while (maxError(error) > tol && iteration < max_iter);

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

    vector<double> solution = gaussSeidel(A, b, x0);

    cout << "Nghiệm gần đúng của hệ phương trình là:" << endl;
    for (size_t i = 0; i < solution.size(); ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}

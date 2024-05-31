#include <bits/stdc++.h>
using namespace std;

vector<double> matrixVectorProduct(const vector<vector<double>>& A, const vector<double>& x) {
    int n = A.size();
    vector<double> result(n, 0.0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i] += A[i][j] * x[j];
        }
    }
    return result;
}

vector<double> normalize(const vector<double>& x) {
    double norm = 0.0;
    for (double xi : x) {
        norm += xi * xi;
    }
    norm = sqrt(norm);
    vector<double> result(x.size());
    for (int i = 0; i < x.size(); ++i) {
        result[i] = x[i] / norm;
    }
    return result;
}

pair<double, vector<double>> rayleighQuotientIteration(const vector<vector<double>>& A, vector<double> x, int iter = 100) {
    int n = A.size();
    double lambda = 0.0;
    for (int i = 0; i < iter; ++i) {
        x = normalize(x);
        vector<double> Ax = matrixVectorProduct(A, x);
        lambda = inner_product(Ax.begin(), Ax.end(), x.begin(), 0.0) / inner_product(x.begin(), x.end(), x.begin(), 0.0);

        vector<double> y(n, 0.0);
        for (int k = 0; k < n; ++k) {
            double sigma = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != k) {
                    sigma += A[k][j] * y[j];
                }
            }
            y[k] = (x[k] - sigma) / A[k][k];
        }

        x = y;
    }
    return make_pair(lambda, normalize(x));
}

int main() {
    vector<vector<double>> A = {{3, 2}, {2, 3}};
    vector<double> x = {1, 0};
    int iter = 50;

    auto result = rayleighQuotientIteration(A, x, iter);

    cout << "Giá trị riêng lớn nhất: " << result.first << endl;
    cout << "Vector riêng tương ứng: ";
    for (double xi : result.second) {
        cout << xi << " ";
    }
    cout << endl;

    return 0;
}

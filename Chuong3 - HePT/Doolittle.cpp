#include <bits/stdc++.h>
using namespace std;

//A=LU
void doolittleDecomposition(const vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    L.resize(n, vector<double>(n, 0));
    U.resize(n, vector<double>(n, 0));

    for (int i = 0; i < n; ++i) {
        L[i][i] = 1;

        for (int j = i; j < n; ++j) {
            double sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += (L[i][k] * U[k][j]);
            }
            U[i][j] = A[i][j] - sum;
        }

        for (int j = i + 1; j < n; ++j) {
            double sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += (L[j][k] * U[k][i]);
            }
            L[j][i] = (A[j][i] - sum) / U[i][i];
        }
    }
}

vector<double> solve(const vector<vector<double>>& L, const vector<vector<double>>& U, const vector<double>& b) {
    int n = L.size();
    vector<double> y(n, 0), x(n, 0);

    // Giải hệ phương trình Ly = b
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < i; ++j) {
            sum += L[i][j] * y[j];
        }
        y[i] = b[i] - sum;
    }

    // Giải hệ phương trình Ux = y
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }

    return x;
}

int main() {
    // Ax = b
    vector<vector<double>> A = {
        {2, 1, -1},
        {3, 4, 1},
        {1, -4, 5}
    };

    vector<double> b = {1, 8, -2};

    vector<vector<double>> L, U;
    doolittleDecomposition(A, L, U);

    vector<double> x = solve(L, U, b);

    cout << "Nghiệm của hệ phương trình:" << endl;
    for (int i = 0; i < x.size(); ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isSymmetric(const vector<vector<double>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i][j] != A[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool isPositiveDefinite(const vector<vector<double>>& A) {
    int n = A.size();
    for (int k = 0; k < n; k++) {
        double sum = 0;
        for (int j = 0; j < k; j++) {
            sum += pow(A[k][j], 2);
        }
        if (A[k][k] - sum <= 0) {
            return false;
        }
    }
    return true;
}

vector<vector<double>> choleskyDecomposition(const vector<vector<double>>& A) {
    int n = A.size();
    vector<vector<double>> L(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L[i][k] * L[j][k];
            }
            L[i][j] = (i == j) ? sqrt(A[i][i] - sum) : (A[i][j] - sum) / L[j][j];
        }
    }
    return L;
}

vector<double> forwardSubstitution(const vector<vector<double>>& L, const vector<double>& b) {
    int n = L.size();
    vector<double> y(n);
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }
    return y;
}

vector<double> backwardSubstitution(const vector<vector<double>>& U, const vector<double>& b) {
    int n = U.size();
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / U[i][i];
    }
    return x;
}

vector<vector<double>> transpose(const vector<vector<double>>& A) {
    int n = A.size();
    vector<vector<double>> result(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[j][i];
        }
    }
    return result;
}

vector<double> solve(const vector<vector<double>>& A, const vector<double>& b) {
    if (!isSymmetric(A) || !isPositiveDefinite(A)) {
        cout << "Ma trận A không đối xứng hoặc không xác định dương" << endl;
        exit(1);
    }
    vector<vector<double>> L = choleskyDecomposition(A);
    vector<double> y = forwardSubstitution(L, b);
    vector<vector<double>> L_transpose = transpose(L);
    vector<double> x = backwardSubstitution(L_transpose, y);
    return x;
}

int main() {
    vector<vector<double>> A = {
        {2, -1, 0},
        {-1, 2, -1},
        {0, -1, 2}
    };
    vector<double> b = {3, -3, 1};

    vector <double> solution = solve(A, b);

    cout << "Nghiệm gần đúng của hệ phương trình là:" << endl;

    for (size_t i = 0; i < solution.size(); ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<double> solve(const vector<vector<double>>& coefficients, const vector<double>& constants) {
    int rowCount = coefficients.size();
    int columnCount = coefficients[0].size();

    // Tạo ma trận mở rộng gồm ma trận hệ số và ma trận hằng số
    vector<vector<double>> augmentedMatrix(rowCount, vector<double>(columnCount + 1));
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < columnCount; ++j) {
            augmentedMatrix[i][j] = coefficients[i][j];
        }
        augmentedMatrix[i][columnCount] = constants[i];
    }

    // Áp dụng phương pháp Gauss-Jordan
    for (int pivot = 0; pivot < rowCount; ++pivot) {
        int maxRowIndex = pivot;
        double maxRowValue = fabs(augmentedMatrix[pivot][pivot]);
        for (int i = pivot + 1; i < rowCount; ++i) {
            double currentRowValue = fabs(augmentedMatrix[i][pivot]);
            if (currentRowValue > maxRowValue) {
                maxRowValue = currentRowValue;
                maxRowIndex = i;
            }
        }

        swap(augmentedMatrix[pivot], augmentedMatrix[maxRowIndex]);

        double pivotValue = augmentedMatrix[pivot][pivot];
        for (int j = pivot; j < columnCount + 1; ++j) {
            augmentedMatrix[pivot][j] /= pivotValue;
        }

        for (int i = 0; i < rowCount; ++i) {
            if (i != pivot) {
                double factor = augmentedMatrix[i][pivot];
                for (int j = pivot; j < columnCount + 1; ++j) {
                    augmentedMatrix[i][j] -= factor * augmentedMatrix[pivot][j];
                }
            }
        }
    }

    vector<double> solution(rowCount);
    for (int i = 0; i < rowCount; ++i) {
        solution[i] = augmentedMatrix[i][columnCount];
    }

    return solution;
}

double calculateFunction(double x) {
    return sin(x);
}

int main() {
    double a, b;
    int n, lv;

    cout << "Nhap a: ";
    // cin >> a;
    a = 2;
    cout << "Nhap b: ";
    // cin >> b;
    b = 5;
    cout << "Nhap n: ";
    // cin >> n;
    n = 3;

    double h = (b - a) / n;
    vector<double> x(n + 1);
    for (int i = 0; i <= n; ++i) {
        x[i] = a + i * h;
    }

    cout << "Nhap bac cua phuong trinh: ";
    // cin >> lv;
    lv = 2;

    vector<vector<double>> matrix(lv + 1, vector<double>(lv + 1));
    for (int i = 0; i <= lv; ++i) {
        for (int j = 0; j <= lv; ++j) {
            double temp = 0;
            for (int k = 0; k <= n; ++k) {
                temp += pow(x[k], i + j);
            }
            matrix[i][j] = temp;
        }
    }

    vector<double> y(lv + 1);
    for (int i = 0; i <= lv; ++i) {
        double temp = 0;
        for (int j = 0; j <= n; ++j) {
            temp += pow(x[j], i) * calculateFunction(x[j]);
        }
        y[i] = temp;
    }

    vector<double> result = solve(matrix, y);
    for (double coeff : result) {
        cout << fixed << setprecision(10) << coeff << endl;
    }

    return 0;
}

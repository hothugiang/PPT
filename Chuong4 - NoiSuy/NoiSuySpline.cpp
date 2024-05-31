#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return sin(x) * exp(2 * x);
}

vector<double> solve(vector<vector<double>> A, vector<double> b) {
    int n = A.size();

    // Tạo ma trận mở rộng bao gồm ma trận A và vector b
    vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmentedMatrix[i][j] = A[i][j];
        }
        augmentedMatrix[i][n] = b[i];
    }

    // Áp dụng phương pháp Gauss
    for (int pivot = 0; pivot < n - 1; ++pivot) {
        int nonZeroRow = -1;
        for (int i = pivot; i < n; ++i) {
            if (augmentedMatrix[i][pivot] != 0) {
                nonZeroRow = i;
                break;
            }
        }

        // Hoán đổi hàng
        if (nonZeroRow != -1) {
            swap(augmentedMatrix[pivot], augmentedMatrix[nonZeroRow]);
        } else {
            return vector<double>();
        }

        // Loại bỏ phần tử chính hợp lệ khỏi các hàng dưới
        for (int i = pivot + 1; i < n; ++i) {
            double factor = augmentedMatrix[i][pivot] / augmentedMatrix[pivot][pivot];
            for (int j = pivot; j <= n; ++j) {
                augmentedMatrix[i][j] -= factor * augmentedMatrix[pivot][j];
            }
        }
    }

    vector<double> solution(n);

    for (int i = n - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += augmentedMatrix[i][j] * solution[j];
        }
        solution[i] = (augmentedMatrix[i][n] - sum) / augmentedMatrix[i][i];
    }

    return solution;
}

vector<double> calcCoef(const vector<double>& a) {
    int num = a.size();
    int size = (num - 1) * 4;
    vector<vector<double>> arr(size, vector<double>(size, 0.0));
    vector<double> b(size);

    int index = 0;
    int index2 = 0;
    while (index2 < size) {
        if (index == 0) {
            arr[index2][index * 4] = pow(a[index], 3);
            arr[index2][index * 4 + 1] = pow(a[index], 2);
            arr[index2][index * 4 + 2] = pow(a[index], 1);
            arr[index2][index * 4 + 3] = pow(a[index], 0);
            b[index2] = f(a[index]);
        } else if (index == num - 1) {
            arr[index2][index * 4 - 4] = pow(a[index], 3);
            arr[index2][index * 4 - 3] = pow(a[index], 2);
            arr[index2][index * 4 - 2] = pow(a[index], 1);
            arr[index2][index * 4 - 1] = pow(a[index], 0);
            b[index2] = f(a[index]);
        } else if (index > 0 && index < num - 1) {
            for (int i = 0; i < 2; ++i) {
                arr[index2][(index - 1) * 4 + i * 4] = pow(a[index], 3);
                arr[index2][(index - 1) * 4 + i * 4 + 1] = pow(a[index], 2);
                arr[index2][(index - 1) * 4 + i * 4 + 2] = pow(a[index], 1);
                arr[index2][(index - 1) * 4 + i * 4 + 3] = pow(a[index], 0);
                b[index2] = f(a[index]);
                if (i == 0) ++index2;
            }
        }

        if (index2 == size / 2) {
            arr[index2][0] = 6 * a[0];
            arr[index2][1] = 2;
            b[index2] = 4;
        }
        if (index2 == size / 2 + 1) {
            arr[index2][(num - 2) * 4] = 6 * a[num - 1];
            arr[index2][(num - 2) * 4 + 1] = 2;
            b[index2] = 3 * exp(M_PI);
        }
        if (index2 > size / 2 + 1 && index2 < size) {
            for (int i = 0; i < num - 2; ++i) {
                arr[index2][i * 4] = 3 * pow(a[i + 1], 2);
                arr[index2][i * 4 + 1] = 2 * a[i + 1];
                arr[index2][i * 4 + 2] = 1;
                arr[index2][(i + 1) * 4] = -3 * pow(a[i + 1], 2);
                arr[index2][(i + 1) * 4 + 1] = -2 * a[i + 1];
                arr[index2][(i + 1) * 4 + 2] = -1;
                b[index2] = 0;
                ++index2;
                arr[index2][i * 4] = 6 * a[i + 1];
                arr[index2][i * 4 + 1] = 2;
                arr[index2][(i + 1) * 4] = -6 * a[i + 1];
                arr[index2][(i + 1) * 4 + 1] = -2;
                b[index2] = 0;
                ++index2;
            }
            continue;
        }
        ++index2;
        if (index < num) ++index;
    }

    return solve(arr, b);
}

void printFx(const vector<double>& a) {
    vector<double> x = calcCoef(a);
    int num = a.size();
    for (int i = 0; i < num - 1; ++i) {
        cout << "F" << i << "(x) = " << x[i * 4] << "*x^3 + " << x[i * 4 + 1] << "*x^2 + " << x[i * 4 + 2] << "*x + " << x[i * 4 + 3] << endl;
    }
}

double calcFx(const vector<double>& a, double val) {
    vector<double> x = calcCoef(a);
    int num = a.size();
    double result = 0;
    for (int i = 0; i < num - 1; ++i) {
        if (val >= a[i] && val <= a[i + 1]) {
            result = x[i * 4] * pow(val, 3) + x[i * 4 + 1] * pow(val, 2) + x[i * 4 + 2] * val + x[i * 4 + 3];
        }
    }
    return result;
}

int main() {
    double left = 0;
    double right = M_PI / 2;
    int num = 50;
    vector<double> a(num);
    for (int i = 0; i < num; ++i) {
        a[i] = left + (right - left) / (num - 1) * i;
    }
    cout << "Da thuc noi suy cua f(x) theo phuong phap Spline voi " << num << " diem moc cach deu:" << endl;
    printFx(a);

    double x = M_PI / 200;
    double result = calcFx(a, x);
    cout << "Gia tri cua f(x) tinh boi da thuc noi suy Spline la:" << endl;
    cout << fixed << setprecision(10) << result << endl;
    cout << "Sai so cua bieu thuc la:" << endl;
    cout << fixed << setprecision(10) << abs(f(x) - result) << endl;
    cout << "Gia tri chinh xac cua f(x) la: " << f(x) << endl;

    return 0;
}

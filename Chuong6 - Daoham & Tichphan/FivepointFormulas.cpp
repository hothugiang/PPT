#include <iostream>
#include <vector>

using namespace std;

double fivePointDerivative(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x5, double y5) {
    double h1 = x2 - x1;
    double h2 = x3 - x2;
    double h3 = x4 - x3;
    double h4 = x5 - x4;

    double delta_y1 = y2 - y1;
    double delta_y2 = y3 - y2;
    double delta_y3 = y4 - y3;
    double delta_y4 = y5 - y4;

    return (-delta_y1 / (12 * h1) + 2 * delta_y2 / (3 * h2) - 2 * delta_y3 / (3 * h3) + delta_y4 / (12 * h4));
}

int main() {
    vector<pair<double, double>> points = {
        {2.1, -1.709847},
        {2.2, -1.373823},
        {2.3, -1.119214},
        {2.4, -0.9160143},
        {2.5, -0.7470223},
        {2.6, -0.6015966}
    };

    cout << "x          f(x)       f'(x)" << endl;

    // Tính đạo hàm tại điểm biên 2.1
    double derivative_at_2_1 = fivePointDerivative(points[0].first, points[0].second, points[1].first, points[1].second, points[2].first, points[2].second, points[3].first, points[3].second, points[4].first, points[4].second);
    cout << points[0].first << "  " << points[0].second << "  " << derivative_at_2_1 << endl;

    for (int i = 2; i < points.size() - 2; ++i) {
        double x1 = points[i - 2].first;
        double y1 = points[i - 2].second;
        double x2 = points[i - 1].first;
        double y2 = points[i - 1].second;
        double x3 = points[i].first;
        double y3 = points[i].second;
        double x4 = points[i + 1].first;
        double y4 = points[i + 1].second;
        double x5 = points[i + 2].first;
        double y5 = points[i + 2].second;

        double derivative = fivePointDerivative(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5);

        cout << x3 << "  " << y3 << "  " << derivative << endl;
    }

    // Tính đạo hàm tại điểm biên 2.6
    double derivative_at_2_6 = fivePointDerivative(points[points.size() - 5].first, points[points.size() - 5].second, points[points.size() - 4].first, points[points.size() - 4].second, points[points.size() - 3].first, points[points.size() - 3].second, points[points.size() - 2].first, points[points.size() - 2].second, points[points.size() - 1].first, points[points.size() - 1].second);
    cout << points[points.size() - 1].first << "  " << points[points.size() - 1].second << "  " << derivative_at_2_6 << endl;

    return 0;
}

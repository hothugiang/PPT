#include <bits/stdc++.h>
using namespace std;

double threePointDerivative(double x1, double y1, double x2, double y2, double x3, double y3) {
    double h1 = x2 - x1;
    double h2 = x3 - x2;

    double delta_y1 = y2 - y1;
    double delta_y2 = y3 - y2;

    return (1 / ((h1 + h2) / h1 / h2)) * ((delta_y2 / h2) - (delta_y1 / h1));
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

    cout << "x               f(x)           f'(x)" << endl;

    double derivative_at_2_1 = threePointDerivative(points[0].first, points[0].second, points[1].first, points[1].second, points[2].first, points[2].second);
    cout << fixed << setprecision(10);
    cout << points[0].first << "  " << points[0].second << "  " << derivative_at_2_1 << endl;

    for (int i = 1; i < points.size() - 1; ++i) {
        double x1 = points[i - 1].first;
        double y1 = points[i - 1].second;
        double x2 = points[i].first;
        double y2 = points[i].second;
        double x3 = points[i + 1].first;
        double y3 = points[i + 1].second;

        double derivative = threePointDerivative(x1, y1, x2, y2, x3, y3);

        cout << fixed << setprecision(10);
        cout << x2 << "  " << y2 << "  " << derivative << endl;
    }

    double derivative_at_2_6 = threePointDerivative(points[points.size() - 3].first, points[points.size() - 3].second, points[points.size() - 2].first, points[points.size() - 2].second, points[points.size() - 1].first, points[points.size() - 1].second);
    cout << fixed << setprecision(10);
    cout << points[points.size() - 1].first << "  " << points[points.size() - 1].second << "  " << derivative_at_2_6 << endl;

    return 0;
}

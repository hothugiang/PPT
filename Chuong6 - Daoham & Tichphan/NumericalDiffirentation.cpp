#include <bits/stdc++.h>
using namespace std;

double forwardDifference(double h, double y0, double y1) {
    return (y1 - y0) / h;
}

double backwardDifference(double h, double y0, double y1) {
    return (y0 - y1) / h;
}

double centralDifference(double h, double y0, double y2) {
    return (y2 - y0) / (2 * h);
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

    double h = 0.1;

    cout << "x          f(x)       f'(x)" << endl;

    double derivative = forwardDifference(h, points[0].second, points[1].second);
    cout << fixed << setprecision(10);
    cout << points[0].first << "  " << points[0].second << "  " << derivative << endl;

    for (int i = 1; i < points.size() - 1; ++i) {
        derivative = centralDifference(h, points[i - 1].second, points[i + 1].second);
        cout << points[i].first << "  " << points[i].second << "  " << derivative << endl;
    }

    derivative = backwardDifference(h, points[points.size() - 1].second, points[points.size() - 2].second);
    cout << points[points.size() - 1].first << "  " << points[points.size() - 1].second << "  " << derivative << endl;

    return 0;
}

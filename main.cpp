#include <iostream>
#include <cmath>

using namespace std;
double step = 0.2;
double g_y1 = -9, g_y2 = 9;
double g_x1 = -9, g_x2 = 9;

double Fun(double x) {
    return sin(x);
}
double dFun(double func(double), double x, double h) {
    return (func(x + h) - func(x)) / h;
}

void graphick() {
    cout << "\nGraph" << endl;
    for (double y = g_y2; y > g_y1; y -= step) {
        for (double x = g_x1; x < g_x2 + 1; x += step) {

            if (fabs(x) <= step / 2 and fabs(y) <= step / 2) cout << "0 ";
            else if (fabs(x) <= step / 2 and fabs(round(y) - y) <= step / 2) {
                if (y < 0) cout << round(y);
                else cout << round(y) << " ";
                if (fabs(round(y)) >= 10000) {
                    x += step; cout << " ";
                }
                if (fabs(round(y)) >= 1000) {
                    x += step; cout << " ";
                }
                if (fabs(round(y)) >= 100) {
                    x += step; cout << " ";
                }
                if (fabs(round(y)) >= 10) {
                    x += step; cout << " ";
                }
            }
            else if (fabs(y) <= step / 2 and fabs(round(x) - x) <= step / 2) {
                if (x < 0 or x >= 10) cout << round(x);
                else cout << round(x) << " ";
            }
            else if (fabs(Fun(x) - y) <= step / 2 * fabs(dFun(Fun, x, 0.0002))) {
                cout << "# ";
            }
            else if (fabs(y) <= step / 2) cout << "= ";
            else if (fabs(x) <= step / 2) cout << "| ";

            else cout << "  ";
        }
        cout << endl;
    }
}

int main() {
    graphick();
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

double f(double x);
int findX(double a, double b, double eps, int deep);

int main()
{
    double a, b, eps, m, f1, f2;
    int deep = 0;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "eps = "; cin >> eps;
    cout << endl;

    do {
        deep++;

        f1 = f(a);
        m = (a + b) / 2;
        f2 = f(m);

        //if (f2 == 0) break;

        if (f1 * f2 < 0)
            b = m; // відкидаємо праву частину
        else
        {
            a = m; // відкидаємо ліву частину
        }
    } while (abs(a - b) >= eps);

    m = (a + b) / 2;
    cout << "x (while):" << m << endl
        << "Deep: " << deep << endl;

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    deep = 0;
    cout << "Deep (rec): " << findX(a, b, eps, deep);


}

int findX(double a, double b, double eps, int deep)
{
    double m = 0, f1, f2;
    f1 = f(a);
    m = (a + b) / 2;
    f2 = f(m);

    if (abs(a - b) >= eps && f2 != 0) {
        if (f1 * f2 < 0)
            b = m; // відкидаємо праву частину
        else
            a = m; // відкидаємо ліву частину

        return findX(a, b, eps, deep + 1);
    }
    else
    {
        cout << "x (rec): " << m << endl;
        return deep;
    }
}

double f(double x)
{
    return sin(x) - cos(x);
}
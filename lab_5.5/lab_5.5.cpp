﻿#include <iostream>
#include <cmath>

using namespace std;

double f(double x);
int findX(double a, double b, double eps, int deep);

int main()
{
    double a, b, eps;
    int deep = 0;

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "eps = "; cin >> eps;
    cout << endl;

    cout << "Deep: " << findX(a, b, eps, deep);


}

int findX(double a, double b, double eps, int deep)
{
    double m, f1, f2;
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
        cout << "x: " << m << endl;
        return deep;
    }
}

double f(double x)
{
    return sin(x) - cos(x);
}
#include <QCoreApplication>
#include <iostream>

#define XX -2 // -1
#define YY 1

#define X 0.0
#define Y 1.0
#define H 0.2 // 0.01

void increaseX(double, double*);
void eulerMethod(double, double*, double*);
void rungeKutta(double, double*, double*);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    double x = X;
    double y = Y;

    for (int i=0; i<3; i++)
    {
        eulerMethod(H, &x, &y);
    }

    x = X;
    y = Y;

    for (int i=0; i<3; i++)
    {
        rungeKutta(H, &x, &y);
    }

    return a.exec();
}

void increaseX(double h, double* x)
{
    double _x = *x + h;

    *x = _x;
}

void print(double x, double y)
{
    std::cout << "x: " << x << "; y: " << y << std::endl;
}

void eulerMethod(double h, double* x, double* y)
{
    double _y = *y + (h * (XX * *x) * (YY * *y));

    print(*x, _y);

    increaseX(h, &*x);

    *y = _y;
}

void rungeKutta(double h, double* x, double* y)
{
    double _k1 = h * (XX * *x) * (YY * *y);
    double _k2 = h * ((XX * *x) + (h / 2)) * ((YY * *y) + (_k1 / 2));
    double _k3 = h * ((XX * *x) + (h / 2)) * ((YY * *y) + (_k2 / 2));
    double _k4 = h * ((XX * *x) + h) * ((YY * *y) +_k3);

    double _y = *y + (_k1 / 6) + (_k2 / 3) + (_k3 / 3) + (_k4 / 6);

    print(*x, _y);

    increaseX(h, &*x);

    *y = _y;
}

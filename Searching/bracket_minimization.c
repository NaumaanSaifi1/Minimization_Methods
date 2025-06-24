#include <stdio.h>
#include <math.h>

#define TOL 0.5e-5

typedef struct {
    double x1;
    double x2;
} Point;

// Swap function for doubles
void Swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Function 1
double func1(double x) {
    return pow(x, 5) - 5 * pow(x, 3) - 20 * x + 5;
}

// Function 2
double func2(double x) {
    return pow(x, 3) / 16.0 - (27.0 * x) / 4.0;
}

// Function 3
double func3(double x) {
    return pow(x, 4) - 14 * pow(x, 3) + 60 * pow(x, 2) - 70 * x;
}

// Function 4
double func4(double x) {
    return -2 * sin(x) + pow(x, 2) / 10.0;
}

// Function 5
double func5(double x) {
    return exp(x) - 5 * x;
}

// Bracket minimum region
Point BracketMin(double (*A)(double), double a, double b) {
    double DELTA = TOL;
    double FACTOR = 2.0;
    double x1 = a, x2 = a + DELTA, x3;
    double f1 = A(x1), f2 = A(x2), f3;

    if (f2 > f1) {
        Swap(&f1, &f2);
        Swap(&x1, &x2);
        DELTA = -DELTA;
    }

    while (1) {
        DELTA *= FACTOR;
        x3 = x2 + DELTA;
        if (x3 > b) x3 = b;
        f3 = A(x3);
        if (f3 > f2)
            break;
        f1 = f2;
        f2 = f3;
        x1 = x2;
        x2 = x3;

        if (fabs(x2 - x1) < TOL) break;
    }

    if (x1 > x3) Swap(&x1, &x3);
    return (Point){x1, x3};
}

int main() {
    Point p1 = BracketMin(func1, -1, 3);
    printf("Function 1: f(x) = x^5 - 5x^3 - 20x + 5\n");
    printf("Bracketed interval: [%.6f, %.6f]\n\n", p1.x1, p1.x2);

    Point p2 = BracketMin(func2, -5, 10);
    printf("Function 2: f(x) = x^3/16 - 27x/4\n");
    printf("Bracketed interval: [%.6f, %.6f]\n\n", p2.x1, p2.x2);

    Point p3 = BracketMin(func3, 0, 2);
    printf("Function 3: f(x) = x^4 - 14x^3 + 60x^2 - 70x\n");
    printf("Bracketed interval: [%.6f, %.6f]\n\n", p3.x1, p3.x2);

    Point p4 = BracketMin(func4, 0, 4);
    printf("Function 4: f(x) = -2sin(x) + x^2/10\n");
    printf("Bracketed interval: [%.6f, %.6f]\n\n", p4.x1, p4.x2);

    Point p5 = BracketMin(func5, -1.5, 3.5);
    printf("Function 5: f(x) = e^x - 5x\n");
    printf("Bracketed interval: [%.6f, %.6f]\n", p5.x1, p5.x2);

    return 0;
}

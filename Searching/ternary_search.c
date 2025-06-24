#include <stdio.h>
#include <math.h>

#define EPS 1e-7

// Ternary Search for Minimum
double ternarySearch(double left, double right, double (*f)(double)) {
    while (right - left > EPS) {
        double m1 = left + (right - left) / 3.0;
        double m2 = right - (right - left) / 3.0;
        if (f(m1) < f(m2))
            right = m2;
        else
            left = m1;
    }
    return (left + right) / 2.0;
}

// Function 1: x^5 - 5x^3 - 20x + 5
double f1(double x) {
    return pow(x, 5) - 5 * pow(x, 3) - 20 * x + 5;
}

// Function 2: x^3 / 16 - 27x / 4
double f2(double x) {
    return pow(x, 3) / 16.0 - 27.0 * x / 4.0;
}

// Function 3: x^4 - 14x^3 + 60x^2 - 70x
double f3(double x) {
    return pow(x, 4) - 14 * pow(x, 3) + 60 * pow(x, 2) - 70 * x;
}

// Function 4: -2sin(x) + x^2 / 10
double f4(double x) {
    return -2 * sin(x) + pow(x, 2) / 10.0;
}

// Function 5: e^x - 5x
double f5(double x) {
    return exp(x) - 5 * x;
}

int main() {
    printf("Function 1: f(x) = x^5 - 5x^3 - 20x + 5\n");
    double x1 = ternarySearch(-1, 3, f1);
    printf("Min at x = %.7f, f(x) = %.7f\n\n", x1, f1(x1));

    printf("Function 2: f(x) = x^3 / 16 - 27x / 4\n");
    double x2 = ternarySearch(-5, 10, f2);
    printf("Min at x = %.7f, f(x) = %.7f\n\n", x2, f2(x2));

    printf("Function 3: f(x) = x^4 - 14x^3 + 60x^2 - 70x\n");
    double x3 = ternarySearch(0, 2, f3);
    printf("Min at x = %.7f, f(x) = %.7f\n\n", x3, f3(x3));

    printf("Function 4: f(x) = -2sin(x) + x^2 / 10\n");
    double x4 = ternarySearch(0, 4, f4);
    printf("Min at x = %.7f, f(x) = %.7f\n\n", x4, f4(x4));

    printf("Function 5: f(x) = e^x - 5x\n");
    double x5 = ternarySearch(-1.5, 3.5, f5);
    printf("Min at x = %.7f, f(x) = %.7f\n\n", x5, f5(x5));

    return 0;
}

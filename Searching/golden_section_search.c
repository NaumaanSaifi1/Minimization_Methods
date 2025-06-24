#include <stdio.h>
#include <math.h>

#define TOL 0.5e-5
#define MAXITER 10000

typedef struct {
    double minx;
    double minvalue; 
} fnData;

// Function prototypes
fnData GoldenMin(double (*A)(double), double a, double b);

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

// Golden Section Minimization
fnData GoldenMin(double (*A)(double), double a, double b){
    double PHI = (sqrt(5.0) - 1) / 2;
    double x1 = b - (b - a) * PHI;
    double x2 = a + (b - a) * PHI;
    double f1 = A(x1);
    double f2 = A(x2);

    while ((b - a) > TOL) {
        if (f1 < f2) {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = b - (b - a) * PHI;
            f1 = A(x1);
        } else {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + (b - a) * PHI;
            f2 = A(x2);
        }
    }

    double x = (a + b) / 2;
    return (fnData){x, A(x)};
}

int main() {
    fnData result1 = GoldenMin(func1, -1, 3);
    printf("Function 1: f(x) = x^5 - 5x^3 - 20x + 5\n");
    printf("Minimum at x = %.6f, f(x) = %.6f\n\n", result1.minx, result1.minvalue);

    fnData result2 = GoldenMin(func2, -5, 10);
    printf("Function 2: f(x) = x^3/16 - 27x/4\n");
    printf("Minimum at x = %.6f, f(x) = %.6f\n\n", result2.minx, result2.minvalue);

    fnData result3 = GoldenMin(func3, 0, 2);
    printf("Function 3: f(x) = x^4 - 14x^3 + 60x^2 - 70x\n");
    printf("Minimum at x = %.6f, f(x) = %.6f\n\n", result3.minx, result3.minvalue);

    fnData result4 = GoldenMin(func4, 0, 4);
    printf("Function 4: f(x) = -2sin(x) + x^2/10\n");
    printf("Minimum at x = %.6f, f(x) = %.6f\n\n", result4.minx, result4.minvalue);

    fnData result5 = GoldenMin(func5, -1.5, 3.5);
    printf("Function 5: f(x) = e^x - 5x\n");
    printf("Minimum at x = %.6f, f(x) = %.6f\n", result5.minx, result5.minvalue);

    return 0;
}

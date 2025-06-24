#include <stdio.h>
#include <math.h>

#define TOL 0.5e-5
#define MAXITER 10000
#define ABS(x) (((x) < 0) ? (-(x)) : (x))


typedef struct {
    double minx;
    double minvalue; 
} fnData;

fnData LinMin(double (*A)(double), double a, double b);

// f(x) = x^5 - 5x^3 - 20x + 5
double func1(double x) {
    return pow(x, 5) - 5 * pow(x, 3) - 20 * x + 5;
}

// f(x) = (x^3)/16 - (27x)/4
double func2(double x) {
    return pow(x, 3) / 16.0 - (27.0 * x) / 4.0;
}

// f(x) = x^4 - 14x^3 + 60x^2 - 70x
double func3(double x) {
    return pow(x, 4) - 14 * pow(x, 3) + 60 * pow(x, 2) - 70 * x;
}

// Linear minimization
fnData LinMin(double (*f)(double), double a, double b){
    double step = 0.001;
    double x = a, y = x+step;
    double fx = f(x), fy = f(y);
    int count = 0;

    while (y < b) {
        if (fy > fx) break;

        fx = fy;
        x = y;
        y += step;
        fy = f(y);
        count++;

        if(ABS(fy-fx) < TOL) return (fnData){x,fx};
    }
    return (fnData){x,fx};
}


int main() {
    fnData result1 = LinMin(func1, -1, 3);
    printf("Function 1: f(x) = x^5 - 5x^3 - 20x + 5\n");
    printf("Minimum at x = %.6f, f(x) = %.6f\n\n", result1.minx, result1.minvalue);

    fnData result2 = LinMin(func2, -5, 10);
    printf("Function 2: f(x) = (x^3)/16 - (27x)/4\n");
    printf("Minimum at x = %.6f, f(x) = %.6f\n\n", result2.minx, result2.minvalue);

    fnData result3 = LinMin(func3, 0, 2);
    printf("Function 3: f(x) = x^4 - 14x^3 + 60x^2 - 70x\n");
    printf("Minimum at x = %.6f, f(x) = %.6f\n", result3.minx, result3.minvalue);

    return 0;
}

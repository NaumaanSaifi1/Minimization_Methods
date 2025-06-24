#include <stdio.h>
#include <math.h>

#define TOL 0.5e-6
#define MAXITERATION 10000
#define ABS(x) (((x) < 0) ? (-(x)) : (x))


typedef struct {
    double minx;
    double minvalue; 
} fnData;

// Function 1 and derivatives
double f1(double x) { return pow(x, 5) - 5 * pow(x, 3) - 20 * x + 5; }
double f1_prime(double x) { return 5 * pow(x, 4) - 15 * pow(x, 2) - 20; }
double f1_double_prime(double x) { return 20 * pow(x, 3) - 30 * x; }

// Function 2 and derivatives
double f2(double x) { return pow(x, 3) / 16.0 - (27.0 * x) / 4.0; }
double f2_prime(double x) { return (3 * pow(x, 2)) / 16.0 - 27.0 / 4.0; }
double f2_double_prime(double x) { return (6 * x) / 16.0; }

// Function 3 and derivatives
double f3(double x) { return pow(x, 4) - 14 * pow(x, 3) + 60 * pow(x, 2) - 70 * x; }
double f3_prime(double x) { return 4 * pow(x, 3) - 42 * pow(x, 2) + 120 * x - 70; }
double f3_double_prime(double x) { return 12 * pow(x, 2) - 84 * x + 120; }

// Function 4 and derivatives
double f4(double x) { return -2 * sin(x) + pow(x, 2) / 10.0; }
double f4_prime(double x) { return -2 * cos(x) + (2 * x) / 10.0; }
double f4_double_prime(double x) { return 2 * sin(x) + 0.2; }

// Function 5 and derivatives
double f5(double x) { return exp(x) - 5 * x; }
double f5_prime(double x) { return exp(x) - 5; }
double f5_double_prime(double x) { return exp(x); }

// Newton Minimization
fnData NewtonMin(double (*f1)(double), double (*f2)(double), double a){
    double x = a;
    int count = 0;
    while(count < MAXITERATION){
        double fd1 = f1(x);
        double fd2 = f2(x);

        if(ABS(fd1) < TOL) break;
        if(ABS(fd2)<TOL){
            printf("Second deriv is too small\n");
            return (fnData){x, f1(x)};
        }

        x = x - fd1 / fd2;
        count++;
    }
    return (fnData){x, f1(x)};
}



int main() {
    fnData result;

    result = NewtonMin(f1_prime, f1_double_prime, 1.0);
    result.minvalue = f1(result.minx);
    printf("Function 1: Minimum at x = %.6f, f(x) = %.6f\n\n", result.minx, result.minvalue);

    result = NewtonMin(f2_prime, f2_double_prime, 0.0);
    result.minvalue = f2(result.minx);
    printf("Function 2: Minimum at x = %.6f, f(x) = %.6f\n\n", result.minx, result.minvalue);

    result = NewtonMin(f3_prime, f3_double_prime, 1.0);
    result.minvalue = f3(result.minx);
    printf("Function 3: Minimum at x = %.6f, f(x) = %.6f\n\n", result.minx, result.minvalue);

    result = NewtonMin(f4_prime, f4_double_prime, 2.0);
    result.minvalue = f4(result.minx);
    printf("Function 4: Minimum at x = %.6f, f(x) = %.6f\n\n", result.minx, result.minvalue);

    result = NewtonMin(f5_prime, f5_double_prime, 0.0);
    result.minvalue = f5(result.minx);
    printf("Function 5: Minimum at x = %.6f, f(x) = %.6f\n", result.minx, result.minvalue);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define STEP_SIZE 0.2
#define MAX_ITER 10000
#define EPSILON 5e-11
#define INTERVAL_LOW -10
#define INTERVAL_HIGH 10

// Function f(x) = x^2 - 4
double f(double x) {
    return x * x - 4;
}

// Derivative f'(x) = 2x
double df(double x) {
    return 2 * x;
}

// Sign function
int sign(double val) {
    return (val > 0) - (val < 0);
}



int main() {
    double x = 1.0;  // Initial guess
    int iter = 0;

    while (iter < MAX_ITER) {
        double grad = df(x);

        // Check for convergence
        if (fabs(grad) < EPSILON) {
            break;
        }

        // Update rule: x = x - alpha * f'(x)
        x = x - STEP_SIZE * grad;

        iter++;
    }

    printf("Minimum found at x = %f after %d iterations\n", x, iter);
    printf("Minimum value f(x) = %f\n", f(x));

    return 0;
}
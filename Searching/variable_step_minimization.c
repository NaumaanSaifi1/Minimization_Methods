#include <stdio.h>
#include <math.h>

#define TOL 0.5e-5
#define MAXITERATION 10000
#define ABS(x) (((x) < 0) ? (-(x)) : (x))


typedef struct {
    double minx;
    double minvalue; 
} fnData;

fnData VarStepMin(double (*A)(double), double a, double b);

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

fnData VarStepMin(double (*f)(double), double a, double b){
    double factor = 2.0, Step = TOL, Epsilon = Step;
    double x= a;
    double fx = f(x);

    int count = 0;
    while(count < MAXITERATION){
        double y = x + Step;

        while(y > b || y < a){
            Step /=factor;
            y = x+Step;
        }

        double fy= f(y);
        if(fy < fx){
            x= y;
            fx = fy;

            if(f(y+ Epsilon) > fy){
                Epsilon = -Epsilon;
                Step /= -factor;
            }else{
                Step *= factor;
            }
        }else{
            Step /= factor;
        }

        count++;
        if(ABS(Step) < TOL) return (fnData){x, fx};
    }
    printf("not converged\n");
    return (fnData){x, fx};
}

int main() {
    fnData result1 = VarStepMin(func1, -1, 3);
    printf("f(x) = x^5 - 5x^3 - 20x + 5\n");
    printf("Minimum at x = %.6f, f(x) = %.6f\n\n", result1.minx, result1.minvalue);

    fnData result2 = VarStepMin(func2, -5, 10);
    printf("f(x) = x^3/16 - 27x/4\n");
    printf("Minimum at x = %.6f, f(x) = %.6f\n\n", result2.minx, result2.minvalue);

    fnData result3 = VarStepMin(func3, 0, 2);
    printf("f(x) = x^4 - 14x^3 + 60x^2 - 70x\n");
    printf("Minimum at x = %.6f, f(x) = %.6f\n", result3.minx, result3.minvalue);

    return 0;
}
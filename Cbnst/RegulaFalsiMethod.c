#include<stdio.h>
#include<math.h>

float func(float x) {
    return (x*x *x - 4*x - 9);
}
void regula_falsi(float *x, float a, float b, int *iter) {
    *x = (a * func(b) - b * func(a)) / (func(b) - func(a));
    ++(*iter);
    printf("x in no of iteeration %d is %f\n", *iter, *x);
}

int main() {
    int iter = 0, maxIter;
    float x, a, b, allerr, x1;
    printf("Enter the first two assumptions a, b: \n");
    scanf("%f %f", &a, &b);

    if (func(a) * func(b) >= 0) {
        printf("Function has the same signs at a and b. The bisection method cannot proceed.\n");

        printf("Re-Enter the first two assumptions a, b: \n");
        scanf("%f %f", &a, &b);
        return -1;
    }

    printf("Enter allowed error: \n");
    scanf("%f", &allerr);

    printf("Enter allowed max iterations: \n");
    scanf("%d", &maxIter);

    regula_falsi(&x, a, b, &iter);

    x1 = x;
    do {
        if (func(a) * func(x) < 0)
            b = x;
        else
            a = x;
        regula_falsi(&x, a, b, &iter);
        if (fabs(x-x1) <= allerr) {
            printf("value of x at iteration %d i = %f\n", iter, x1);
            return 0;
        }
        x1 = x;
    } while (iter);

    printf("Maximum number of iterations reached.\n");
    return 1;
}
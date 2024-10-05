#include<stdio.h>
#include<math.h>

double g(double x) {
    return cbrt(2 * x * x + 4);
}

int main() {
    double x0, x1, tolerance;
    int max_iter, iter = 0;

    // printf("Enter initial guess: ");
    // scanf("%lf", &x0);
    printf("Enter tolerance: ");
    scanf("%lf", &tolerance);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iter);

    do {
        x1 = g(x0);
        iter++;
        printf("Iteration %d: x = %lf\n", iter, x1);

        if (fabs(x1 - x0) < tolerance) {
            printf("Root found at x = %lf after %d iterations\n", x1, iter);
            return 0;
        }

        x0 = x1;
    } while (iter < max_iter);

    printf("Maximum iterations reached without finding the root.\n");
    return 0;
}
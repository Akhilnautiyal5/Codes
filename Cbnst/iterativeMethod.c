#include <stdio.h>
#include <math.h>

// Function f(x) = x^3 + x^2 - 1
double f(double x) {
    return x * x * x + x * x - 1;
}

// Derivative of f(x), f'(x) = 3x^2 + 2x
double f_prime(double x) {
    return 3 * x * x + 2 * x;
}

int main() {
    double x0, x1, tolerance;
    int max_iter, iter = 0;

    printf("Enter initial guess: ");
    scanf("%lf", &x0);  // Initial guess
    printf("Enter tolerance: ");
    scanf("%lf", &tolerance);  // Tolerance value
    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iter);  // Maximum iterations

    do {
        x1 = x0 - f(x0) / f_prime(x0);  // Newton's iteration
        iter++;  // Increment iteration counter
        printf("Iteration %d: x = %lf\n", iter, x1);  // Print current iteration result

        if (fabs(x1 - x0) < tolerance) {  // Convergence check
            printf("Root found at x = %lf after %d iterations\n", x1, iter);
            return 0;
        }

        x0 = x1;  // Update x0 for the next iteration
    } while (iter < max_iter);

    printf("Maximum iterations reached without finding the root.\n");
    return 0;
}

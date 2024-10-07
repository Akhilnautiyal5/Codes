#include <stdio.h>
#include <math.h>

// Function g(x) for the iteration, rewritten form of f(x) = x^3 - 4x - 9
float g(float x) {
    return cbrt(4 * x + 9);  // g(x) = ∛(4x + 9)
}

// Function f(x) = x^3 - 4x - 9
float f(float x) {
    return (x * x * x - 4 * x - 9);  // Original function
}

// Fixed-point iteration step
float fixed_point_iteration(float x, int *itr) {
    float x_next = g(x);  // Apply the fixed-point iteration formula
    (*itr)++;  // Increment iteration count
    printf("At iteration %d, value of x is: %f\n", *itr, x_next);
    return x_next;
}

int main() {
    float x0, x1, allowed_error;
    int max_itr, itr = 0;

    // Get input from the user
    do {
        printf("\nEnter initial approximations x1 & x2 such that f(x1)*f(x2)<0: ");
        scanf("%f %f", &x0, &x1);
    } while (f(x0) * f(x1) >= 0);  // Ensure f(x1) * f(x2) < 0 (sign change)

    printf("Enter allowed error: \n");
    scanf("%f", &allowed_error);

    printf("Enter the maximum number of iterations: \n");
    scanf("%d", &max_itr);

    // Perform the first iteration
    x1 = fixed_point_iteration(x0, &itr);

    // Fixed-point iteration loop
    do {
        x0 = x1;  // Update x0 with the latest value
        x1 = fixed_point_iteration(x0, &itr);

        // Check if the error is within the allowed tolerance
        if (fabs(x1 - x0) < allowed_error) {
            printf("\nRoot found after %d iterations\n", itr);
            printf("Root = %f\n", x1);
            printf("Function value at root = %f\n", f(x1));
            return 0;
        }

    } while (itr < max_itr);

    // If maximum iterations reached
    printf("Max iterations reached!\n");
    return 0;
}

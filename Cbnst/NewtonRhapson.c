#include<stdio.h>
#include<math.h>

// Define the function f(x)
float f(float x) {
    return (x * x * x - 4 * x - 9);  // Example function: f(x) = x^3 - 4x - 9
}

// Define the derivative f'(x)
float f_prime(float x) {
    return (3 * x * x - 4);  // Derivative of f(x): f'(x) = 3x^2 - 4
}

// Newton-Raphson iteration function
float newton_raphson(float x, int *itr) {
    float x_next = x - f(x) / f_prime(x);  // Apply the Newton-Raphson formula
    (*itr)++;  // Increment the iteration counter
    printf("At iteration %d, value of x is: %f\n", *itr, x_next);
    return x_next;
}

int main() {
    float x0, x1, allowed_error;
    int max_itr, itr = 0;

    // Get input from the user
    printf("Enter the initial guess: \n");
    scanf("%f", &x0);

    printf("Enter allowed error: \n");
    scanf("%f", &allowed_error);

    printf("Enter the maximum number of iterations: \n");
    scanf("%d", &max_itr);

    // Perform the first iteration
    x1 = newton_raphson(x0, &itr);

    // Newton-Raphson loop
    do {
        x0 = x1;  // Update x0 with the latest value
        x1 = newton_raphson(x0, &itr);  // Perform the next iteration

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

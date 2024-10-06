#include<stdio.h>
#include<math.h>

// Function f(x) = x^3 - 4
float f(float x) {
    return (x * x * x - 4);
}

int main() {
    float a, b, c, e;
    int count = 1, n;

    // Input the initial guesses for a and b
    printf("Enter the values of a and b (initial guesses):\n");
    scanf("%f %f", &a, &b);

    // Input the allowed error and maximum number of iterations
    printf("Enter the values of allowed error and maximum number of iterations:\n");
    scanf("%f %d", &e, &n);

    if((f(a) == f(b))) { // Prevent division by zero
        printf("Solution cannot be found as f(a) and f(b) are too close.\n");
        return 1;
    }

    // Implementing the Secant method
    do {
        // Calculate the new point c
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        // Print the current iteration result
        printf("Iteration No-%d    x = %f\n", count, c);

        // Check if the error is within the allowed limit
        if(fabs(f(c)) < e) {
            printf("\nThe required solution is %f\n", c);
            return 0;
        }

        // Update a and b for the next iteration
        a = b;
        b = c;
        count++;

        // Check if maximum number of iterations is reached
        if(count > n) {
            printf("Maximum number of iterations reached. Solution may not have converged.\n");
            return 1;
        }

    } while(fabs(f(c)) > e);

    printf("\nThe required solution is %f\n", c);
    return 0;
}

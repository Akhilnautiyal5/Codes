#include<stdio.h>
#include<math.h>

#define f(x) (x*x*x - 4*x - 9)            // Original function f(x) = x^3 - 4x - 9
#define g(x) (pow((4*x + 9), 1/3.0))      // Fixed-point transformation g(x) = ∛(4x + 9)
#define dg(x) (4/3.0 * pow((4*x + 9), -2/3.0))  // Derivative of g(x), g'(x)

int main(void) {
    printf("\nIterative Method\n");
    float a, b, err;

    // Step 1: Input two initial approximations a & b such that f(a)*f(b) < 0
    do {
        printf("\nEnter initial approximation a & b: ");
        scanf("%f %f", &a, &b);
    } while (f(a) * f(b) >= 0);  // Ensure sign change between f(a) and f(b)

    // Step 2: Check the derivative condition
    if (fabs(dg(a)) < 1 && fabs(dg(b)) < 1)
        printf("\nFunction is correct and converges.\n");
        // Step 3: Input the acceptable error
        printf("\nEnter acceptable error: ");
        scanf("%f", &err);
    
        float x0, x1;
        // Step 4: Determine initial guess x0 based on which f(x) value is smaller
        if (fabs(f(a)) < fabs(f(b)))
            x1 = a;  // Use a if f(a) is smaller
        else
            x1 = b;  // Otherwise, use b
    
        int count = 0;
    
        // Step 5: Fixed-point iteration process
        do {
            count++;
            x0 = x1;  // Set the current guess to x0
            x1 = g(x0);  // Compute the next approximation using g(x)
            printf("\nIteration %d: x%d = %f", count, count, x1);
        } while (fabs(x1 - x0) >= err);  // Continue until the error is within the allowed tolerance
    
        // Step 6: Output the root after convergence
        printf("\nRoot of the equation = %f \nafter %d Iterations\n", x1, count);
    
        return 0;
    else {
        printf("\nFunction does not converge.\n");
        return 1;  // Exit if the function does not converge
    }

}

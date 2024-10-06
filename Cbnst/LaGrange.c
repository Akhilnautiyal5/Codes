#include <stdio.h>

int main() {
    int n;
    float xp;

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    // Input the x and y values for the data points
    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    // Input the point where interpolation is to be done
    printf("Enter the value of x at which to interpolate: ");
    scanf("%f", &xp);

    float yp = 0; // Resultant interpolated value at xp

    for (int i = 0; i < n; i++) {
        float L = 1; // Initialize L_i(x) for each i

        // Calculate the Lagrange basis polynomial L_i(x)
        for (int j = 0; j < n; j++) {
            if (i != j) {
                L = L * (xp - x[j]) / (x[i] - x[j]);
            }
        }

        // Add the term y_i * L_i(x) to the final result
        yp += L * y[i];
    }
    printf("The interpolated value at x = %f is y = %f\n", xp, yp);

    return 0;
}

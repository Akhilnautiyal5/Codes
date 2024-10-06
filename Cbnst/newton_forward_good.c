#include <stdio.h>
#include <math.h>

// Function to calculate the product of u terms for forward interpolation
float u_cal_forward(float u, int n) {
    float product = u; // Start with u
    for (int i = 1; i < n; i++) {
        product = product * (u - i); // Multiply by (u - i) for forward interpolation
    }
    return product;
}

// Function to calculate factorial of a number
int fact(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial *= i; // Compute n! (factorial)
    }
    return factorial;
}

int main() {
    // Number of data points (n = 5)
    int n = 5;

    // x-values (known data points)
    float x[] = { 1891, 1901, 1911, 1921, 1931 };

    // y-values corresponding to x-values (y[n][n] to store the difference table)
    float y[n][n];
    y[0][0] = 46;  // f(1891)
    y[1][0] = 66;  // f(1901)
    y[2][0] = 81;  // f(1911)
    y[3][0] = 93;  // f(1921)
    y[4][0] = 101; // f(1931)

    // Filling the forward difference table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            // Calculate the ith difference (y[j][i] = y[j+1][i-1] - y[j][i-1])
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    // Printing the forward difference table
    printf("Forward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("%6.2f\t", y[i][j]); // Print the values in the table
        }
        printf("\n");
    }

    // Value at which we want to interpolate (value = 1925)
    float value = 1925;

    // Initializing the sum with the first y-value (y[0][0])
    float result = y[0][0];

    // Compute the normalized u value for forward interpolation
    float u = (value - x[0]) / (x[1] - x[0]); // u = (xp - x0) / h

    // Calculate the interpolated value using forward differences
    for (int i = 1; i < n; i++) {
        result = result + (u_cal_forward(u, i) * y[0][i]) / fact(i); // Add each term
    }

    // Print the final interpolated value
    printf("\nInterpolated value at %.2f is %.2f\n", value, result);

    return 0;
}

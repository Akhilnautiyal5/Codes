#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100

// Function to calculate the forward difference table
void calculateForwardDiff(float x[], float y[], float forwardDiffArr[][MAX_POINTS], int n) {
    // First column of forward difference table is the y-values
    for (int i = 0; i < n; i++) {
        forwardDiffArr[i][0] = y[i];
    }

    // Filling the forward difference table
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            forwardDiffArr[i][j] = forwardDiffArr[i + 1][j - 1] - forwardDiffArr[i][j - 1];
        }
    }
}

// Function to perform Newton's Forward Interpolation
float newtonForwardInterpolation(float x[], float y[], int n, float xp) {
    float forwardDiffArr[MAX_POINTS][MAX_POINTS];
    float h, u, result;

    // Step 1: Compute the forward difference table
    calculateForwardDiff(x, y, forwardDiffArr, n);

    // Step 2: Compute the difference between consecutive x-values (h)
    h = x[1] - x[0]; // Assuming equally spaced points

    // Step 3: Calculate u
    u = (xp - x[0]) / h;

    // Step 4: Initialize the result with the first y-value
    result = y[0];
    float term = 1.0;

    // Step 5: Calculate the interpolated value using forward differences
    for (int i = 1; i < n; i++) {
        term *= (u - i + 1) / i; // Compute u * (u-1) * (u-2) ... / i!
        result += term * forwardDiffArr[0][i]; // Add the forward difference term
    }

    return result; // Return the interpolated value
}

int main() {
    // Input data points (x-values and y-values)
    float x[] = {45, 50, 55, 60}; // x-values
    float y[] = {0.7071, 0.7660, 0.8192, 0.8660}; // y-values (sin values in this case)
    int n = 4; // Number of data points
    float xp = 52; // Value of x to interpolate

    // Call the Newton's Forward Interpolation function
    float result = newtonForwardInterpolation(x, y, n, xp);

    // Display the result
    printf("Interpolated value at x = %.2f is %.4f\n", xp, result);

    return 0;
}

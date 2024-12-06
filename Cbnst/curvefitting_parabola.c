#include <stdio.h>
#include <math.h>

int main() {
    float xy[2][20], matrix[3][4], n;
    float sumx = 0, sumy = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0, sumxy = 0, sumx2y = 0;

    printf("Enter the number of data points (n): ");
    scanf("%f", &n);

    printf("Enter values of x and y (pairs):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i + 1);
        scanf("%f", &xy[0][i]);
        printf("y[%d]: ", i + 1);
        scanf("%f", &xy[1][i]);
    }

    // Calculate sums
    for (int i = 0; i < n; i++) {
        float x = xy[0][i];
        float y = xy[1][i];
        sumx += x;
        sumy += y;
        sumx2 += x * x;
        sumx3 += x * x * x;
        sumx4 += x * x * x * x;
        sumxy += x * y;
        sumx2y += x * x * y;
    }

    // Form the augmented matrix
    matrix[0][0] = n;
    matrix[0][1] = sumx;
    matrix[0][2] = sumx2;
    matrix[0][3] = sumy;
    matrix[1][0] = sumx;
    matrix[1][1] = sumx2;
    matrix[1][2] = sumx3;
    matrix[1][3] = sumxy;
    matrix[2][0] = sumx2;
    matrix[2][1] = sumx3;
    matrix[2][2] = sumx4;
    matrix[2][3] = sumx2y;

    // Gaussian elimination
    for (int i = 0; i < 3; i++) {
        // Make the diagonal element 1
        float pivot = matrix[i][i];
        for (int j = 0; j < 4; j++) {
            matrix[i][j] /= pivot;
        }

        // Eliminate all other rows
        for (int k = 0; k < 3; k++) {
            if (k != i) {
                float ratio = matrix[k][i];
                for (int j = 0; j < 4; j++) {
                    matrix[k][j] -= ratio * matrix[i][j];
                }
            }
        }
    }

    // Extract coefficients
    float c = matrix[0][3];
    float b = matrix[1][3];
    float a = matrix[2][3];

    printf("The fitted parabola is: y = %.4fx^2 + %.4fx + %.4f\n", a, b, c);

    return 0;
}

#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100


//calculate the forward difference table
void ForwardDiff(float x[], float y[], float forwardDiffArr[][MAX_POINTS], int n) {
    for (int i = 0; i < n; i++)
        forwardDiffArr[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            forwardDiffArr[i][j] = forwardDiffArr[i + 1][j - 1] - forwardDiffArr[i][j - 1];
        }
    }
}

//Newton's Forward Interpolation
float ForwardInterpo(float x[], float y[], int n, float xp) {
    float forwardDiffArr[MAX_POINTS][MAX_POINTS];
    float h, u, result;

    if (n <= 0 || n > MAX_POINTS) {
        printf("Invalid number of points\n");
        return NAN;
    }

    ForwardDiff(x, y, forwardDiffArr, n);

    h = x[1] - x[0];
    u = (xp - x[0]) / h;

    result = y[0];
    float term = 1.0;

    for (int i = 1; i < n; i++) {
        term *= (u - i + 1) / i;
        result += term * forwardDiffArr[0][i];
    }

    return result;
}

int main() {
    float x[] = { 45, 50, 55, 60 };
    float y[] = {0.7071,0.7660,0.8192,0.8660};
    int xsize = 4;
    float xp = 52;

    float result = ForwardInterpo(x, y, xsize, xp);

    printf("Interpolated value at sin = %.2f is %.4f\n", xp, result);

    return 0;
}

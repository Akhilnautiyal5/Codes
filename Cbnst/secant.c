// x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0))

#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (x * x * x - 4 * x - 9);
}

float secant(float x0, float x1, int *itr)
{
    float x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
    (*itr)++;
    printf("at iteration %d value of x is: %f\n", *itr, x2);
    return x2;
}

int main()
{
    float x0, x1, x2, allerr;
    int itr = 0, maxitr;

    printf("Enter the first two assumptions a, b: \n");
    scanf("%f %f", &x0, &x1);

    printf("Enter allowed error: \n");
    scanf("%f", &allerr);

    printf("Enter allowed max iterration: \n");
    scanf("%d", &maxitr);

    x2 = secant(x0, x1, &itr);

    do
    {
        x0 = x1;
        x1 = x2;
        x2 = secant(x0, x1, &itr);

        if (fabs(x2 - x1) < allerr)
        {
            printf("\nRoot found after %d iterations\n", itr);
            printf("Root = %f\n", x2);
            printf("Function value at root = %f\n", f(x2));
            return 0;
        }

    } while (itr < maxitr);
    printf("Max iteration reached!\n");
    return 0;
}

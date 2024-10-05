#include<stdio.h>
#include<math.h>
float function(float x){
    return  x*log10(x) - 1.2;
}
float derivativeFunction(float x) {
    return  log10(x) + 0.43429;
}
int main() {
    int itr, maxitr;
    float x0, x1, allerr, h; // h = f(x)/f'(x);
    printf("\nEnter x0, allowed error and maximum iterations: ");
    scanf("%f%f%d", &x0, &allerr, &maxitr);
    do {
        h = function(x0) / derivativeFunction(x0);
        x1 = x0 - h;
        printf("At Iteration no. %d, x = %f\n", itr, x1);
        if (fabs(h) < allerr){
            printf("After %d iterations, root = %f\n", itr, x1);
            return 0;
        }
        x0 = x1;
        itr++;
    } while (itr <= maxitr);
    printf(" The required solution does not converge or iterations are insufficient\n");
}

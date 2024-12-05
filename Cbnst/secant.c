#include<stdio.h>
#include<math.h>

#define f(x) ( x*x*x - 5*x + 1)
#define bisect(x1, x2) ((x1+x2)/2)
#define regula(x1, x2) ((x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)))
#define secant(x1, x2) ((x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)))

int main() {
  int maxitr = 20;
  float epsilon = 0.001;
  float x1 = 0, x2 = 1;
  int i = 0;
  float x = secant(x1, x2);
  while (i <= maxitr) {
   x1 = x2;
    x2 = x;
    x = secant(x1, x2);
    if (fabs(x - x2) < epsilon) {
      printf("total iteration = %d, root = %f\n", i+1, x);
      return 0;
    }
    printf("iteration = %d, root = %f\n", i+1, x);
    i++;
  }
}

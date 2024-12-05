#include<stdio.h>
#include<math.h>

#define f(x) ( x*x*x - 2*x - 5)
#define bisect(x1, x2) ((x1+x2)/2)
#define regula(x1, x2) ((x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)))
#define secant(x1, x2) ((x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)))

int main() {
  int maxitr = 20;
  float epsilon = 0.0001;
  float x1 = 2, x2 = 3;
    if (f(x1)*f(x2) >0 ) {
         printf("invalid root range");
        return 0;
    }
  int i = 1;
  float x = bisect(x1, x2);
  while (i <= maxitr) {
    if (f(x)*f(x1) < 0) {
      x2 = x;
    } else {
      x1 = x;
    }
    float x3 = bisect(x1, x2);
    if (fabs(x3 - x) < epsilon) {
      printf("total iteration = %d, root = %f\n", i, x);
      return 0;
    }
    x = x3;
    printf("iteration = %d, root = %f\n", i, x);
    i++;
  }
}

#include<stdio.h>
#include<math.h>

#define f(x) (x*x*x - 3*x - 5)
#define dx(x) (3*x*x - 3)
#define raphson(x) (x - f(x)/dx(x))

int main() {
  int maxitr = 20;
  float x1 = 2, x2 = 3;
  float x = (x1+x2)/2;
  float x3;
  int i = 1;
  while (i <= maxitr) {
    x3 = raphson(x);
    if (fabs(x3-x) < 0.0001) {
      printf("iteration = %d, root = %f\n", i, x);
      return 0;
    }
    printf("iteration = %d, root = %f\n", i, x);
    x = x3;
    i++;
  }
}

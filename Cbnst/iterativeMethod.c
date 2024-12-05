#include<stdio.h>
#include<math.h>

float f(float x) {
  return x*x*x + x*x - 1;
}

float gx(float x) {
  return 1/sqrt(1+x);
}

float dx(float x) {
  return -1/2.0 * pow((1+x),-3/2.0);
}

int main() {
  int maxitr = 20;
  float x1 = 0, x2 = 1;
  float x = (x1+x2)/2;
  if (dx(x) < 1) {
    printf("function is correct\n");
  }else {
    printf("function is not correct\n");
    return 0;
  }
  float x3;
  int i = 1;
  while (i <= maxitr) {
    x3 = gx(x);
    if (fabs(x3-x) < 0.0001) {
      printf("iteration = %d, root = %f\n", i, x);
      return 0;
    }
    printf("iteration = %d, root = %f\n", i, x);
    x = x3;
    i++;
  }
    printf("iteration = %d, root = %f\n", --i, x);
}

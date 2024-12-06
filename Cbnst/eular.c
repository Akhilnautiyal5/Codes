#include <stdio.h>
#define f(x,y) (x+y)
int main()
{
  float x0, y0, x=2, h;
  x0=0,y0=1;
  int n = 4;
  h = (x-x0)/n;
  for (int i=0; i<n; i++) {
    y0 = y0 + h*f(x0, y0);
    x0 = x0+h;
    printf("x = %f, y = %f\n", x0, y0);
  }
    printf("\nx = %f, y = %f\n", x0, y0);
}


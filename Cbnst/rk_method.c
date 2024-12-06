#include <stdio.h>
#define f(x,y) (x+y)
int main()
{
  float x0, y0, x=2, h;
  x0=0,y0=1;
  int n = 4;
  h = (x-x0)/n;
  float k0, k1, k2, k3, k;
  for (int i=0; i<n; i++) {
    k0 = h*f(x0, y0);
    k1 = h*f(x0+h/2, y0+k0/2);
    k2 = h*f(x0+h/2, y0+k1/2);
    k3 = h*f(x0+h, y0+k2);
    
    k = (k0 + 2*k1+2*k2+k3)/6;
    y0 = y0 + k;
    x0 += h;
    printf("\nx = %f, y = %f\n", x0, y0);
  }
    printf("\nx = %f, y = %f\n", x0, y0);
}


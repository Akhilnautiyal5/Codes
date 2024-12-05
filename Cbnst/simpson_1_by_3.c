#include<stdio.h>
#include <math.h>

#define f(x) (1/(1+x*x))

int main() {
  float a=0, b=6;
  int n = 6;
  float h = (b-a)/n;
  float sum = f(a)+f(b);
  int term = 1;
  for (float i=a+h; i<b; i+=h) {
      if (term%2 == 0) {
        sum += 2*f(i);
      }else  {
        sum += 4*f(i);
      }
      term++;
  }
  sum *= h/3;
  printf("%f", sum);
}

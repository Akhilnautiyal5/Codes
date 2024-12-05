#include<stdio.h>

#define f(x) (x*x*x)

int main()
{
    int n=5;
    float a=0,b=1;

    float h=(b-a)/n;
    float sum = f(a) + f(b);
    
    for(float i=a+h; i<b; i=i+h) {
      sum = sum + 2*f(i);
    }
    sum = (h * sum)/2;


    printf("\nValue of The integral  = %f",sum);    
    
}

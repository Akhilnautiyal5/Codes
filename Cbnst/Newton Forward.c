#include<stdio.h>
#include<math.h>


int main() {
  float arr[100][100];
  int n = 5;
  printf("x\n");
  for (int i=0; i<n; i++) {
    scanf("%f", &arr[i][0]);
  }
  printf("y\n");
  for (int i=0; i<n; i++) {
    scanf("%f", &arr[i][1]);
  }
  
  int x;
  printf("enter x for y to be found: ");
  scanf("%d", &x);
  
  //find difference table
  for (int j=2; j<=n; j++) {
    for (int i = 0; i<=n-j; i++) {
      arr[i][j] = arr[i+1][j-1] - arr[i][j-1];
    }
  }
  
  // print difference table
  printf("dif table: \n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<=n-i; j++) {
      printf("%f\t", arr[i][j]);
    }
    printf("\n");
  }
  
  // find u
  int h = arr[1][0] - arr[0][0];
  float u = (x - arr[0][0])/h;
  float y = arr[0][1];
  float u1 = u;
  float fact = 1;
  for (int i=2; i<=n; i++) {
    y = y+ u1*arr[0][i]/fact;
    fact = fact*i;
    u1 = u1*(u-(i-1));
  }
  
  printf("\n\nValue at X = %d is = %f", x, y);
}

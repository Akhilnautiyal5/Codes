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
  float u = (x - arr[n-1][0])/h;
  float y = arr[n-1][1];
  float u1 = u;
  float fact = 1;
  int j=2;
  for (int i=n-2; i>=0; i--) {
    y = y+ (u1*arr[i][j])/fact;
    fact = fact*i;
    u1 = u1*(u+(j-1));
    j++;
  }
  
  printf("\n\nValue at X = %d is = %f", x, y);
}

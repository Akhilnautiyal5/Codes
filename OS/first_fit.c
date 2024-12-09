#include <stdio.h>
#include <math.h>
int main() {
  int process = 4, block = 6;
  int processes[4] = {357, 210, 468, 499};
  int blocks[6] = {200, 400, 600, 500, 300, 250};
  int alloc[4];
  int allocated[4];
  
  for (int i=0; i<block; i++) {
    for (int j=0; j<process; j++) {
      if (processes[j] <= blocks[i] && !allocated[j]) {
        alloc[j] = blocks[i];
        allocated[j] = 1;
        break;
      }
    }
  }
  
  for (int i=0; i<process; i++) {
    if (alloc[i])
    printf("process %d allocated to %d\n", processes[i], alloc[i]);
    else
    printf("process %d not allocated\n", processes[i]);
    
  }
  
}

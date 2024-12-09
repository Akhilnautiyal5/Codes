#include <stdio.h>
#include <math.h>
int main() {
  int process = 4, block = 6;
  int processes[4] = {212 , 417 , 112 , 426};
  int blocks[6] = {100 , 500 , 200 , 300 , 600};
  
  int alloc[4] = {0};
  int block_occupied[6] = {0};
  int blockno[4];
  
  for (int i=0; i<process; i++) {
    int idx = -1;
    int high = 0;
    for (int j=0; j<block; j++) {
      if (block_occupied[j] != 1 && blocks[j] > high && processes[i] <= blocks[j]) {
        high = blocks[j];
        idx = j;
      }
    }
    alloc[i] = blocks[idx];
    blockno[i] = idx;
    block_occupied[idx] = 1;
  }
  
  printf("process\t\tblock_no\tblock_size\n");
  for (int i=0; i<process; i++) {
    printf("%d\t\t%d\t\t%d\n", processes[i], blockno[i], alloc[i]);
  }
  
}

#include <stdio.h>
#include <math.h>
int main() {
  int process = 4, block = 6;
  int processes[4] = {212 , 417 , 112 , 426};
  int blocks[6] = {100 , 500 , 200 , 300 , 600};
  
  int alloc[4] = {0};
  int blockno[4] = {-1};
  int block_occupied[6] = {0};
  int frag[4];
  
  for (int i=0; i<process; i++) {
    int lowest = 999999;
    int idx;
    for (int j=0; j<block; j++) {
      if (block_occupied[j] != 1 && blocks[j] >= processes[i]) {
        int temp = blocks[j] - processes[i];
        if (temp < lowest) {
          lowest = temp;
          idx = j;
        }
      }
      
    }
    alloc[i] = blocks[idx];
    block_occupied[idx] = 1;
    frag[i] = lowest;
    blockno[i] = idx;
  }
  printf("process\t\tblock_no\tblock_size\tfragment\n");
  for (int i=0; i<process; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], blockno[i], alloc[i], frag[i]);
  }
  
}

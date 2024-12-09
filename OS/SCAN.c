#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 8;
    int size = 200;
    int rq[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    
    printf("enter initial head: \n");
    int initial = 53;
    
    int total_head_movement = 0;
    
    //bubble sort
    for (int i=0; i<n; i++) {
      for (int j=0; j<n-i-1; j++) {
        if (rq[j] > rq[j+1]) {
          int temp = rq[j];
          rq[j] = rq[j+1];
          rq[j+1] = temp;
        }
      }
    }
    
    
    int index = 0;
    for (int i=0; i<n; i++) {
      if (initial < rq[i]){
        index = i;
        break;
      }
    }
    
  
    int moved = 0; // towerds low
    int i;
    if (moved == 1) {
      for (i=index; i<n; i++) {
        total_head_movement += abs(rq[i] - initial);
        initial = rq[i];
      }
      total_head_movement += abs(199 - rq[i+1]);
      initial = 199;
      for(i=index-1; i>=0; i--) {
        total_head_movement += abs(rq[i] - initial);
        initial = rq[i];
      }
    } else {
      for(i=index-1; i>=0; i--) {
        total_head_movement += abs(rq[i] - initial);
        initial = rq[i];
      }
      total_head_movement += abs(rq[i+1] - 0);
      initial = 0;
      for (i=index; i<n; i++) {
        total_head_movement += abs(rq[i] - initial);
        initial = rq[i];
      }
    }
    
    printf("total head movement: %d", total_head_movement);
}

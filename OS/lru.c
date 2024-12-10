#include <stdio.h>

int LRU (int time[], int frame) {
  int min = time[0];
  int idx = 0;
  for (int i=1; i<frame; i++) {
    if (time[i] < min) {
      min = time[i];
      idx = i;
    }
  }
  return idx;
}

int main() {
  int n = 12;
  int frame = 3;
  int pages[12] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
  
  int fault = 0;
  int time[3] = {0, 0, 0};
  int frames[3] =  {-1, -1, -1};
  int count = 0;
  printf("Page reference\tmemory state\tpage fault\n");
  for (int i=0; i<n; i++) {
    int found = 0;
    int page = pages[i];
    for(int j=0; j<frame; j++) {
      if (frames[j] == page) {
        found = 1;
        time[j] = count++;
        break;
      }
    }
    if (!found) {
      int front = LRU(time, frame);
      frames[front] = page;
      time[front] = count++;
      fault++;
    }
    
    printf("%d\t\t", page);
    for (int j = 0; j<frame; j++) {
      if (frames[j] != -1) {
        printf("%d ", frames[j]);
      } else {
        printf("_ ");
      }
    }
    printf("\t\t%d\n", fault);
  }
  
  printf("total page fault: %d\n", fault);
  printf("page fault ratio: %f\n", (float)fault/n);
  printf("page hit ratio: %f\n", (float)(n-fault)/n);
}

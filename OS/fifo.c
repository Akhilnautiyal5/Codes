#include <stdio.h>

int main() {
  int n = 12;
  int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3};
  int frame = 3;
  int fault = 0;
  
  int frames[frame];
  for (int i = 0; i < frame; i++) {
        frames[i] = -1;
    }
  int front = 0;
  printf("Page Reference\tMemory State\tPage Fault\n");
  for (int i=0; i<n; i++) {
    int found = 0;
    int page = pages[i];
    for (int j=0; j<frame; j++) {
      if (frames[j] == page) {
        found = 1;
        break;
      }
    }
    if (!found) {
      frames[front] = page;
      front = (front+1)%frame;
      fault++;
    }
    
    printf("%d\t\t", page);
    for (int j=0; j<frame; j++) {
      if (frames[j] != -1)
        printf("%d ", frames[j]);
      else
        printf("_ ");
    }
    printf("\t\t%s\n", found ? "No" : "Yes");
  }
  
  printf("\ntotal page fault: %d", fault);
}

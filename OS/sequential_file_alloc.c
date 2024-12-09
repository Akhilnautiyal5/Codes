#include <stdio.h>
#include <string.h>

struct file {
  char name[20];
  int sblock;
  int bsize;
} f[30];

int main() {
  int n = 3;
  
  for (int i=0; i<n; i++) {
    printf("\nenter file name: ");
    scanf("%s", f[i].name);
    printf("enter starting block: ");
    scanf("%d", &f[i].sblock);
    printf("enter block size: ");
    scanf("%d", &f[i].bsize);
  }
  
  char s[20];
  printf("\nenter file name to be searched: ");
  scanf("%s", s);
  
  int idx = -1;
  for (int i=0; i<n; i++) {
    if (strcmp(s, f[i].name) == 0) {
        idx = i;
        break;
    }
  }
  
  if (idx != -1) {
    printf("\nfile_name\tstart_block\tbolck_size\tblock_occupied\n");
    printf("%s\t\t%d\t\t%d\t\t", f[idx].name, f[idx].sblock, f[idx].bsize);
    for (int i=0; i<f[idx].bsize; i++) {
      printf("%d, ", f[idx].sblock+i);
    }
    
  }else {
    printf("\nfile not found");
  }
  
}

#include <stdio.h>
#include <string.h>

struct file {
  char name[20];
  int bsize;
  int block[100];
} f[30];

int main() {
  int n = 3;
  
  for (int i=0; i<n; i++) {
    printf("\nenter file name: ");
    scanf("%s", f[i].name);
    printf("enter starting block: ");
    scanf("%d", &f[i].bsize);
    printf("enter the blocks: ");
    for (int j=0; j<f[i].bsize; j++) {
      scanf("%d", &f[i].block[j]);
    }
  }
  
  char s[20];
  printf("\nenter file name to be searched: ");
  scanf("%s", s);
  
  int idx = -1;
  for (int i=0; i<n; i++) {
    if (strcmp(s, f[i].name) == 0){
     idx = i;
     break;
    }
  }
  
  if (idx != -1) {
    printf("\nfile_name\tbolck_size\tblock_occupied\n");
    printf("%s\t\t%d\t\t", f[idx].name, f[idx].bsize);
    for (int i=0; i<f[idx].bsize; i++) {
      printf("%d  ", f[idx].block[i]);
    }
    
  }else {
    printf("file not found");
  }
  
}

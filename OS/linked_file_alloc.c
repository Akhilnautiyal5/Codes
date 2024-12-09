#include <stdio.h>
#include <string.h>

struct file {
  char name[20];
  int bsize;
  struct node{
    int data;
    struct node *next;
  } *sb;
} f[30];

int main() {
  int n = 3;
  struct node *temp;
  
  for (int i=0; i<n; i++) {
    printf("\nenter file name: ");
    scanf("%s", f[i].name);
    printf("enter starting block: ");
    scanf("%d", &f[i].bsize);
    printf("enter the blocks: ");
    f[i].sb = (struct node* )malloc(sizeof(struct node));
    temp = f[i].sb;
    for (int j=0; j<f[i].bsize; j++) {
      struct node *new =  (struct node* )malloc(sizeof(struct node));
      
      scanf("%d", &new->data);
      temp->next = new;
      temp = temp->next;
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
    temp = f[idx].sb->next;
    for (int i=0; i<f[idx].bsize; i++) {
      printf("%d->", temp->data);
      temp = temp->next;
    }
    
  }else {
    printf("file not found");
  }
  
}

// exec systam call used to replace current process with new process

// ececv command 

#include <stdio.h>
#include <unistd.h>

int main() {
  char *temp[3];
  temp[0] = "ls";
  temp[1] = "-l";
  temp[2] = NULL;
  
  execv("/bin/ls", temp);
  printf("this won't print if execv run");
}


// ececlp

#include <stdio.h>
#include <unistd.h>

int main() {
  execlp("/bin/ls", "ls", NULL);
  printf("this won't print if execv run");
}

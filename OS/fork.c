#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t q = fork();
  if(q < 0) {
    printf("fork Error ");
  }
  if (q == 0) {
    printf("child: %d, patient: %d\n", getpid(), getppid());
  }
  else {
    wait(NULL);
    printf("parent: %d, child: %d\n", getpid(), q);
  }
  printf("common\n");
}


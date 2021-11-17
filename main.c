#include "forka.h"

int main() {

  printf("Parent started PID: %d\n", getpid());
  printf("First Fork.\n");

  int one = fork();
  // parent fork

  if (one) {
    printf("Second Fork.\n");
    int two = fork();


    if (two) { // if completed
      int status;
      int waited = wait(&status);
      printf("Completed Child PID: %d\tAsleep for %d seconds\n", waited, WEXITSTATUS(status));
      printf("Parent Completed \n");
      return 0;
    }

    else {
      printf("Other Child PID: %d\n", getpid());
      int r = rand() % 4;
      sleep(r);
      printf("Slept for %d seconds\n", r);
      return r;
    }
  }
  else {
    printf("PID: %d\n", getpid());
    int r = (rand() % 4);
    sleep(r);
    printf("Finished sleeping\n");
    return r;
  }
}

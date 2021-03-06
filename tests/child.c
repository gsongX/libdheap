/**
 * Test file
 * Spawns a child and attempts a double free
 */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int pid;
  int wstatus;
  char *p1, *p2;

  pid = fork();
  if (pid == 0) {
    // Child
    p1 = malloc(20);
    p2 = malloc(20);
    free(p1);
    free(p2);
    free(p1);
    return 0;
  }
  // Parent
  waitpid(pid, &wstatus, 0);
  return 0;
}

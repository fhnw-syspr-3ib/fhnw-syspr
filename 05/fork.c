#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t res = fork();
    if (res == 0) { // child
        printf("child %d of parent %d\n", getpid(), getppid());
        exit(0);
    }
    // parent
    wait(NULL); // blocking
    printf("parent %d of child %d\n", getpid(), res);
    return 0;
}

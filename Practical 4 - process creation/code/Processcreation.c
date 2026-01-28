#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    pid_t pid;

    printf("parent process started\n");
    printf("parent PID: %d\n", getpid());

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        printf("\nChild process\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        execl("/bin/ls", "ls", "-l", NULL);

        // Only runs if execl fails
        perror("execl failed");
        exit(1);
    }
    else {
        wait(NULL);
        printf("\nChild process completed\n");
        printf("parent process exiting\n");
    }

    return 0;
}

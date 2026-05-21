#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int status;
    if (fork() == 0) {
        printf("Child Process\n");
        return 5;
    } else {
        wait(&status);
        if (WIFEXITED(status))
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        else
            printf("Child exited abnormally\n");
    }
    return 0;
}
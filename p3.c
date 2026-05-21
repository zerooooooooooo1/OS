#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Clock ticks: %ld\n", sysconf(_SC_CLK_TCK));
    printf("Max child processes: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Max path length: %ld\n", pathconf("/", _PC_PATH_MAX));
    printf("Max filename length: %ld\n", pathconf("/", _PC_NAME_MAX));
    printf("Max open files: %ld\n", sysconf(_SC_OPEN_MAX));
    return 0;
}
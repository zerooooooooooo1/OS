#include <stdio.h>

extern char **environ;

int main() {
    char **env = environ;
    while (*env)
        printf("%s\n", *env++);
    return 0;
}


/*gedit prog2.c       # paste the code
gcc prog2.c         # compile
./a.out             # run*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int pid = fork();
    if (pid > 0) {
        printf("Parent Process\n");
    } else {
        printf("Child Process\n");
        char ch;
        int in = open(argv[1], O_RDONLY);
        int out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        while (read(in, &ch, 1) > 0)
            write(out, &ch, 1);
        close(in); close(out);
    }
    return 0;
}

/*./a.out source.txt dest.txt
# create source.txt first: gedit source.txt*/

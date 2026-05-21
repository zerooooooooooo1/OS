// writer
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char msg[] = "Hello FIFO";
    mkfifo("myfifo", 0666);
    int fd = open("myfifo", O_WRONLY);
    write(fd, msg, sizeof(msg));
    close(fd);
    return 0;
}

//reader
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char msg[50];
    int fd = open("myfifo", O_RDONLY);
    read(fd, msg, sizeof(msg));
    printf("Message: %s\n", msg);
    close(fd);
    return 0;
}

/*# Terminal 1:
gcc writer.c -o writer
./writer &
# Terminal 2:
gcc reader.c -o reader
./reader*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("test.txt", O_RDWR);
    struct flock lock;

    lock.l_type   = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start  = 0;
    lock.l_len    = 100;

    fcntl(fd, F_SETLK, &lock);
    printf("File locked\n");
    sleep(5);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("File unlocked\n");

    close(fd);
    return 0;
}



/*gedit test.txt   # type anything, save it
gcc prog10.c
./a.out*/

#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat s;
    stat("test.txt", &s);
    printf("File Size: %ld\n", s.st_size);
    printf("Inode Number: %ld\n", s.st_ino);
    printf("Number of Links: %ld\n", s.st_nlink);
    return 0;
}


/*gedit test.txt   # type anything, save it
gcc prog10.c
./a.out*/

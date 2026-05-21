//cat
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");
    char ch;
    while((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
    return 0;
}

/*./a.out test.txt*/

//ls
#include <stdio.h>
#include <dirent.h>

int main() {
    struct dirent *d;
    DIR *dir = opendir(".");
    while((d = readdir(dir)) != NULL)
        printf("%s\n", d->d_name);
    closedir(dir);
    return 0;
}
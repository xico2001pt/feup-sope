#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void sequential(int fd){
    char c;
    lseek(fd, 0, SEEK_SET); // we have written
                            // to the file, get back to the beggining!
    for(;;){
        read(fd, &c, 1);
        if (c == 0){
            break;
        }
        else printf("%c ",c);
    }
}

void random(int fd){
    char c;
    int location = 0;
    lseek(fd, 0, SEEK_SET);
    for(;;){
        if (read(fd, &c, 1) == 0) break;
        if (c == 0){
            break;
        }
        else printf("%c ",c);
        lseek(fd, 1, SEEK_CUR); // advance 2
    }
}

int main(){
    int fd = open("mf", O_CREAT | O_RDWR);
    char buf[50];
    snprintf(buf, 50, "This is a small text\n");
    printf("%d bytes written\n", write(fd, buf, strlen(buf) + 1));
    sequential(fd);
    random(fd);
    close(fd);
}
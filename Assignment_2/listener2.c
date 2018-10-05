#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFFER_SIZE 80
int main(){
    int fd2;
    char * myfifo = "/tmp/myfifo2";
    mkfifo(myfifo, 0666);
    char buffer_in[BUFFER_SIZE],buffer_out[BUFFER_SIZE],dummy;
    while (1){
        fd2 = open(myfifo,O_RDONLY);
        read(fd2, buffer_in, BUFFER_SIZE);
        printf("Message: %s\n", buffer_in);
        close(fd2);
    }
    return 0;
}

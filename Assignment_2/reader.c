#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFFER_SIZE 80
int main(){
    int fd1;
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    char buffer_in[BUFFER_SIZE],buffer_out[BUFFER_SIZE],dummy;
    while (1){
    	fd1 = open(myfifo,O_RDONLY);
    	read(fd1, buffer_in, BUFFER_SIZE);
    	printf("Caller: %s\n", buffer_in);
    	close(fd1);
    }
    return 0;
}

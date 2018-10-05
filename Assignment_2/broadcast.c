#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFFER_SIZE 80
int main(){
    int fd1,fd2;
    char * myfifo1 = "/tmp/myfifo1";
    char * myfifo2 = "/tmp/myfifo2";
    mkfifo(myfifo1, 0666);
    mkfifo(myfifo2, 0666);
    char buffer_in[BUFFER_SIZE], buffer_out[BUFFER_SIZE],dummy;
    while (1){
        fd1 = open(myfifo1, O_WRONLY);
        fd2 = open(myfifo2, O_WRONLY);
        printf("Enter your message: ");
        scanf("%[^\n]s",buffer_out);
        scanf("%c",&dummy);        
        write(fd1, buffer_out, strlen(buffer_out)+1);
        write(fd2, buffer_out, strlen(buffer_out)+1);
        close(fd1);
        close(fd2);
       
    }
    return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>


void perror (const char *str);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    const char *string_to_write = argv[2];

    // Open syslog
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    // Write to file
    int fd;
    size_t nr;

    fd = open(filename, O_WRONLY | O_TRUNC);
    
    if(fd == -1){
        perror("open");
    }else{
        nr = write(fd, string_to_write, strlen(string_to_write));
        if (nr == -1)
        {
            perror("write");
        } 

        if(close(fd) == -1){
            perror("close");
        }
    }

    return EXIT_SUCCESS;
}

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd = open("example.txt", O_RDONLY);  // Open file in read-only mode
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[100]; 
    ssize_t bytesRead ;

    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0';
        printf("%s", buffer);
    }

    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    close(fd);  // Close the file descriptor
    return 0;
}

/* Demo to show the write() system call */

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <io.h>
#define write _write
#else
#include <unistd.h>
#endif

int main(void){
    int msg_len = 0;
    char buf[100];

    strncpy(buf, "This is writing to screen using write() system call instead of printf Library call\n", 99);
    buf[99] = '\0';
    msg_len = (int)strlen(buf);

    int ret = write(1, buf, msg_len);
    if (ret < 0) {
        perror("write");
        return 1;
    }

    return 0;
}
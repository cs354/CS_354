#include "server_thread.h"
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include <signal.h>

void medium(int cfd);

void *run(int cfd) {
    printf("Starting session %d\n", cfd);
    medium(cfd);
    printf("Ending session %d\n", cfd);
    shutdown(cfd, SHUT_RDWR);
    return NULL;
}

void medium(int cfd) {

    char cnry[] = "cnry!~!";
    char buf[32];
    printf("buf : %p\n",&buf);
    int r = read(cfd, buf, 320);
    if (strcmp(cnry,"cnry!~!")) {
        dprintf(cfd,"-=-=-= Stack smashing detected =-=-=- \n This incident will be reported\n");
        exit(1);
    }
    if (r < 1)
        exit(1);
    printf("Returning;");
}

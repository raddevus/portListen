#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    int server = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(port)
    };

    bind(server, (struct sockaddr*)&addr, sizeof(addr));
    listen(server, 1);

    int client = accept(server, NULL, NULL);

    char buf[1024];
    ssize_t n;
    while ((n = read(client, buf, sizeof(buf))) > 0) {
        fwrite(buf, 1, n, stdout);
        fflush(stdout);
    }

    close(client);
    close(server);
    return 0;
}


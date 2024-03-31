/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** teams server
*/

#ifndef TEAMS_SERVER_H_
    #define TEAMS_SERVER_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <sys/select.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/wait.h>
    #include <dirent.h>

typedef struct message {
    char *xxx;
} msg_t;

typedef struct check {
    bool *user;
    bool *pass;
    bool *auth;
} check_t;

typedef struct server_teams {
    int fd;
    int client_fd;
    struct sockaddr_in addr;
    struct sockaddr_in client_addr;
    fd_set readfds;
    int *client_fds;
    char *buffer;
    char *path;
    int port;
    char **client_msg;
    char *connect_msg;
    char *tok;
    const char **msg;
    int data_socket;
    int data_port;
    struct sockaddr_in data_addr;
    char *file_buff;
    char *pwd;
    check_t check;
    int status;
} teams_s;

int create_socket(void);

struct sockaddr_in configure_socket(int port);

#endif /* !TEAMS_SERVER_H_ */

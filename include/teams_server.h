/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** teams server
*/

#ifndef TEAMS_SERVER_H_
    #define TEAMS_SERVER_H_

    #include "my_teams.h"
    #include "../libs/myteams/logging_server.h"

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
} steams_t;

int create_socket(void);

struct sockaddr_in configure_socket(int port);

int teams_server(char *port);

int bind_socket(steams_t *server);

int listen_on_socket(int fd);

int error_handling(steams_t *server);

void set_clients(steams_t *server);

int *check_disconnection(steams_t *server, int i);

void to_exit(steams_t *server);

void free_arr(steams_t *server);

void infinite_loop(steams_t *server);

#endif /* !TEAMS_SERVER_H_ */

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** teams server
*/

#ifndef TEAMS_SERVER_H_
    #define TEAMS_SERVER_H_

    #include "my_teams.h"
    #include "../libs/myteams/logging_client.h"

typedef struct message {
    char *xxx;
} msg_t;

typedef struct check {
    bool *user;
    bool *pass;
    bool *auth;
} check_t;

typedef struct client_teams {
    int fd;
    int ip;
    char *id;
    struct sockaddr_in addr;
    struct sockaddr_in client_addr;
    fd_set readfds;
    char *name;
    int *client_fds;
    char *buffer;
    char *in_buffer;
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
    char *welcome;
} cteams_t;

static const char *log[] = {
    "LOGIN",
    "LOGOUT",
};

static const char *create[] = {
    "TEAM-CREATED",
    "CHANNEL-CREATED",
    "THREAD-CREATED",
    "REPLY-CREATED",
};

static const char *user_msg[] = {
    "USERS",
    "USER",
    "RECEIVED",
};

int create_socket(void);

struct sockaddr_in configure_socket(int ip, int port);

void to_exit(cteams_t *client);

int infinite_loop(cteams_t *client);

void check_messages(cteams_t *client);

bool check_log(char *command);

bool check_create(char *command);

bool check_user_msg(char *command);

#endif /* !TEAMS_SERVER_H_ */

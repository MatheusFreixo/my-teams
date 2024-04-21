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
    bool status;
} cteams_t;

static const char *log[] = {
    "LOGIN",
    "LOGOUT",
    NULL,
};

static const char *create[] = {
    "TEAM-CREATED",
    "CHANNEL-CREATED",
    "THREAD-CREATED",
    "REPLY-CREATED",
    NULL,
};

static const char *user_msg[] = {
    "USERS",
    "USER",
    "RECEIVED",
    "MESSAGES",
    NULL,
};

static const char *subs_msg[] = {
    "SUBSCRIBED",
    "UNSUBSCRIBED",
    "SUBSCRIBED-TEAMS",
    "SUBSCRIBED-USERS",
    NULL,
};

int create_socket(void);

struct sockaddr_in configure_socket(int ip, int port);

void to_exit(cteams_t *client);

int infinite_loop(cteams_t *client);

void check_messages(cteams_t *client);

bool check_log(char *command);

bool check_create(char *command);

bool check_user_msg(char *command);

time_t parse_time(char *time);

char *parse_message(char *message);

void manage_create_message(cteams_t *client, char **msg);

void manage_list_message(char **msg);

bool check_subs_msg(char *command);

void manage_subs_message(char **command);

void each_user_details(char **msg);

#endif /* !TEAMS_SERVER_H_ */

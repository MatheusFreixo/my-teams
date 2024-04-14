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

typedef struct list {
    const char *id;
    char *name;
    LIST_ENTRY(list) entry;
} list_t;

typedef struct replies {
    const char *id;
    char *name;
    char *message;
    LIST_ENTRY(list) entry;
} replies_t;

typedef struct threads {
    const char *id;
    char *name;
    replies_t *replies;
    LIST_ENTRY(threads) entry;
} threads_t;

typedef struct channels {
    const char *id;
    char *name;
    threads_t *threads;
    LIST_ENTRY(channels) entry;
} channels_t;

typedef struct teams {
    const char *id;
    char *name;
    channels_t *channels;
    LIST_ENTRY(teams) entry;
} temas_t;

typedef struct users {
    const char *id;
    char *name;
    bool status;
    int fd;
    list_t *teams;
    list_t *channels;
    list_t *threads;
    list_t *replies;
    LIST_ENTRY(users) entry;
} users_t;

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
    LIST_HEAD(UserHead, users) users;
    LIST_HEAD(ChannelHead, list) channels;
    LIST_HEAD(ThreadHead, list) threads;
    LIST_HEAD(ReplyHead, list) replies;
    struct users *last_user;
    struct list *last_channel;
    struct list *last_thread;
    struct list *last_reply;
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

static const char *log[] = {
    "/login",
    "/logout",
};

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

const char *gen_uuid_parsed(void);

const char *get_user_id(steams_t *server, char *name);

void user_log_in(steams_t *server, char *name, int client_fd);

void user_log_out(steams_t *server, int client_fd);

int check_command(steams_t *server, char *command, int client_fd);

bool check_client(steams_t *server, int client_fd);

char *get_user_name(steams_t *server, int client_fd);

bool check_log(char *command);

void manage_log_command(steams_t *server, char *cmd, char *name, int client_fd);

#endif /* !TEAMS_SERVER_H_ */

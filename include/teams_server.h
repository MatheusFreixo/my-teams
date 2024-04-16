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

typedef enum create_type {
    TEAM,
    CHANNEL,
    THREAD,
    REPLY
} create_t;

typedef struct list {
    const char *id;
    char *name;
    LIST_ENTRY(list) entry;
} list_t;

typedef struct replies {
    const char *id;
    char *message;
    const char *channel_id;
    const char *thread_id;
    const char *team_id;
    const char *user_id;
    time_t timestamp;
    LIST_ENTRY(replies) entry;
} replies_t;

typedef struct threads {
    const char *id;
    char *title;
    char *message;
    time_t timestamp;
    const char *channel_id;
    const char *team_id;
    const char *user_id;
    // LIST_HEAD(ReplyHead, reply) replies;
    LIST_ENTRY(threads) entry;
} threads_t;

typedef struct channels {
    const char *id;
    char *name;
    char *description;
    const char *team_id;
    // LIST_HEAD(ThreadHead, threads) threads;
    LIST_ENTRY(channels) entry;
} channels_t;

typedef struct teams {
    const char *id;
    char *name;
    char *description;
    // LIST_HEAD(ChannelHead, channels) channels;
    LIST_ENTRY(teams) entry;
} teams_t;

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
    LIST_HEAD(TeamsHead, teams) teams;
    LIST_HEAD(ChannelHead, channels) channels;
    LIST_HEAD(ThreadHead, threads) threads;
    LIST_HEAD(ReplyHead, replies) replies;
    struct users *last_user;
    struct teams *last_team;
    struct channels *last_channel;
    struct threads *last_thread;
    struct replies *last_reply;
    create_t create_type;
    bool context;
    char *team_id;
    char *channel_id;
    char *thread_id;
    int nb_users;
    int nb_teams;
    int nb_channels;
    int nb_threads;
    int nb_replies;
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
    NULL
};

static const char *context_cmd[] = {
    "/create",
    "/list",
    "/info",
    "/use",
    NULL
};

static const char *user_cmd[] = {
    "/users",
    "/user",
    "/send",
    "/messages",
    NULL,
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

const char *get_user_id_by_name(steams_t *server, char *name);

const char *get_user_id_by_fd(steams_t *server, int fd);

void user_log_in(steams_t *server, char *name, int client_fd);

void user_log_out(steams_t *server, int client_fd);

int check_command(steams_t *server, char *command, int client_fd);

bool check_client(steams_t *server, int client_fd);

char *get_user_name(steams_t *server, int client_fd);

bool check_log(char *command);

void manage_log_command(
    steams_t *server,
    char *cmd,
    char *name,
    int client_fd);

bool check_team(steams_t *server, char *name);

bool check_thread(steams_t *server, char *thread_id);

bool check_channel(steams_t *server, char *channel_id);

void manage_create_command(steams_t *server, char **command, int client_fd);

void add_team_to_list(steams_t *server, char *name, char *desc, int client_fd);

void manage_context(steams_t *server, char **command, int client_fd);

void add_channel_to_list(
    steams_t *server,
    char *name,
    char *desc,
    int client_fd);

void add_thread_to_list(
    steams_t *server,
    char *title,
    char *message,
    int client_fd);

void add_reply_to_list(steams_t *server, char *message, int client_fd);

bool check_context_cmd(steams_t *server, char *command, int client_fd);

void context_based(steams_t *server, char **command, int client_fd);

bool check_user_cmd(steams_t *server, char *command, int client_fd);

char *concat_malloc(char *str1, const char *id, char *name, bool status);

char *get_all_users(steams_t *server);

char *get_specific_user(steams_t *server, char *id);

void user_related(steams_t *server, char **command, int client_fd);

#endif /* !TEAMS_SERVER_H_ */

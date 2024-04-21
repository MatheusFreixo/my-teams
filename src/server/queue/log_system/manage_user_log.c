/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_queue
*/

#include "../../../../include/teams_server.h"

int change_user_status(
    steams_t *server,
    char *name,
    int client_fd,
    bool expected_status)
{
    users_t *tmp = NULL;

    LIST_FOREACH(tmp, &server->users, entry){
        if (strcmp(tmp->name, name) == 0){
            if (tmp->status == expected_status){
                tmp->status = !tmp->status;
            }
            return (1);
        }
    }
    return (0);
}

void add_user_to_list(steams_t *server, char *name, int client_fd)
{
    users_t *user = malloc(sizeof(users_t));

    user->name = strdup(name);
    user->id = gen_uuid_parsed();
    server_event_user_created(user->id, user->name);
    server_event_user_logged_in(user->id);
    user->status = true;
    user->fd = client_fd;
    user->last_msg = malloc(sizeof(msg_t));
    server->nb_users++;
    if (LIST_EMPTY(&server->users)){
        LIST_INSERT_HEAD(&server->users, user, entry);
    } else {
        LIST_INSERT_AFTER(server->last_user, user, entry);
    }
    server->last_user = user;
}

void user_log_in(steams_t *server, char *name, int client_fd)
{
    char *msg;
    char *id;
    char *user_name = parse_message(name);

    if (change_user_status(server, user_name, client_fd, false) == 0){
        add_user_to_list(server, user_name, client_fd);
    } else {
        server_event_user_logged_in(get_user_id_by_name(server, user_name));
        set_user_fd(server, user_name, client_fd);
    }
    msg = malloc(sizeof(char) * MAX_NAME_LENGTH + 44);
    id = strdup(get_user_id_by_name(server, user_name));
    strcpy(msg, "LOGIN\n");
    strcat(msg, id);
    strcat(msg, "\n");
    strcat(msg, user_name);
    strcat(msg, "\n");
    write(client_fd, msg, strlen(msg));
    store_users(server);
    free(msg);
}

void user_log_out(steams_t *server, int client_fd)
{
    char *name = get_user_name(server, client_fd);
    char *fd = malloc(sizeof(char) * 5);
    char *id = strdup(get_user_id_by_name(server, name));
    char *msg = malloc(sizeof(char) * strlen(id) + strlen(name) + 13);

    sprintf(fd, "%d", client_fd);
    strcpy(msg, "LOGOUT\n");
    strcat(msg, id);
    strcat(msg, "\n");
    strcat(msg, name);
    strcat(msg, "\n");
    strcat(msg, fd);
    strcat(msg, "\n");
    if (change_user_status(server, name, client_fd, true) == 1){
        server_event_user_logged_out(get_user_id_by_name(server, name));
        write(client_fd, msg, strlen(msg));
    }
    store_users(server);
}

void manage_log_command(steams_t *server, char *cmd, char *name, int client_fd)
{
    if (strcmp(cmd, "/login") == 0 && name != NULL && strcmp(name, "") != 0){
        user_log_in(server, name, client_fd);
    } else if (strcmp(cmd, "/logout") == 0 && check_client(server, client_fd)){
        user_log_out(server, client_fd);
    }
}

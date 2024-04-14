/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_queue
*/

#include "../../../include/teams_server.h"

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
    user->status = true;
    user->fd = client_fd;
    user->id = gen_uuid_parsed();
    if (LIST_EMPTY(&server->users)){
        LIST_INSERT_HEAD(&server->users, user, entry);
    } else {
        LIST_INSERT_AFTER(server->last_user, user, entry);
    }
    server_event_user_created(user->id, user->name);
    server->last_user = user;
}

void user_log_in(steams_t *server, char *name, int client_fd)
{
    char *msg;
    char *id;

    if (change_user_status(server, name, client_fd, false) == 0){
        add_user_to_list(server, name, client_fd);
    } else {
        server_event_user_logged_in(get_user_id(server, name));
    }
    msg = malloc(sizeof(char) * 43);
    id = strdup(get_user_id(server, name));
    strcpy(msg, "LOGIN ");
    strcat(msg, id);
    write(client_fd, msg, 42);
    free(msg);
    free(id);
}

void user_log_out(steams_t *server, int client_fd)
{
    char *name = get_user_name(server, client_fd);
    char *msg = "LOGOUT";

    if (change_user_status(server, name, client_fd, true) == 1){
        server_event_user_logged_out(get_user_id(server, name));
        write(client_fd, "LOGOUT", 6);
    }
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** setters
*/

#include "./../../../include/teams_server.h"

void send_message_to_all_users(steams_t *server, char *msg)
{
    users_t *user = NULL;

    LIST_FOREACH(user, &server->users, entry) {
        if (user->status){
            write(user->fd, msg, strlen(msg));
        }
    }
}

msg_t *get_last_message(msg_t *message)
{
    msg_t *tmp = message;

    while (tmp->entry.le_next != NULL){
        tmp = tmp->entry.le_next;
    }
    return (tmp);
}

void add_message_to_list(steams_t *server, msg_t *message)
{
    msg_t *msg;

    if (LIST_EMPTY(&server->msg)){
        LIST_INSERT_HEAD(&server->msg, message, entry);
        server->last_msg = message;
    } else {
        LIST_INSERT_AFTER(server->last_msg, message, entry);
        server->last_msg = message;
    }
}

void set_message(steams_t *server, msg_t *message)
{
    if (LIST_EMPTY(&server->msg)){
        LIST_INSERT_HEAD(&server->msg, message, entry);
    } else {
        LIST_INSERT_AFTER(server->last_msg, message, entry);
    }
    server->last_msg = message;
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** setters
*/

#include "./../../../include/teams_server.h"

void add_message_to_list(users_t *user, msg_t *message)
{
    user->last_msg = message;
    if (LIST_EMPTY(&user->msg)){
        LIST_INSERT_HEAD(&user->msg, message, entry);
    } else {
        LIST_INSERT_AFTER(user->last_msg, message, entry);
    }
}

void set_message(steams_t *server, msg_t *message)
{
    users_t *tmp;

    LIST_FOREACH(tmp, &server->users, entry){
        if (strcmp(tmp->id, message->receiver_id) == 0){
            add_message_to_list(tmp, message);
        }
        if (strcmp(tmp->id, message->sender_id) == 0){
            add_message_to_list(tmp, message);
        }
    }
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** getters
*/

#include "../../../../include/teams_server.h"

char *get_messages_by_id(steams_t *server, const char *id)
{
    users_t *tmp = NULL;
    msg_t *msg = NULL;
    char *message = "MESSAGES";

    LIST_FOREACH(tmp, &server->users, entry){
        if (strcmp(tmp->id, id) == 0){
            LIST_FOREACH(msg, &tmp->msg, entry){
                message = concat_message_info(
                    message, msg->sender_id, msg->timestamp, msg->body);
            }
            return (message);
        }
    }
    return (NULL);
}

int get_user_fd_by_id(steams_t *server, const char *id)
{
    users_t *tmp = NULL;

    LIST_FOREACH(tmp, &server->users, entry){
        if (strcmp(tmp->id, id) == 0){
            return (tmp->fd);
        }
    }
    return (0);
}

char *get_status(bool status)
{
    if (status == true)
        return ("1");
    return ("0");
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** getters
*/

#include "../../../../include/teams_server.h"

bool check_sender_receiver_id(
    msg_t *tmp, const char *sender, const char *receiver)
{
        if (strcmp(tmp->sender_id, sender) == 0
        && strcmp(tmp->receiver_id, receiver) == 0){
            return (true);
        }
    return (false);
}

char *get_messages_by_id(
    steams_t *server, const char *id, const char *other_id)
{
    msg_t *tmp = NULL;
    char *message = "MESSAGES\n";

    LIST_FOREACH(tmp, &server->msg, entry){
        if (check_sender_receiver_id(tmp, id, other_id)
        || check_sender_receiver_id(tmp, other_id, id)){
            message = concat_message_info(
                message, tmp->sender_id,
                tmp->timestamp, parse_message(tmp->body));
        }
    }
    if (strlen(message) == 9)
        return (NULL);
    return (message);
}

int get_user_fd_by_id(steams_t *server, const char *id)
{
    users_t *tmp = NULL;
    int i = 0;

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

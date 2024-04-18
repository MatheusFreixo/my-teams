/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_messages
*/

#include "../../../include/teams_server.h"

msg_t *store_message(steams_t *server, int fd, char *receiver_id, char *body)
{
    msg_t *msg = malloc(sizeof(msg_t));
    time_t t = time(NULL);

    msg->receiver_id = strdup(receiver_id);
    msg->sender_id = get_user_id_by_fd(server, fd);
    msg->timestamp = t;
    msg->body = strdup(body);
    return (msg);
}

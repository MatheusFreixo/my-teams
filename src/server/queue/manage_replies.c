/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_teams
*/

#include "../../../include/teams_server.h"

char *gen_message_reply(char *type, replies_t *reply)
{
    int size = strlen(type) + strlen(reply->id) + strlen(reply->user_id) + strlen(reply->message) + 4;
    char *msg;
    char *time;

    sprintf(time, "%ld", reply->timestamp);
    size = size + strlen(time);
    msg = malloc(sizeof(char) * size + 1);
    strcpy(msg, type);
    strcat(msg, "\n");
    strcat(msg, reply->id);
    strcat(msg, "\n");
    strcat(msg, reply->user_id);
    strcat(msg, "\n");
    strcat(msg, time);
    strcat(msg, "\n");
    strcat(msg, reply->message);
    return (msg);
}

struct replies *init_reply(steams_t *server, char *message, int client_fd)
{
    replies_t *tmp = malloc(sizeof(teams_t));

    tmp->id = gen_uuid_parsed();
    tmp->message = message;
    tmp->channel_id = server->channel_id;
    tmp->thread_id = server->thread_id;
    tmp->team_id = server->team_id;
    tmp->user_id = get_user_id_by_fd(server, client_fd);
    tmp->timestamp = time(NULL);
    return (tmp);
}

void add_reply_to_list(steams_t *server, char *message, int client_fd)
{
    replies_t *reply = NULL;
    char *msg = NULL;

    if (strcmp(message, "") == 0)
        return;
    reply = init_reply(server, message, client_fd);
    if (LIST_EMPTY(&server->replies))
        LIST_INSERT_HEAD(&server->replies, reply, entry);
    else
        LIST_INSERT_AFTER(server->last_reply, reply, entry);
    msg = gen_message_reply("REPLY-CREATED", reply);
    server_event_reply_created(reply->thread_id, reply->id, reply->message);
    write(client_fd, msg, strlen(msg));
    server->last_reply = reply;
    free(msg);
}

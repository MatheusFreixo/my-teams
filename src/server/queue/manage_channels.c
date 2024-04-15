/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_teams
*/

#include "../../../include/teams_server.h"
#include <string.h>

char *gen_message_channels(char *type, channels_t *channel)
{
    int size = strlen(type) + strlen(channel->name) +
        strlen(channel->description) + strlen(channel->id) + 3;
    char *msg = malloc(sizeof(char) * size + 1);

    strcpy(msg, type);
    strcat(msg, "\n");
    strcat(msg, channel->id);
    strcat(msg, "\n");
    strcat(msg, channel->name);
    strcat(msg, "\n");
    strcat(msg, channel->description);
    return (msg);
}

void add_channel_to_list(
    steams_t *server, char *name,
    char *desc, int client_fd)
{
    channels_t *channel = NULL;
    char *msg = NULL;

    if (check_channel(server, name) || strcmp(name, "") == 0)
        return;
    channel = malloc(sizeof(teams_t));
    channel->id = gen_uuid_parsed();
    channel->name = name;
    channel->description = desc;
    channel->threads = NULL;
    channel->team_id = server->team_id;
    if (LIST_EMPTY(&server->channels))
        LIST_INSERT_HEAD(&server->channels, channel, entry);
    else
        LIST_INSERT_AFTER(server->last_channel, channel, entry);
    msg = gen_message_channels("CHANNEL-CREATED", channel);
    server_event_channel_created(channel->team_id, channel->id, name);
    write(client_fd, msg, strlen(msg));
    server->last_channel = channel;
    free(msg);
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** list_getters
*/

#include "../../../../include/teams_server.h"

bool check_id(
    steams_t *server, const char *team_id,
    const char *channel_id, const char *thread_id)
{
    if (strcmp(team_id, server->team_id) == 0
    && strcmp(channel_id, server->channel_id) == 0
    && strcmp(thread_id, server->thread_id) == 0){
        return (true);
    }
    return (false);
}

char *get_replies_info(steams_t *server)
{
    replies_t *tmp = NULL;
    char *replies = "LIST-REPLIES\n";

    LIST_FOREACH(tmp, &server->replies, entry){
        if (check_id(server, tmp->team_id, tmp->channel_id, tmp->thread_id)){
            replies = concat_reply(replies, tmp);
        }
    }
    if (strlen(replies) == 14)
        return (NULL);
    return (replies);
}

char *get_threads_info(steams_t *server)
{
    threads_t *tmp = NULL;
    char *threads = "LIST-THREADS\n";

    LIST_FOREACH(tmp, &server->threads, entry){
        if (strcmp(tmp->team_id, server->team_id) == 0
        && strcmp(tmp->channel_id, server->channel_id) == 0){
            threads = concat_thread(threads, tmp);
        }
    }
    if (strlen(threads) == 13)
        return (NULL);
    return (threads);
}

char *get_channels_info(steams_t *server)
{
    channels_t *tmp = NULL;
    char *channels = "LIST-CHANNELS\n";

    LIST_FOREACH(tmp, &server->channels, entry){
        if (strcmp(tmp->team_id, server->team_id) == 0)
        channels = concat_team_channel(
            channels, tmp->id, tmp->name, tmp->description);
    }
    if (strlen(channels) == 14)
        return (NULL);
    return (channels);
}

char *get_teams_info(steams_t *server)
{
    teams_t *tmp = NULL;
    char *teams = "LIST-TEAMS\n";

    LIST_FOREACH(tmp, &server->teams, entry){
        teams = concat_team_channel(teams, tmp->id, tmp->name, tmp->desc);
    }
    if (strlen(teams) == 11)
        return (NULL);
    return (teams);
}

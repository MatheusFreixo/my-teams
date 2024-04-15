/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** checkers
*/

#include "../../../include/teams_server.h"

bool check_channel(steams_t *server, char *id)
{
    channels_t *tmp = NULL;

    LIST_FOREACH(tmp, &server->channels, entry){
        if (strcmp(tmp->id, id) == 0){
            return (true);
        }
    }
    return (false);
}

bool check_thread(steams_t *server, char *id)
{
    threads_t *tmp = NULL;

    LIST_FOREACH(tmp, &server->threads, entry){
        if (strcmp(tmp->id, id) == 0){
            return (true);
        }
    }
    return (false);
}

bool check_team(steams_t *server, char *id)
{
    teams_t *tmp = NULL;

    LIST_FOREACH(tmp, &server->teams, entry){
        if (strcmp(tmp->id, id) == 0){
            return (true);
        }
    }
    return (false);
}

bool check_client(steams_t *server, int client_fd)
{
    users_t *tmp = NULL;

    LIST_FOREACH(tmp, &server->users, entry){
        if (tmp->fd == client_fd){
            return (true);
        }
    }
    return (false);
}

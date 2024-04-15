/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_context
*/

#include "./../../../include/teams_server.h"

enum create_type check_context(steams_t *server)
{
    if (server->team_id != NULL && server->channel_id != NULL
    && server->thread_id != NULL){
        server->context = true;
        return (REPLY);
    }
    if (server->team_id != NULL && server->channel_id != NULL){
        server->context = true;
        return (THREAD);
    }
    if (server->team_id != NULL){
        server->context = true;
        return (CHANNEL);
    }
    server->context = false;
    return (TEAM);
}

void manage_context(steams_t *server, char **command, int client_fd)
{
    server->team_id = NULL;
    server->channel_id = NULL;
    server->thread_id = NULL;
    for (int i = 0; command[i] != NULL; i++) {
        server->team_id =
            check_team(server, command[i]) ? command[i] : NULL;
        server->channel_id =
            check_channel(server, command[i]) ? command[i] : NULL;
        server->thread_id =
            check_thread(server, command[i]) ? command[i] : NULL;
    }
    server->create_type = check_context(server);
}

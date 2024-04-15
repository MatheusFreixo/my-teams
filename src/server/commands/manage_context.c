/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_context
*/

#include "./../../../include/teams_server.h"

enum create_type check_context(steams_t *server)
{
    if (server->team_id != NULL && server->channel_id != NULL && server->thread_id != NULL){
        server->context = true;
        return (REPLY);
    } else if (server->team_id != NULL && server->channel_id != NULL){
        server->context = true;
        return (THREAD);
    } else if (server->team_id != NULL){
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
        check_team(server, command[i]) ? server->team_id = command[i] : NULL;
        check_channel(server, command[i]) ? server->channel_id = command[i] : NULL;
        check_thread(server, command[i]) ? server->thread_id = command[i] : NULL;
    }
    server->create_type = check_context(server);
}

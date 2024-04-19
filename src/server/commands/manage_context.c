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
        if (check_team(server, parse_message(command[i])))
            server->team_id = parse_message(command[i]);
        if (check_channel(server, parse_message(command[i])))
            server->channel_id = parse_message(command[i]);
        if (check_thread(server, parse_message(command[i])))
            server->thread_id = parse_message(command[i]);
    }
    server->create_type = check_context(server);
}

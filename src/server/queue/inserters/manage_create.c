/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_create
*/

#include "./../../../../include/teams_server.h"

void manage_create_command(steams_t *server, char **command, int client_fd)
{
    if (command[2] == NULL && server->create_type != REPLY){
        return;
    }
    switch (server->create_type) {
        case TEAM:
            add_team_to_list(server, parse_message(command[1]),
                parse_message(command[2]), client_fd);
            break;
        case CHANNEL:
            add_channel_to_list(server, parse_message(command[1]),
                parse_message(command[2]), client_fd);
            break;
        case THREAD:
            add_thread_to_list(server, parse_message(command[1]),
                parse_message(command[2]), client_fd);
            break;
        case REPLY:
            add_reply_to_list(server, parse_message(command[1]), client_fd);
            break;
    }
}

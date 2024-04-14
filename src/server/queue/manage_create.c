/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_create
*/

#include "./../../../include/teams_server.h"

void manage_create_command(steams_t *server, char **command, int client_fd)
{
    if (server->context == false && command[2] != NULL){
        add_team_to_list(server, command[1], command[2], client_fd);
    }
}

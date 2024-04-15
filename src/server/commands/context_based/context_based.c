/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** context_based
*/

#include "./../../../../include/teams_server.h"

void context_based(steams_t *server, char **command, int client_fd)
{
    if (strcmp(command[0], "/use") == 0)
        manage_context(server, command, client_fd);
    if (strcmp(command[0], "/create") == 0)
        manage_create_command(server, command, client_fd);
    if (strcmp(command[0], "/list") == 0){}
    if (strcmp(command[0], "/info") == 0){}
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** error_handling
*/

#include "../../../../include/teams_server.h"

int error_handling(steams_t *server)
{
    if (server == NULL || bind_socket(server) == 84
    || listen_on_socket(server->fd) == 84){
        return (84);
    }
    return (0);
}

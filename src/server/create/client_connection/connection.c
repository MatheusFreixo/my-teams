/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** connection
*/

#include "./../../../../include/teams_server.h"

void infinite_loop(steams_t *server)
{
    printf("Waiting for clients connections...\n");
    while (1) {
        FD_ZERO(&server->readfds);
        FD_SET(server->fd, &server->readfds);
    }
}

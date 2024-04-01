/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** client_management
*/

#include "./../../../../include/teams_server.h"

void set_clients(steams_t *server)
{
    for (int i = 0; i < 1024; i++) {
        if (server->client_fds[i] > 0){
            FD_SET(server->client_fds[i], &server->readfds);
        }
    }
    if (select(1024, &server->readfds, NULL, NULL, NULL) < 0) {
        exit(84);
    }
}

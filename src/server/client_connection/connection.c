/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** connection
*/

#include "./../../../include/teams_server.h"

int *check_disconnection(steams_t *server, int i)
{
    int *clients = server->client_fds;

    if (read(clients[i], server->buffer, 1024) == 0) {
        printf("Client disconnected, socket fd is %d\n", clients[i]);
        clients[i] = 0;
    } else {
        check_command(server, server->buffer, clients[i]);
    }
    return (clients);
}

void infinite_loop(steams_t *server)
{
    printf("Waiting for clients connections...\n");
    while (1) {
        FD_ZERO(&server->readfds);
        FD_SET(server->fd, &server->readfds);
        set_clients(server);
    }
}

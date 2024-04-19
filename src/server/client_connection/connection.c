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
    char **split_buffer = NULL;
    char *token = NULL;

    if (read(clients[i], server->buffer, 1024) == 0) {
        printf("Client disconnected, socket fd is %d\n", clients[i]);
        clients[i] = 0;
    } else {
        token = strtok(server->buffer, "\n");
        while (token != NULL){
            check_command(server, token, clients[i]);
            token = strtok(NULL, "\n");
        }
        server->buffer = NULL;
        server->buffer = malloc(sizeof(char) * 1024 + 1);
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

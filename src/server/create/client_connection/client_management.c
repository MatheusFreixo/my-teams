/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** client_management
*/

#include "./../../../../include/teams_server.h"

int *storing_clients(steams_t *server)
{
    int *clients = server->client_fds;
    socklen_t size = sizeof(server->client_addr);

    server->client_fd = accept(server->fd,
            (struct sockaddr *)&server->client_addr, &size);
    if (server->client_fd < 0) {
        exit(84);
    }
    for (int i = 0; i < 1024; i++)
        if (clients[i] == 0) {
            clients[i] = server->client_fd;
            break;
        }
    write(server->client_fd, server->msg[5], strlen(server->msg[5]));
    printf("Client connected\n");
    server->check.user[0] = false;
    server->check.pass[0] = false;
    return (clients);
}

void set_clients(steams_t *server)
{
    for (int i = 0; i < 1024; i++) {
        if (server->client_fds[i] > 0){
            FD_SET(server->client_fds[i], &server->readfds);
        }
    }
    if (select(1024, &server->readfds, NULL, NULL, NULL) < 0) {
        // to_exit(server);
        exit(84);
    }
    // check_clients(server);
}
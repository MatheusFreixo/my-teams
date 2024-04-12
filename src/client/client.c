/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** client
*/

#include "../../include/teams_client.h"

int server_connection(cteams_t *client)
{
    if (connect(client->fd, (struct sockaddr*) &client->addr,
                sizeof(client->addr)) != 0){
        printf("Connection failed\n");
        return (84);
    }
    return (0);
}

void read_input(cteams_t *client)
{
    read(INPUT_FD, client->in_buffer, 1024);
    if (strncmp(client->in_buffer, "/logout", 7) == 0){
        close(client->fd);
        to_exit(client);
        client_event_logged_out("121", "No one");
        exit(0);
    }
}

int infinite_loop(cteams_t *client)
{
    if (server_connection(client) == 84)
        return (84);
    while (1) {
        FD_ZERO(&client->readfds);
        FD_SET(client->fd, &client->readfds);
        FD_SET(INPUT_FD, &client->readfds);
        if (select(client->fd + 1, &client->readfds, NULL, NULL, NULL) < 0) {
            printf("Error while selecting\n");
            return (84);
        }
        send(client->fd, client->welcome, strlen(client->welcome), 0);
        if (FD_ISSET(INPUT_FD, &client->readfds))
            read_input(client);
        if (FD_ISSET(client->fd, &client->readfds)) {
            read(client->fd, client->buffer, 1024);
            printf("%s\n", client->buffer);
        }
    }
    return (0);
}

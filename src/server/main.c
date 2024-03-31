/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** main
*/

#include "../../include/teams_server.h"

struct server_teams *setup_server_struct(char *port)
{
    steams_t *tmp = malloc(sizeof(steams_t));

    tmp->port = atoi(port);
    tmp->fd = create_socket();
    if (tmp->fd == 84)
        return (NULL);
    tmp->addr = configure_socket(tmp->port);
    tmp->buffer = malloc(sizeof(char) * 1024 + 1);
    tmp->client_fds = malloc(sizeof(int) * 1024);
    tmp->pwd = malloc(sizeof(char) * 1000 + 1);
    for (int i = 0; i < 1024; i++)
        tmp->client_fds[i] = '\0';
    tmp->file_buff = malloc(sizeof(char) * 1000 + 1);
    return (tmp);
}

int main(int argc, char **argv)
{
    steams_t *server;

    if (argc != 2){
        return (84);
    }
    server = setup_server_struct(argv[1]);
    return (0);
}

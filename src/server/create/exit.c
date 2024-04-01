/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** exit
*/

#include "../../../include/teams_server.h"

void free_checkers(steams_t *server)
{
    free(server->check.user);
    free(server->check.pass);
    free(server->check.auth);
}

char *free_buff(steams_t *server)
{
    free(server->buffer);
    server->buffer = malloc(sizeof(char) * 1024 + 1);
    return (server->buffer);
}

void free_arr(steams_t *server)
{
    for (int i = 0; server->client_msg[i] != NULL; i++) {
        free(server->client_msg[i]);
    }
    free(server->client_msg);
}

void to_exit(steams_t *server)
{
    if (server->client_fds != NULL)
        free(server->client_fds);
    if (server->buffer != NULL)
        free(server->buffer);
    free_arr(server);
    free_checkers(server);
    free(server->pwd);
    free(server->file_buff);
    if (server != NULL)
        free(server);
}

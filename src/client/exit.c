/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** exit
*/

#include "../../include/teams_client.h"

void free_checkers(cteams_t *client)
{
    free(client->check.user);
    free(client->check.pass);
    free(client->check.auth);
}

char *free_buff(cteams_t *client)
{
    free(client->buffer);
    client->buffer = malloc(sizeof(char) * 1024 + 1);
    return (client->buffer);
}

void free_arr(cteams_t *client)
{
    for (int i = 0; client->client_msg[i] != NULL; i++) {
        free(client->client_msg[i]);
    }
    free(client->client_msg);
}

void to_exit(cteams_t *client)
{
    if (client->client_fds != NULL)
        free(client->client_fds);
    if (client->buffer != NULL)
        free(client->buffer);
    free_checkers(client);
    free(client->pwd);
    free(client->file_buff);
    if (client != NULL)
        free(client);
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** messages
*/

#include "../../include/teams_client.h"

void check_messages(cteams_t *client)
{
    char **msg = split_str(client->buffer, '\n');

    client->tok = strtok(client->buffer, "\r\n");
    if (strncmp(msg[0], "LOGIN", 5) == 0) {
        client->id = strdup(msg[1]);
        client_event_logged_in(client->id, client->name);
    } else if (strncmp(msg[0], "LOGOUT", 6) == 0) {
        client_event_logged_out(client->id, client->name);
        close(client->fd);
        to_exit(client);
        exit(0);
    } else if(strcmp(msg[0], "TEAM-CREATED") == 0) {
        client_event_team_created(msg[1], msg[2], msg[3]);
    }
    free(client->buffer);
    client->buffer = malloc(sizeof(char) * 1024 + 1);
}

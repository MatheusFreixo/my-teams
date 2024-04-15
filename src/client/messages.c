/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** messages
*/

#include "../../include/teams_client.h"

bool check_log(char *command)
{
    for (int i = 0; log[i] != NULL; i++) {
        if (strcmp(log[i], command) == 0) {
            return (true);
        }
    }
    return (false);
}

bool check_create(char *command)
{
    for (int i = 0; create[i] != NULL; i++) {
        if (strcmp(create[i], command) == 0) {
            return (true);
        }
    }
    return (false);
}

void manage_create_message(cteams_t *client, char **msg)
{
    if (strcmp(msg[0], "TEAM-CREATED") == 0){
        client_event_team_created(msg[1], msg[2], msg[3]);
        client_print_team_created(msg[1], msg[2], msg[3]);
    }
    if (strcmp(msg[0], "CHANNEL-CREATED") == 0){
        client_event_channel_created(msg[1], msg[2], msg[3]);
        client_print_channel_created(msg[1], msg[2], msg[3]);
    }
    if (strcmp(msg[0], "THREAD-CREATED") == 0){
        client_event_thread_created(msg[1], msg[2],
            (time_t)strtoul(msg[3], NULL, strlen(msg[3])), msg[4], msg[5]);
        client_print_thread_created(msg[1], msg[2],
            (time_t)strtoul(msg[3], NULL, strlen(msg[3])), msg[4], msg[5]);
    }
    if (strcmp(msg[0], "REPLY-CREATED") == 0){
        client_print_reply_created(msg[1], msg[2],
            (time_t)strtoul(msg[3], NULL, strlen(msg[3])), msg[4]);
    }
}

void manage_log_message(cteams_t *client, char **msg)
{
    if (strncmp(msg[0], "LOGIN", 5) == 0){
        client->id = strdup(msg[1]);
        client_event_logged_in(client->id, client->name);
    } else if (strncmp(msg[0], "LOGOUT", 6) == 0){
        client_event_logged_out(client->id, client->name);
        close(client->fd);
        to_exit(client);
        exit(0);
    }
}

void check_messages(cteams_t *client)
{
    char **msg = split_str(client->buffer, '\n');

    client->tok = strtok(client->buffer, "\r\n");
    if (check_log(msg[0])){
        manage_log_message(client, msg);
    } else if (check_create(msg[0])){
        manage_create_message(client, msg);
    }
    free(client->buffer);
    client->buffer = malloc(sizeof(char) * 1024 + 1);
}

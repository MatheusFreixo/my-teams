/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** messages
*/

#include "../../include/teams_client.h"

void manage_user_message(char **msg)
{
    char **details = NULL;

    if (strcmp(msg[0], "USER") == 0){
        details = split_str(msg[1], '\t');
        client_print_user(details[0], details[1], atoi(details[2]));
    }
    if (strcmp(msg[0], "USERS") == 0){
        for (int i = 1; msg[i] != NULL; i++){
            details = split_str(msg[i], '\t');
            client_print_users(details[0], details[1], atoi(details[2]));
        }
    }
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
        client->name = strdup(msg[2]);
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
    if (check_log(msg[0]))
        manage_log_message(client, msg);
    if (check_create(msg[0]))
        manage_create_message(client, msg);
    if (check_user_msg(msg[0]))
        manage_user_message(msg);
    free(client->buffer);
    client->buffer = NULL;
    client->buffer = malloc(sizeof(char) * 1024 + 1);
}

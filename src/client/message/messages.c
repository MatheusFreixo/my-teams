/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** messages
*/

#include "../../../include/teams_client.h"

void manage_messages(char **msg)
{
    char **details = NULL;

    for (int i = 1; msg[i] != NULL; i++){
        details = split_str(msg[i], '\b');
        if (details[2] == NULL){
            break;
        }
        client_private_message_print_messages(parse_message(details[0]),
            parse_time(details[1]), parse_message(details[2]));
    }
}

void manage_user_message(char **msg)
{
    char **details = NULL;
    char *id;
    char *name;

    if (strcmp(msg[0], "USER") == 0){
        details = split_str(msg[1], '\t');
        id = parse_message(details[0]);
        name = parse_message(details[1]);
        client_print_user(id, name, atoi(details[2]));
    }
    if (strcmp(msg[0], "USERS") == 0){
        for (int i = 1; msg[i] != NULL; i++){
            details = split_str(msg[i], '\t');
            id = parse_message(details[0]);
            name = parse_message(details[1]);
            client_print_users(id, name, atoi(details[2]));
        }
    }
}

void manage_user_related_message(char **msg)
{
    char **details = NULL;

    if (strncmp(msg[0], "USER", 4) == 0){
        manage_user_message(msg);
        return;
    }
    if (strcmp(msg[0], "RECEIVED") == 0){
        details = split_str(msg[1], '\t');
        client_event_private_message_received(
            parse_message(details[0]), parse_message(details[1]));
    }
    if (strcmp(msg[0], "MESSAGES") == 0){
        manage_messages(msg);
    }
}

void manage_log_message(cteams_t *client, char **msg)
{
    if (strncmp(msg[0], "LOGIN", 5) == 0){
        client->id = parse_message(msg[1]);
        client->name = parse_message(msg[2]);
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
        manage_user_related_message(msg);
    if (strncmp(msg[0], "LIST", 4) == 0)
        manage_list_message(msg);
    if (check_subs_msg(msg[0]))
        manage_subs_message(msg);
    free(client->buffer);
    client->buffer = NULL;
    client->buffer = malloc(sizeof(char) * 1024 + 1);
}

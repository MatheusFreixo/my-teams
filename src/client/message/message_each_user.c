/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** message_each_user
*/

#include "../../../include/teams_client.h"

void each_user_details(char **msg)
{
    char **details = NULL;
    char *id = NULL;
    char *name = NULL;

    for (int i = 1; msg[i] != NULL; i++){
        details = split_str(msg[i], '\t');
        if (details[2] == NULL)
            break;
        id = parse_message(details[0]);
        name = parse_message(details[1]);
        client_print_users(id, name, atoi(details[2]));
    }
}

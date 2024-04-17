/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** parser
*/

#include "../../../include/teams_client.h"

time_t parse_time(char *time)
{
    time_t parsed_time = (time_t)strtoul(time, NULL, strlen(time));

    return (parsed_time);
}

char *parse_message(char *message)
{
    char *parsed_msg = NULL;

    if (message[0] != '"')
        return (message);
    parsed_msg = malloc(sizeof(char) * (strlen(message)));
    for (int i = 0; message[i] != '\0'; i++){
        if (message[i] != '"'){
            parsed_msg[i - 1] = message[i];
        }
    }
    return (parsed_msg);
}

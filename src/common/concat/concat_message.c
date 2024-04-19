/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** concat_message
*/

#include "../../../include/teams_server.h"

char *concat_message_to_send(char *str1, const char *id, char *message)
{
    char *str = malloc(strlen(str1) + strlen(id) + strlen(message) + 20);

    strcpy(str, str1);
    strcat(str, "\n");
    strcat(str, id);
    strcat(str, "\t");
    strcat(str, message);
    strcat(str, "\t");
    return (str);
}

char *concat_message_info(char *str1, const char *id, time_t timest, char *msg)
{
    char *time = parse_time_to_string(timest);
    char *str = malloc(
        strlen(str1) + strlen(id) + strlen(time) + strlen(msg) + 5);

    strcpy(str, str1);
    strcat(str, id);
    strcat(str, "\b");
    strcat(str, time);
    strcat(str, "\b");
    strcat(str, msg);
    strcat(str, "\n");
    return (str);
}

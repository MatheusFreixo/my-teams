/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** concat_malloc
*/

#include "../../include/teams_server.h"

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
    char *str = malloc(strlen(str1) + strlen(id) + strlen(msg) + 30);
    char *time = malloc(sizeof(char) * 20 + 1);

    sprintf(time, "%ld", timest);
    strcpy(str, str1);
    strcat(str, "\n");
    strcat(str, id);
    strcat(str, "\t");
    strcat(str, time);
    strcat(str, "\t");
    strcat(str, msg);
    strcat(str, "\n");
    return (str);
}

char *concat_malloc(char *str1, const char *id, char *name, bool status)
{
    char *str = malloc(strlen(str1) + strlen(id) + strlen(name) + 6);
    char *status_str = status ? "1" : "0";

    strcpy(str, str1);
    if (str[strlen(str) - 1] != '\n')
        strcat(str, "\n");
    strcat(str, id);
    strcat(str, "\t");
    strcat(str, name);
    strcat(str, "\t");
    strcat(str, status_str);
    strcat(str, "\t");
    return (str);
}

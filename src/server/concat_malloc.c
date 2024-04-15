/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** concat_malloc
*/

#include "../../include/teams_server.h"

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
    return (str);
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** concat_subs_message
*/

#include "../../../include/teams_server.h"

char *concat_subs(
    char *str1, const char *team_id, const char *user_id, char *end)
{
    char *str = malloc(strlen(str1) + strlen(team_id) + strlen(user_id) + 3);

    strcpy(str, str1);
    strcat(str, user_id);
    strcat(str, "\t");
    strcat(str, team_id);
    strcat(str, end);
    return (str);
}

char *concat_subs_teams(char *str1, const char *id, char *name, char *desc)
{
    char *str = malloc(strlen(str1) + strlen(id) + strlen(name)
        + strlen(desc) + 4);

    strcpy(str, str1);
    strcat(str, id);
    strcat(str, "\t");
    strcat(str, name);
    strcat(str, "\t");
    strcat(str, desc);
    strcat(str, "\n");
    return (str);
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** concat_malloc
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

char *concat_reply(char *str1, replies_t *reply)
{
    char *time = parse_time_to_string(reply->timestamp);
    char *str = malloc(strlen(str1) + strlen(reply->thread_id)
        + strlen(reply->user_id) + strlen(time) + strlen(reply->message) + 5);

    strcpy(str, str1);
    strcat(str, reply->thread_id);
    strcat(str, "\t");
    strcat(str, reply->user_id);
    strcat(str, "\t");
    strcat(str, time);
    strcat(str, "\t");
    strcat(str, reply->message);
    strcat(str, "\n");
    return (str);
}

char *concat_thread(char *str1, threads_t *thread)
{
    char *str;
    char *time = parse_time_to_string(thread->timestamp);

    str = malloc(strlen(str1) + strlen(thread->id) + strlen(thread->user_id)
        + strlen(time) + strlen(thread->title) + strlen(thread->message) + 6);
    strcpy(str, str1);
    strcat(str, thread->id);
    strcat(str, "\t");
    strcat(str, thread->user_id);
    strcat(str, "\t");
    strcat(str, time);
    strcat(str, "\t");
    strcat(str, thread->title);
    strcat(str, "\t");
    strcat(str, thread->message);
    strcat(str, "\n");
    return (str);
}

char *concat_team_channel(char *str1, const char *id, char *name, char *desc)
{
    char *str = malloc(
        strlen(str1) + strlen(id) + strlen(name) + strlen(desc) + 4);

    strcpy(str, str1);
    strcat(str, id);
    strcat(str, "\t");
    strcat(str, name);
    strcat(str, "\t");
    strcat(str, desc);
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

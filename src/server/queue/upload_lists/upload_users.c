/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** upload_users
*/

#include "../../../../include/teams_server.h"

void upload_to_list_user(steams_t *server, char *id, char *name, int status)
{
    users_t *user = malloc(sizeof(users_t));

    user->id = strdup(id);
    user->name = strdup(name);
    user->status = status;
    user->last_msg = malloc(sizeof(msg_t));
    if (LIST_EMPTY(&server->users)){
        LIST_INSERT_HEAD(&server->users, user, entry);
    } else {
        LIST_INSERT_AFTER(server->last_user, user, entry);
    }
    server->last_user = user;
}

void upload_to_list_team(steams_t *server, char *id, char *name, char *desc)
{
    teams_t *team = malloc(sizeof(teams_t));

    team->id = strdup(id);
    team->name = strdup(name);
    team->desc = strdup(desc);
    if (LIST_EMPTY(&server->teams)){
        LIST_INSERT_HEAD(&server->teams, team, entry);
    } else {
        LIST_INSERT_AFTER(server->last_team, team, entry);
    }
    server->last_team = team;
}

void upload_user(steams_t *server)
{
    char *users = readfile("./users.txt");
    char **each_user = split_str(users, '\n');
    char **user_info = NULL;

    for (int i = 1; each_user[i]; i++) {
        user_info = split_str(each_user[i], '\t');
        if (user_info[2] == NULL){
            break;
        }
        upload_to_list_user(
            server, user_info[0], user_info[1], atoi(user_info[2]));
        server->nb_users++;
    }
}

void upload_team(steams_t *server)
{
    char *teams = readfile("./teams.txt");
    char **each_team = split_str(teams, '\n');
    char **team_info = NULL;

    for (int i = 1; each_team[i]; i++) {
        team_info = split_str(each_team[i], '\t');
        if (team_info[2] == NULL){
            break;
        }
        upload_to_list_team(server, team_info[0], team_info[1], team_info[2]);
    }
}

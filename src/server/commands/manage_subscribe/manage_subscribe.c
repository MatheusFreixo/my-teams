/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_subscribe
*/

#include "./../../../../include/teams_server.h"

void subs_teams(steams_t *server, int client_fd)
{
    teams_t *tmp = NULL;
    const char *user_id = get_user_id_by_fd(server, client_fd);
    char *msg = "SUBSCRIBED-TEAMS\n";

    LIST_FOREACH(tmp, &server->teams, entry){
        if (check_list(tmp->subscribed, user_id)){
            msg = concat_subs_teams(msg, tmp->id, tmp->name, tmp->desc);
        }
    }
    write(client_fd, msg, strlen(msg));
}

void list_subscribed(steams_t *server, char **command, int client_fd)
{
    teams_t *tmp = NULL;
    char *msg;

    if (command[1] == NULL){
        subs_teams(server, client_fd);
        return;
    }
    LIST_FOREACH(tmp, &server->teams, entry){
        if (strcmp(tmp->id, command[1]) == 0){
            msg = get_all_subscribers(server, tmp);
        }
    }
    write(client_fd, msg, strlen(msg));
}

void unsubscribe_from_team(steams_t *server, char *id, int client_fd)
{
    teams_t *tmp = NULL;
    bool found = false;
    const char *user_id = get_user_id_by_fd(server, client_fd);
    char *msg = concat_subs("UNSUBSCRIBED\n", id, user_id, "\t");

    LIST_FOREACH(tmp, &server->teams, entry){
        if (strcmp(tmp->id, id) == 0){
            tmp->subscribed = remove_user_from_list(tmp->subscribed, user_id);
        }
    }
    write(client_fd, msg, strlen(msg));
}

void subscribe_to_team(steams_t *server, char *id, int client_fd)
{
    teams_t *tmp = NULL;
    const char *user_id = get_user_id_by_fd(server, client_fd);
    char *msg = "SUBSCRIBED\n";

    msg = concat_subs(msg, id, user_id, "\t");
    LIST_FOREACH(tmp, &server->teams, entry){
        if (strcmp(tmp->id, id) == 0){
            tmp->subscribed = add_user_id_to_list(tmp->subscribed, user_id);
        }
    }
    write(client_fd, msg, strlen(msg));
}

void manage_subscribe_command(steams_t *server, char **command, int client_fd)
{
    if (strcmp(command[0], "/subscribe") == 0) {
        if (command[1] == NULL) {
            return;
        }
        subscribe_to_team(server, command[1], client_fd);
    }
    if (strcmp(command[0], "/subscribed") == 0) {
        list_subscribed(server, command, client_fd);
    }
    if (strcmp(command[0], "/unsubscribe") == 0) {
        if (command[1] == NULL) {
            return;
        }
        unsubscribe_from_team(server, command[1], client_fd);
    }
}

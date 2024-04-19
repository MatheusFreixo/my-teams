/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_subscribe
*/

#include "./../../../../include/teams_server.h"

bool check_list(char **list, const char *user_id)
{
    for (int i = 0; list[i] != NULL; i++) {
        if (strcmp(list[i], user_id) == 0) {
            return (true);
        }
    }
    return (false);
}

int get_array_len(char **array)
{
    int i = 0;

    if (array == NULL)
        return (1);
    for (; array[i] != NULL; i++);
    return (i);
}

char **add_user_id_to_list(char **list, const char *user_id)
{
    char **tmp = malloc(sizeof(char *) * (get_array_len(list) + 2));
    int i = 0;

    if (list != NULL) {
        for (; list[i] != NULL; i++) {
            tmp[i] = strdup(list[i]);
        }
    }
    tmp[i] = strdup(user_id);
    tmp[i + 1] = NULL;
    return (tmp);
}

char **remove_user_id_from_list(char **list, const char *user_id)
{
    char **tmp = malloc(sizeof(char *) * (get_array_len(list) + 1));
    int j = 0;

    for (int i = 0; list[i] != NULL; i++) {
        if (strcmp(list[i], user_id) != 0) {
            tmp[j] = strdup(list[i]);
            j++;
        }
    }
    tmp[j] = NULL;
    return (tmp);
}

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
    char *user_name;

    if (command[1] == NULL){
        subs_teams(server, client_fd);
        return;
    }
    LIST_FOREACH(tmp, &server->teams, entry){
        if (strcmp(tmp->id, command[1]) == 0){
            msg = "SUBSCRIBED-USERS\n";
            for (int i = 0; tmp->subscribed[i] != NULL; i++){
                user_name = strdup(
                    get_user_name_by_id(server, tmp->subscribed[i]));
                msg = concat_malloc(msg, tmp->subscribed[i],
                    user_name, get_user_status(server, tmp->subscribed[i]));
            }
        }
    }
    write(client_fd, msg, strlen(msg));
}

void unsubscribe_from_team(steams_t *server, char *id, int client_fd)
{
    teams_t *tmp = NULL;
    bool found = false;
    const char *user_id = get_user_id_by_fd(server, client_fd);
    char *msg = "UNSUBSCRIBED\n";

    LIST_FOREACH(tmp, &server->teams, entry){
        if (strcmp(tmp->id, id) == 0){
            tmp->subscribed = remove_user_id_from_list(
                tmp->subscribed, user_id);
        }
    }
    if (found == true){
        msg = concat_subs(msg, id, user_id, "\t");
        write(client_fd, msg, strlen(msg));
    }
}

void subscribe_to_team(steams_t *server, char *id, int client_fd)
{
    teams_t *tmp = NULL;
    const char *user_id = get_user_id_by_fd(server, client_fd);
    char *msg = "SUBSCRIBED\n";

    LIST_FOREACH(tmp, &server->teams, entry){
        if (strcmp(tmp->id, id) == 0){
            tmp->subscribed = add_user_id_to_list(tmp->subscribed, user_id);
        }
    }
    msg = concat_subs(msg, id, user_id, "\t");
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

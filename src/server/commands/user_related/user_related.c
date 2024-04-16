/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** user_related
*/

#include "./../../../../include/teams_server.h"
// command[1] = receiver_id
// command[2] = message
void manage_send(steams_t *server, char **cmd, int client_fd)
{
    char *sender_id = NULL;
    char *msg_to_send = NULL;
    users_t *tmp = NULL;
    time_t t = time(NULL);

    if (cmd[2] == NULL)
        return;
    sender_id = strdup(get_user_id_by_fd(server, client_fd));
    LIST_FOREACH(tmp, &server->users, entry){
        if (strcmp(tmp->id, cmd[1]) == 0){
            tmp->msg = concat_message_info(tmp->msg, sender_id, t, cmd[2]);
            msg_to_send = concat_message_to_send(
                "RECEIVED", sender_id, cmd[2]);
            write(tmp->fd, msg_to_send, strlen(msg_to_send));
            return;
        }
    }
    msg_to_send = concat_message_to_send("ERROR-SEND", cmd[1], cmd[2]);
    write(client_fd, msg_to_send, strlen(msg_to_send));
    return;
}

void manage_user(steams_t *server, char **command, int client_fd)
{
    char *user = NULL;

    if (command[1] == NULL)
        return;
    user = get_specific_user(server, command[1]);
    if (user == NULL){
        user = malloc(sizeof(char) * strlen(command[1]) + 13);
        user = "ERROR-USER\n";
        strcat(user, command[1]);
    }
    write(client_fd, user, strlen(user));
}

void manage_users(steams_t *server, char **command, int client_fd)
{
    char *users = get_all_users(server);

    write(client_fd, users, strlen(users));
}

void user_related(steams_t *server, char **command, int client_fd)
{
    if (strcmp(command[0], "/users") == 0)
        manage_users(server, command, client_fd);
    if (strcmp(command[0], "/user") == 0)
        manage_user(server, command, client_fd);
    if (strcmp(command[0], "/send") == 0)
        manage_send(server, command, client_fd);
}

/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** user_related
*/

#include "./../../../../include/teams_server.h"

void manage_messages(steams_t *server, char **command, int client_fd)
{
    char *messages = get_messages_by_id(server,
        get_user_id_by_fd(server, client_fd), parse_message(command[1]));

    write(client_fd, messages, strlen(messages));
}

void manage_send(steams_t *server, char **cmd, int client_fd)
{
    char *msg_to_send = NULL;
    msg_t *msg;
    msg_t *tmp;
    int receiver_fd;

    if (cmd[2] == NULL)
        return;
    msg = store_message(
        server, client_fd, parse_message(cmd[1]), parse_message(cmd[2]));
    receiver_fd = get_user_fd_by_id(server, msg->receiver_id);
    if (receiver_fd == 0){
        msg_to_send = concat_message_to_send(
            "ERROR-SEND", parse_message(cmd[1]), msg->body);
        write(client_fd, msg_to_send, strlen(msg_to_send));
    } else {
        set_message(server, msg);
        msg_to_send = concat_message_to_send(
            "RECEIVED", msg->sender_id, msg->body);
        write(receiver_fd, msg_to_send, strlen(msg_to_send));
    }
}

void manage_user(steams_t *server, char **command, int client_fd)
{
    char *user = NULL;
    char *id = parse_message(command[1]);

    if (command[1] == NULL)
        return;
    user = get_specific_user(server, id);
    if (user == NULL){
        user = malloc(sizeof(char) * strlen(id) + 13);
        user = "ERROR-USER\n";
        strcat(user, id);
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
    char *cmd = parse_message(command[0]);

    if (strcmp(cmd, "/users") == 0)
        manage_users(server, command, client_fd);
    if (strcmp(cmd, "/user") == 0 && command[1] != NULL)
        manage_user(server, command, client_fd);
    if (strcmp(cmd, "/send") == 0 && command[2] != NULL)
        manage_send(server, command, client_fd);
    if (strcmp(cmd, "/messages") == 0 && command[1] != NULL)
        manage_messages(server, command, client_fd);
}

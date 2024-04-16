/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_teams
*/

#include "../../../include/teams_server.h"

char *gen_message_threads(char *type, threads_t *thread)
{
    int size = strlen(type) + strlen(thread->id) + strlen(thread->user_id)
        + strlen(thread->title) + strlen(thread->message) + 5;
    char *msg = malloc(sizeof(char) * size + 1);
    char *time;

    sprintf(time, "%ld", thread->timestamp);
    size = size + strlen(time);
    strcpy(msg, type);
    strcat(msg, "\n");
    strcat(msg, thread->id);
    strcat(msg, "\n");
    strcat(msg, thread->user_id);
    strcat(msg, "\n");
    strcat(msg, time);
    strcat(msg, "\n");
    strcat(msg, thread->title);
    strcat(msg, "\n");
    strcat(msg, thread->message);
    strcat(msg, "\n");
    return (msg);
}

struct threads *init_thread(
    steams_t *server,
    char *title,
    char *message,
    int client_fd)
{
    threads_t *tmp = malloc(sizeof(threads_t));

    tmp->id = gen_uuid_parsed();
    tmp->title = title;
    tmp->message = message;
    tmp->channel_id = server->channel_id;
    tmp->team_id = server->team_id;
    tmp->user_id = get_user_id_by_fd(server, client_fd);
    tmp->timestamp = time(NULL);
    return (tmp);
}

void add_thread_to_list(
    steams_t *server,
    char *title,
    char *message,
    int client_fd)
{
    threads_t *thread = NULL;
    char *msg = NULL;

    if (strcmp(title, "") == 0)
        return;
    thread = init_thread(server, title, message, client_fd);
    if (LIST_EMPTY(&server->threads))
        LIST_INSERT_HEAD(&server->threads, thread, entry);
    else
        LIST_INSERT_AFTER(server->last_thread, thread, entry);
    msg = gen_message_threads("THREAD-CREATED", thread);
    server_event_thread_created(thread->channel_id, thread->id,
        thread->user_id, thread->title, thread->message);
    write(client_fd, msg, strlen(msg));
    server->last_thread = thread;
    free(msg);
}

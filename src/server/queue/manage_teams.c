/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_teams
*/

#include "../../../include/teams_server.h"

char *gen_message(char *type, char *name, char *desc, const char *id)
{
    int size = strlen(type) + strlen(name) + strlen(desc) + strlen(id) + 3;
    char *msg = malloc(sizeof(char) * size + 1);

    strcpy(msg, type);
    strcat(msg, "\n");
    strcat(msg, id);
    strcat(msg, "\n");
    strcat(msg, name);
    strcat(msg, "\n");
    strcat(msg, desc);
    return (msg);
}

void add_team_to_list(steams_t *server, char *name, char *desc, int client_fd)
{
    teams_t *team = NULL;
    char *msg = NULL;

    if (check_team(server, name) || strcmp(name, "") == 0)
        return;
    team = malloc(sizeof(teams_t));
    team->id = gen_uuid_parsed();
    team->name = name;
    team->description = desc;
    team->channels = NULL;
    if (LIST_EMPTY(&server->teams))
        LIST_INSERT_HEAD(&server->teams, team, entry);
    else
        LIST_INSERT_AFTER(server->last_team, team, entry);
    msg = gen_message("TEAM-CREATED", team->name, team->description, team->id);
    server_event_team_created(team->id, team->name,
        get_user_id_by_fd(server, client_fd));
    write(client_fd, msg, strlen(msg));
    server->last_team = team;
    free(msg);
}
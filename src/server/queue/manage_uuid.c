/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_uuid
*/

#include "../../../include/teams_server.h"

const char *gen_uuid_parsed(void)
{
    uuid_t id;
    char *id_parsed = malloc(sizeof(char) * 37);

    uuid_generate(id);
    uuid_unparse(id, id_parsed);
    return (id_parsed);
}

const char *get_user_id(steams_t *server, char *name)
{
    users_t *tmp = NULL;

    LIST_FOREACH(tmp, &server->users, entry){
        if (strcmp(tmp->name, name) == 0){
            return (tmp->id);
        }
    }
    return (NULL);
}

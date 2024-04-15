/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** split_str
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_word(char const *str, char c)
{
    int count = 1;

    for (int index = 0; str[index] != '\0'; index++){
        if (str[index] == c){
            count++;
        }
    }
    return (count);
}

char **fill_arr(char **arr, char const *str, char c)
{
    bool is_quote = false;
    char **tmp = arr;
    int letters = 0;
    int words = 0;

    for (int index = 0; str[index] != '\0'; index++)
        if (str[index] == c && is_quote == false){
            tmp[words][letters] = '\0';
            letters = 0;
            words++;
        } else if (str[index] == '"') {
            tmp[words][letters] = str[index];
            is_quote = !is_quote;
            letters++;
        } else {
            tmp[words][letters] = str[index];
            letters++;
        }
    tmp[words][letters] = '\0';
    return (tmp);
}

char **alloc_arr(char const *str, char c, int count)
{
    char **arr = malloc(sizeof(char *) * (count + 1));
    bool is_quote = false;
    int words = 0;
    int letters = 0;

    arr = malloc(sizeof(char *) * (count + 1));
    arr[count] = NULL;
    for (int index = 0; str[index] != '\0'; index++)
        if (str[index] == c && is_quote == false) {
            arr[words] = malloc(sizeof(char) * letters + 1);
            words++;
            letters = 0;
        } else if (str[index] == '"') {
            is_quote = !is_quote;
            letters++;
        } else {
            letters++;
        }
    arr[words] = malloc(sizeof(char) * letters + 1);
    return (arr);
}

char **split_str(char const *str, char c)
{
    char **arr = NULL;

    arr = alloc_arr(str, c, count_word(str, c));
    arr = fill_arr(arr, str, c);
    return (arr);
}

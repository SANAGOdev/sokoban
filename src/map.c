/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** map.c
*/

#include "main.h"

map_t *load_map(const char *content)
{
    map_t *map = malloc(sizeof(map_t));

    map->o_locs = NULL;
    map->box_locs = NULL;
    map->nb_lines = count_lines(content);
    map->array = malloc(sizeof(char *) * (map->nb_lines + 1));
    if (!map || ! map->array)
        return (NULL);
    get_lines(content, map);
    map->array[map->nb_lines] = '\0';
    if (!check_size(map))
        return (NULL);
    if (!check_content(map))
        return (NULL);
    get_player_line(map);
    get_player_column(map);
    find_storage_locs(map);
    find_box_locs(map);
    return (map);
}

void get_lines(const char *content, map_t *map)
{
    int i = 0;
    int len = 0;
    int line = 0;

    len = get_line_size(content);
    map->nb_columns = len;
    while (len) {
        map->array[line] = malloc(sizeof(char) * (len + 1));
        for (i = 0; i < len; i++)
            map->array[line][i] = content[i];
        map->array[line][i] = '\0';
        line++;
        content += len + 1;
        len = get_line_size(content);
    }
}

int valid_line(const char *str)
{
    int i = 0;

    for (; str[i]; i++)
        if (
            str[i] != '#' &&
            str[i] != ' ' &&
            str[i] != 'X' &&
            str[i] != 'O' &&
            str[i] != 'P'
            )
            return (0);
    return (1);
}

int check_size(map_t *map)
{
    int i = 1;

    for (; map->array[i]; i++)
        if (my_strlen(map->array[i]) != my_strlen(map->array[i - 1]))
            return (0);
    return (1);
}

int check_content(map_t *map)
{
    int i = 0;

    for (i = 0; map->array[i]; i++)
        if (!valid_line(map->array[i]))
            return (0);
    return (1);
}

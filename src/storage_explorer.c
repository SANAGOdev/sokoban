/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** map_explorer.c
*/

#include "main.h"

void find_storage_locs(map_t *map)
{
    find_storage_line(map);
}

void find_storage_line(map_t *map)
{
    int line = 0;

    for (; map->array[line]; line++)
        find_storage_column(map, line);
}

void find_storage_column(map_t *map, int line)
{
    int column = 0;
    storage_loc_t *storage_loc;

    for (; map->array[line][column]; column++) {
        if (map->array[line][column] == 'O') {
            storage_loc = malloc(sizeof(storage_loc_t));
            storage_loc->pos.x = line;
            storage_loc->pos.y = column;
            storage_loc->next = NULL;
            add_to_storage_list(map, storage_loc);
        }
    }
}

void add_to_storage_list(map_t *map, storage_loc_t *storage_loc)
{
    if (!map->o_locs)
        map->o_locs = storage_loc;
    else
        get_last_storage(map)->next = storage_loc;
}

storage_loc_t *get_last_storage(map_t *map)
{
    storage_loc_t *first = map->o_locs;

    for (; first->next; first = first->next);
    return (first);
}

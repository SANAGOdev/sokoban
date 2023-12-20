/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** box_explorer.c
*/

#include "main.h"

void find_box_locs(map_t *map)
{
    find_box_line(map);
}

void find_box_line(map_t *map)
{
    int line = 0;

    for (; map->array[line]; line++)
        find_box_column(map, line);
}

void find_box_column(map_t *map, int line)
{
    int column = 0;
    box_loc_t *box_loc;

    for (; map->array[line][column]; column++) {
        if (map->array[line][column] == 'X') {
            box_loc = malloc(sizeof(box_loc_t));
            box_loc->pos.x = line;
            box_loc->pos.y = column;
            box_loc->next = NULL;
            add_to_box_list(map, box_loc);
        }
    }
}

void add_to_box_list(map_t *map, box_loc_t *box_loc)
{
    if (!map->box_locs)
        map->box_locs = box_loc;
    else
        get_last_box(map)->next = box_loc;
}

box_loc_t *get_last_box(map_t *map)
{
    box_loc_t *first = map->box_locs;

    for (; first->next; first = first->next);
    return (first);
}

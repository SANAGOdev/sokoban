/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** player_utils.c
*/

#include "main.h"

void check_storage_location(map_t *map, int line, int column)
{
    storage_loc_t *first = map->o_locs;

    for (; first; first = first->next)
        if (first->pos.x == line && first->pos.y == column)
            map->array[line][column] = 'O';
}

void update_line_box(map_t *map, int next_line, int next_line_box)
{
    box_loc_t *first = map->box_locs;

    for (; first; first = first->next)
        if (first->pos.x == next_line && first->pos.y == map->pos.y)
            first->pos.x = next_line_box;
}

void update_column_box(map_t *map, int next_column, int next_column_box)
{
    box_loc_t *first = map->box_locs;

    for (; first; first = first->next)
        if (first->pos.y == next_column && first->pos.x == map->pos.x)
            first->pos.y = next_column_box;
}

void enlarge_terminal(int x, int y)
{
    char msg[] = "Please enlarge the terminal";
    int row = y / 2;
    int col = x - my_strlen(msg);

    col = (col > 0 ? col / 2 : 0);
    mvprintw(row, col, "%s", msg);
}

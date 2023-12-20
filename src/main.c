/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** main.c
*/

#include "main.h"

int main(int argc, char const *argv[])
{
    int game_state = -1;
    int reset = 0;
    map_t *map = NULL;
    char *content = read_file(argv[1]);

    if (help_menu(argc, argv) == 1 || argc != 2)
        return (84);
    if (!content)
        return (84);
    do {
        reset = 0;
        map = load_map(content);
        if (!map)
            return (84);
        game_state = game_loop(map, &reset);
        black_hole(map);
    } while (reset);
    free(content);
    return (game_state);
}

int help_menu(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++) {
        if (my_strcmp(argv[i], "-h") == 0) {
            my_printf("USAGE\n\t./my_sokoban map\n");
            my_printf("DESCRIPTION\n\tmap file representing the warehouse ");
            my_printf("map, containing '#' for walls, 'P' for the player, ");
            my_printf("'X' for boxes and 'O' for storage locations.\n");
            return 1;
        }
    }
    return 0;
}

void black_hole(map_t *map)
{
    box_loc_t *box = map->box_locs;
    storage_loc_t *store = map->o_locs;

    while (box) {
        map->box_locs = box->next;
        free(box);
        box = map->box_locs;
    }
    while (store) {
        map->o_locs = store->next;
        free(store);
        store = map->o_locs;
    }
    for (int i = 0; map->array[i]; i++)
        free(map->array[i]);
    free(map->array);
    free(map);
}

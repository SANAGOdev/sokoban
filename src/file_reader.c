/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** file_reader.c
*/

#include "main.h"

char *close_file(FILE *file)
{
    fclose(file);
    return (NULL);
}

char *read_file(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    char *content;
    struct stat file_info;

    if (file == NULL)
        return NULL;
    if (stat(filename, &file_info) != 0)
        return close_file(file);
    content = (char *)malloc(file_info.st_size + 1);
    if (content == NULL)
        return close_file(file);
    if (fread(content, 1, file_info.st_size, file)
        != (size_t)file_info.st_size) {
        free(content);
        return close_file(file);
    }
    content[file_info.st_size] = '\0';
    fclose(file);
    return is_valid_content(content, file_info.st_size);
}

char *is_valid_content(char *content, unsigned long size)
{
    int player_count = 0;
    int box_count = 0;
    int loc_count = 0;

    if (content[size - 1] != '\n')
        return freeing(content);
    for (int i = 0; content[i]; i++) {
        if (content[i] == 'P')
            player_count++;
        if (content[i] == 'X')
            box_count++;
        if (content[i] == 'O')
            loc_count++;
    }
    if (player_count != 1 || box_count != loc_count)
        return freeing(content);
    return content;
}

char *freeing(char *content)
{
    free(content);
    return (NULL);
}

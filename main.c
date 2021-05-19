/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <stdio.h>
#include "my.h"
#include <stdlib.h>

char *load_file_in_mem(char const *filepath);

int get_nb_cols(char *str);

char **load_2d_arr_from_file (char const *filepath, int nb_rows, int nb_cols);

char **find_largest_square(char **arr);

int get_nb_rows(char *str);

int handle_errors(char **arr);

int find_first_dot(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            str[i] = 'x';
            break;
        }
    }
    my_putstr(str);
    return (0);
}

int main(int argc , char **av)
{
    if (argc != 2)
        return (84);
    char *path = av[1];
    char *str = load_file_in_mem(path);
    if (str == NULL)
        return (84);
    int row = get_nb_rows(str) + 1;
    int col = get_nb_cols(str);
    char **arr2 = load_2d_arr_from_file(path, row, col);

    if (handle_errors(arr2) == 84)
        return (84);
    if (col == 1 || row == 2)
        if (find_first_dot(str) == 0)
            return (0);
    find_largest_square(arr2);
    return (0);
}
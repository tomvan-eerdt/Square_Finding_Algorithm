/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *count_lines(char *str);

int fs_open_file2(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        return (-1);
    }
    else
        return (fd);
}

char *load_file_in_mem(char const *filepath)
{
    int fd = fs_open_file2(filepath);
    if (fd == -1)
        return (NULL);
    struct stat buf;
    stat(filepath, &buf);
    char *str = malloc(sizeof(char) * (buf.st_size + 1));
    size_t buf_s = buf.st_size;
    int a = read(fd, str, buf_s);

    if (buf.st_size == 0)
        return (NULL);
    str[a] = '\0';
    str = count_lines(str);
    if (str == NULL)
        return (NULL);
    return (rm_first_line_str(str));
}

int get_nb_cols(char *str)
{
    int i;

    for (i = 0; str[i] != '\n'; i++) {}
    return (i);
}

int get_nb_rows(char *str)
{
    int a = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            a++;
        }
        i++;
    }
    return (a);
}

char **load_2d_arr_from_file (char const *filepath, int nb_rows, int nb_cols)
{
    char *file = load_file_in_mem(filepath);
    char **arr2 = malloc(sizeof(char *) * (nb_rows) + 1);
    int a = 0;
    int b = 0;

    arr2[a] = malloc(sizeof(char) * (nb_cols) + 1);
    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '\n') {
            arr2[a][b] = '\0';
            a = a + 1;
            arr2[a] = malloc(sizeof(char) * (nb_cols) + 1);
            b = -1;
        }
        else
            arr2[a][b] = file[i];
        b++;
    }
    arr2[a] = NULL;
    return (arr2);
}
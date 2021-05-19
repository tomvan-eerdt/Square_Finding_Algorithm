/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <stdio.h>
#include <stdlib.h>

int get_rows(char **arr)
{
    int i;

    for (i = 0; arr[i] != NULL; i++) {}
    return (i);
}

int get_cols(char **arr)
{
    int i;

    for (i = 0; arr[1][i] != '\0'; i++) {}
    return (i);
}
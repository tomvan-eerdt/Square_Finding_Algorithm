/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int check_if_correct_chars(char **arr)
{
    for (int i = 0; i != get_rows(arr); i++) {
        for (int k = 0; arr[i][k] != '\0'; k++) {
            if (arr[i][k] != 46 && arr[i][k] != 111)
                return (84);
        }
    }
    return (0);
}

char *count_lines(char *str)
{
    int i;
    int a = -2;
    char *number;

    for (i = 0; str[i] != '\n'; i++) {}
    number = malloc(sizeof(char) * i) ;
    for (i = 0; str[i] != '\n'; i++) {
        number[i] = str[i];
    }
    number[i] = '\0';
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            a++;
    }
    if (a + 1 != str_to_int(number))
        str = NULL;
    return (str);
}

int handle_errors(char **arr)
{
    if (check_if_correct_chars(arr) == 84)
        return (84);
    return (0);
}
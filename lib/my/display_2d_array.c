/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Write a function that displays, one-by-one, the characters of a string
*/

int my_putstr(char const *str);

int my_putchar(char str);
#include <stdlib.h>
#include <stdio.h>

void display_2d_array(char **str, int row)
{
    for (int i = 0; str[i] != NULL; i++) {
        my_putstr(str[i]);
        my_putchar('\n');
    }
}
/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Write a function that displays, one-by-one, the characters of a string
*/

int my_strlen(char const *str);
#include <stdlib.h>
#include <stdio.h>

char *rm_first_line_str(char *str)
{
    int i;
    int a = 0;
    int b = 0;
    int h;
    char *str2 = malloc(sizeof(char) * my_strlen(str) + 1);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' && a == 0)
            a++;
        else if (a > 0) {
            str2[b] = str[i];
            b++;
        }
    }
    str2[b] = '\0';
    return (str2);
}
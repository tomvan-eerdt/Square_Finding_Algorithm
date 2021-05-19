/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <stdlib.h>
#include "my.h"

void filled_array(char **arr, int posx, int posy, int count)
{
    int i;
    int k;

    for (i = 0; i < count; i++) {
        for (k = 0; k < count; k++) {
            arr[posx + i][posy + k] = 'x';
        }
    }
    display_2d_array(arr, get_rows(arr));
}

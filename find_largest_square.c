/*
** EPITECH PROJECT, 2020
** algorithms
** File description:
** desc
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void filled_array(char **arr, int posx, int posy, int count);

void fill_int(char **arr, int m, int n, int **a)
{
    for (int i = 0; i != n; i++) {
        for (int k = 0; k != m; k++) {
            if (arr[i][k] != '.') {
                a[i][k] = 0;
            }
            else if (i == n - 1 || k == m - 1)
                a[i][k] = 1;
            else
                a[i][k] = -11;
        }
    }
}

int **count_square(int **a, int j, int k, int *largest)
{
    int r;

    if (a[j][k] != 0) {
        r = min_int(a[j + 1][k + 1], a[j][k + 1], a[j + 1][k]) + 1;
        a[j][k] = r;
        if (r >= largest[0]) {
            largest[0] = r;
            largest[1] = j;
            largest[2] = k;
        }
    }
}

void find_largest_square(char **arr)
{
    int m = get_cols(arr);
    int n = get_rows(arr);
    int **a = malloc(sizeof(int *) * n);
    int largest[3];

    largest[0] = 0;
    for (int p = 0; p != n; p++)
        a[p] = malloc(sizeof(int) * m + 1);
    fill_int(arr, m, n, a);
    for (int j = n - 2; j != -1; j--) {
        for (int k = m - 2; k != -1; k--)
            count_square(a, j, k, largest);
    }
    filled_array(arr, largest[1], largest[2], largest[0]);
}
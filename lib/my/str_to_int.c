/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** desc
*/

int str_to_int(char *str)
{
    int result;
    int puiss;

    result = 0;
    puiss = 1;
    while (('-' == (*str)) || ((*str) == '+'))
    {
        if (*str == '-')
            puiss = puiss * -1;
        str++;
    }
    while ((*str >= '0') && (*str <= '9'))
    {
        result = (result * 10) + ((*str) - '0');
        str++;
    }
    return (result * puiss);
}
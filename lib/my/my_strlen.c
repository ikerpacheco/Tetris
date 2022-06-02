/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** Return the length of a given string.
*/

int my_strnlen(char const *str)
{
    for (int i = 0; str[i] != '\n'; i++)
    return i;
}

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0')
        length++;
    return (length);
}

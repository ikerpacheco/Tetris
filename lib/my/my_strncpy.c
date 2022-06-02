/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** str cpy of n characters
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int	i = 0;

    while (src[i] && i < n) {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}

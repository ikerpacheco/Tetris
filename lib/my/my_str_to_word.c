/*
** EPITECH PROJECT, 2022
** my_str_to_wordarray
** File description:
** turn a string into a 2D array in which every array is a word
*/

#include "../../include/my.h"

char **my_2Dmalloc(char **array, int size)
{
    array = malloc((size + 1) * sizeof(char *));

    for (int i = 0; i < size; i++)
        array[i] = malloc(50 * sizeof(char));
    array[size] = NULL;
    return (array);
}

int is_alnum(char c)
{
    if (c < 45 || (c > 45 && c <= 47) || c >= 127)
        return 0;
    return 1;
}

int	word_count(char *str)
{
    int i = 0;
    int word = 0;

    while (str != NULL && str[i]) {
        if (is_alnum(str[i]) == 1 && is_alnum(str[i + 1]) == 0)
            word = word + 1;
        i = i + 1;
    }
    return (word);
}

char **my_str_to_word(char *str)
{
    int	j = 0;
    int	i = 0;
    char **wordtab = malloc((word_count(str) + 1) * sizeof(char *));
    int	len = 0;

    while (str != NULL && str[i]) {
        if (is_alnum(str[i]))
            len = len + 1;
        if (is_alnum(str[i]) == 1 && is_alnum(str[i + 1]) == 0) {
            wordtab[j] = malloc(len + 1);
            my_strncpy(wordtab[j], &str[i - len + 1], len);
            len = 0;
            j = j + 1;
        }
        i = i + 1;
    }
    wordtab[j] = NULL;
    return (wordtab);
}
#include "substring.h"

/**
* find_substring - find substring in string
* @s: string
* @words: words to find
* @nb_words: number of words
* @n: number of words found
*
* Return: array of indices
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int *indices;
    int i, j, k, l;

    indices = malloc(sizeof(int) * nb_words);
    if (!indices)
        return (NULL);
    for (i = 0; i < nb_words; i++)
    {
        for (j = 0; s[j] == words[i][j]; j++)
        {
            if (words[i][j + 1] == '\0')
            {
                indices[i] = j;
                break;
            }
        }
        if (j == 0)
        {
            free(indices);
            return (NULL);
        }
    }
    for (i = 0; i < nb_words; i++)
    {
        for (j = i + 1; j < nb_words; j++)
        {
            if (indices[i] > indices[j])
            {
                k = indices[i];
                indices[i] = indices[j];
                indices[j] = k;
                l = i;
                i = j;
                j = l;
            }
        }
    }
    *n = nb_words;
    return (indices);
}

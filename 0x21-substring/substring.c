#include "substring.h"

/**
 * compare - compares strings
 * @s1: first string
 * @i: index
 * @s2: second string
 *
 * Return: length of the shorter word contained or 0 if no match
 */
int compare(char const *s1, unsigned int i, char const *s2)
{
	unsigned int j = 0;

	for (j = 0; s1[i] && s2[j]; i++, j++)
	{
		if (s1[i] != s2[j])
			return (0);
	}
	return (j);
}

/**
 * set_to - sets elements of array
 * @array: pointer to array
 * @size: the size of the array
 *
 */
void set_to(int **array, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
		(*array)[i] = -1;
}

/**
 * mem - allocates memory for int arrays
 * @word_used: pointer to first
 * @nb_words: number of words
 * @indices: pointer to second
 * @max_index: max number
 *
 * Return: -1 or 0
 */
int mem(int **word_used, int nb_words, int **indices, int max_index)
{
	*word_used = malloc(sizeof(int) * nb_words);
	if (*word_used == NULL)
		return (-1);
	set_to(word_used, nb_words);
	*indices = malloc(sizeof(int) * max_index);
	if (*indices == NULL)
	{
		free(word_used);
		return (-1);
	}
	set_to(indices, max_index);
	return (0);
}

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
	int word = 0, i = 0, match = 0, count = 0, j = 0, k = 0, I = 0;
	int *word_used = NULL, *indices = NULL;

	*n = 0;
	if (words == NULL)
		return (NULL);

	j = (nb_words * strlen(words[0]));
	i = mem(&word_used, nb_words, &indices, (strlen(s) / j) + 1);
	if (i == -1)
		return (NULL);
	for (i = 0; s[i]; i++)
	{
		I = i;
		for (set_to(&word_used, nb_words), word = 0; word < nb_words && s[i]; word++)
		{
			match = compare(s, i, words[word]);
			while (match != 0)
			{
				word_used[word] = 1;
				i += match;
				if (s[i] == '\0')
					break;
				for (count = 0, word = 0; word < nb_words; word++)
				{
					if (word_used[word] != -1)
						count++;
					match = compare(s, i, words[word]);
					if (match != 0)
						break;
				}
				if (count == nb_words)
					indices[k++] = (i - j);
			}
		}
		if (i != I || s[i] == '\0')
			i--;
	}
	free(word_used);
	*n = k;
	return (indices);
}

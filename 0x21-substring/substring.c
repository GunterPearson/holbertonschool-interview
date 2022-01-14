#include "substring.h"


/**
 * free_tree - frees nodes
 * @root: pointer
 */
void free_tree(Tree *root)
{
	int i = 0;

	for (i = 0; i < 26; i++)
		if (root->children[i])
			free_tree(root->children[i]);
	free(root);
}

/**
 * tree - searches for word
 * @node: root of tree
 * @str: string
 * @k: characters in string
 * @memo: array
 * @j: index
 * Return: 1 or 0
 */
int tree(Tree *node, char *str, int k, Tree **memo, int j)
{
	for (; k; str++, k--)
	{
		if (!node->children[INDEX(*str)])
			return (0);
		node = node->children[INDEX(*str)];
	}

	memo[j] = node;
	if (node->left-- > 0)
	{
		return (1);
	}
	return (0);
}

/**
 * build_tree - builds tree
 * @root: pointer
 * @words: pointer
 * @nb_words: number of words
 * @nodes: populate array
 */
void build_tree(Tree *root, char const **words, int nb_words, Tree **nodes)
{
	int i = 0;
	char const *str;
	Tree *node;

	for (i = 0; i < nb_words; i++)
	{
		node = root;
		for (str = words[i]; *str; str++)
		{
			if (!node->children[INDEX(*str)])
			{
				node->children[INDEX(*str)] = calloc(1, sizeof(Tree));
				if (!node->children[INDEX(*str)])
					exit(1);
			}
			node = node->children[INDEX(*str)];
		}
		node->word = 1;
		node->count++;
		node->left++;
		node->val = (char *)words[i];
		nodes[i] = node;
	}
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
	int i = 0, j, k, slen, matches;
	Tree *root, **nodes, **memo;
	int *indices;

	*n = 0;
	slen = strlen(s);
	k = strlen(words[0]);
	indices = calloc(slen, sizeof(int));
	root = calloc(1, sizeof(Tree));
	nodes = calloc(nb_words, sizeof(*nodes));
	memo = calloc(slen, sizeof(*memo));
	if (!indices || !root || !nodes || !memo)
		exit(1);
	build_tree(root, words, nb_words, nodes);

	for (i = 0; i < slen; i++)
	{
		matches = 0;
		for (j = i; j <= slen - k; j += k)
		{
			if ((memo[j] && memo[j]->left-- > 0) ||
				tree(root, (char *)s + j, k, memo, j))
			{
				if (++matches == nb_words)
				{
					indices[*n] = i;
					*n += 1;
					break;
				}
			}
			else
				break;
		}
		for (j = 0; j < nb_words; j++)
			nodes[j]->left = nodes[j]->count;
	}
	free_tree(root), free(nodes), free(memo);
	if (*n == 0)
		indices = (free(indices), NULL);
	return (indices);
}

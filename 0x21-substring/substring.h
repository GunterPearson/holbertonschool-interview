#ifndef _SUBSTRING_H
#define _SUBSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define INDEX(x) ((x) - 'a')

/**
 * struct Tree - trie struct
 * @children: array of child nodes
 * @word: 1 if word
 * @count: instances
 * @left: instances left
 * @val: pointer
 */
typedef struct Tree
{
	struct Tree *children[26];
	int word;
	int count;
	int left;
	char *val;
} Tree;

int *find_substring(char const *s, char const **words, int nb_words, int *n);
#endif

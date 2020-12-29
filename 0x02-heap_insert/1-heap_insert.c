#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * len_nodes - count nodes
 * @root: double pointer
 *
 * Return: number of nodes
 */
int len_nodes(heap_t *root)
{
	int n;

	if (root == NULL)
		return (0);
	if (root)
		n = 1;
	n += len_nodes(root->left);
	n += len_nodes(root->right);

	return (n);
}

/**
 * check - function that checks tree
 * @tree: pointer to the root
 * Return: 1 or 0 based on result
 */

int check(const heap_t *tree)
{
	int p1, p2;

	if (tree == NULL)
		return (0);
	p1 = len_nodes(tree->left);
	p2 = len_nodes(tree->right);
	if (p1 == p2)
		return (1);
	return (0);
}

/**
 * parent - find the parent node
 * @root: double pointer
 *
 * Return: a pointer to the parent node
 */
heap_t *parent(heap_t *root)
{
	heap_t *p;
	int l, r, lf, rf;

	if (root == NULL)
		return (NULL);

	p = root;
	l = len_nodes(p->left);
	r = len_nodes(p->right);
	lf = check(p->left);
	rf = check(p->right);

	if (!l || !r)
		return (p);
	if (!lf || (lf && rf && l == r))
		return (parent(p->left));
	else if (!rf || (lf && rf && l > r))
		return (parent(p->right));
	return (p);
}

/**
 * sort - sort a child and a parent node
 * @new: inserted node
 *
 * Return: nothing
 */
void sort(heap_t **new)
{
	heap_t *current;
	int aux;

	current = *new;
	while (current->parent)
	{
		if (current->parent->n < current->n)
		{
			aux = current->parent->n;
			current->parent->n = current->n;
			current->n = aux;
			*new = current->parent;
		}
		current = current->parent;
	}
}
/**
 * heap_insert - inserts a value into Heap
 * @root: double pointer
 * @value: value
 *
 * Return: a pointer to the new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *p;

	p = parent(*root);
	new = binary_tree_node(p, value);
	if (new == NULL)
		return (NULL);
	if (p == NULL)
		*root = new;
	else if (!(p->left))
		p->left = new;
	else
		p->right = new;
	sort(&new);
	return (new);
}

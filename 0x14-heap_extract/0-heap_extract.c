#include "binary_trees.h"

/**
 * _height - height of a binary tree
 * @tree: Pointer
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_left;
	size_t height_right;

	height_left = tree->left ? 1 + _height(tree->left) : 0;
	height_right = tree->right ? 1 + _height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}

/**
 * traverse - traverse through binary tree
 * @root: pointer root
 * @node: pointer node
 * @h: height of tree
 * @l: layer on the tree
 **/
void traverse(heap_t *root, heap_t **node, size_t h, size_t l)
{
	if (!root)
		return;
	if (h == l)
		*node = root;
	l++;
	if (root->left)
		traverse(root->left, node, h, l);
	if (root->right)
		traverse(root->right, node, h, l);
}

/**
 * _sorting - binary tree Heapsort
 * @temp: pointer to the heap root
 * Return: pointer to last node
 **/
heap_t *_sorting(heap_t *temp)
{
	int aux;

	while (temp->left || temp->right)
	{
		if (!temp->right || temp->left->n > temp->right->n)
		{
			aux = temp->n;
			temp->n = temp->left->n;
			temp->left->n = aux;
			temp = temp->left;
		}
		else if (!temp->left || temp->left->n < temp->right->n)
		{
			aux = temp->n;
			temp->n = temp->right->n;
			temp->right->n = aux;
			temp = temp->right;
		}

	}
	return (temp);
}

/**
 * heap_extract - extracts the root
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *aux, *node;

	if (!root || !*root)
		return (0);
	aux = *root;
	value = aux->n;
	if (!aux->left && !aux->right)
	{
		*root = NULL;
		free(aux);
		return (value);
	}
	traverse(aux, &node, _height(aux), 0);
	aux = _sorting(aux);
	aux->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (value);
}

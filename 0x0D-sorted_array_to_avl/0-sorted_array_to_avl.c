#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds AVL tree
 * @array: pointer
 * @size: number of elements
 *
 * Return: pointer to the root or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	int check = 0;

	if (array == NULL || size < 1)
		return (NULL);

	check = add_node(array, size, &tree, 1);
	if (check)
	{
		free_avl(&tree);
		return (NULL);
	}

	return (tree);
}


/**
 * add_node - builds tree from sorted
 * @array: pointer
 * @size: number of elements
 * @tree: double pointer
 * @add_left: flag
 *
 * Return: 0 or -1
 */
int add_node(int *array, size_t size, avl_t **tree, int add_left)
{
	size_t half = (size - 1) / 2;
	avl_t *new = NULL;
	int check = 0;

	if (array == NULL || size < 1)
		return (0);
	new = malloc(sizeof(avl_t));
	if (new == NULL)
		return (-1);
	new->n = array[half];
	new->parent = (*tree);
	new->left = NULL;
	new->right = NULL;
	if ((*tree) == NULL)
		(*tree) = new;
	else if (add_left)
		(*tree)->left = new;
	else
		(*tree)->right = new;
	check = add_node(array, half, &new, 1);
	if (check == -1)
		return (-1);
	half++;
	check = add_node(&array[half], size - half, &new, 0);
	if (check == -1)
		return (-1);
	return (0);
}

/**
 * free_avl - free tree
 * @tree: double pointer
 */
void free_avl(avl_t **tree)
{
	avl_t *left = NULL, *right = NULL;

	if (tree == NULL || (*tree) == NULL)
		return;

	left = (*tree)->left;
	right = (*tree)->right;

	free((*tree)->parent);
	free((*tree)->right);
	free((*tree)->left);
	free(*tree);

	free_avl(&left);
	free_avl(&right);
}

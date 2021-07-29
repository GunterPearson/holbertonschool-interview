#ifndef _BINARY_TREE_
#define _BINARY_TREE_

/* INCLUDED LIBRARIES */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/* STRUCTS AND DEFINITIONS */
/* Basic Binary Tree */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

/* AVL Tree */
typedef struct binary_tree_s avl_t;


void binary_tree_print(const binary_tree_t *);
avl_t *sorted_array_to_avl(int *array, size_t size);
int add_node(int *array, size_t size, avl_t **tree, int add_left);
void free_avl(avl_t **tree);

#endif

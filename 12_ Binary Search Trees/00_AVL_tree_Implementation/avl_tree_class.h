#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct avl_tree_node
{
    int val;
    int balance_factor;
    struct avl_tree_node *parent;
    struct avl_tree_node *left;
    struct avl_tree_node *right;
} avl_tree_node;

typedef struct avl_tree
{
    avl_tree_node *root;
} avl_tree;

avl_tree_node *create_a_avl_tree_node(int x);

avl_tree *create_a_avl_tree(int root_data);

avl_tree_node * rotation(avl_tree_node *root);

int height_of_avl_tree(avl_tree_node *root);

avl_tree_node *insert_into_avl_tree(int x, avl_tree_node *root, avl_tree_node *parent);

avl_tree_node *delete_a_avl_tree_node(int x, avl_tree_node *root);

void print_avl_tree(avl_tree_node *root);
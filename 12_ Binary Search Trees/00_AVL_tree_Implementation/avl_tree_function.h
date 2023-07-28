#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "avl_tree_class.h"

avl_tree_node *create_a_avl_tree_node(int x)
{
    avl_tree_node *ans = (avl_tree_node *)malloc(sizeof(avl_tree_node) * 1);
    ans->val = x;
    ans->balance_factor = 0;
    ans->parent = NULL;
    ans->left = NULL;
    ans->right = NULL;
    return ans;
}

avl_tree *create_a_avl_tree(int root_data)
{
    avl_tree *new_tree = (avl_tree *)malloc(sizeof(avl_tree) * 1);
    new_tree->root = create_a_avl_tree_node(root_data);
    new_tree->root->parent = create_a_avl_tree_node(INT_MAX);
    new_tree->root->parent->left=new_tree->root;
    return new_tree;
}

void adjust_avl_tree_val(avl_tree_node *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->parent->left==root)
    {
        // i.e root is left child of the its parent
        if(root->val<root->parent->val)
        {
            adjust_avl_tree_val(root->left);
            adjust_avl_tree_val(root->right);
        }
        else
        {
            int temp=root->val;
            root->val=root->parent->val;
            root->parent->val=temp;
            adjust_avl_tree_val(root->left);
            adjust_avl_tree_val(root->right);
        }
    }
    else if(root->parent->right==root)
    {
        // i.e root is the right child of its parent
        if(root->val>root->parent->val)
        {
            adjust_avl_tree_val(root->left);
            adjust_avl_tree_val(root->right);
        }
        else
        {
            int temp=root->val;
            root->val=root->parent->val;
            root->parent->val=temp;
            adjust_avl_tree_val(root->left);
            adjust_avl_tree_val(root->right);
            
        }
    }
}

avl_tree_node *do_right_rotation(avl_tree_node *root)
{
    avl_tree_node *parent_of_original_root = root->parent;
    avl_tree_node *original_root = root;
    avl_tree_node *original_left_child_of_root = root->left;

    original_root->left = original_left_child_of_root->right;
    if (original_left_child_of_root->right != NULL)
    {
        original_left_child_of_root->right->parent = original_root;
    }

    original_left_child_of_root->right = original_root;
    original_root->parent = original_left_child_of_root;

    original_left_child_of_root->parent = parent_of_original_root;

    parent_of_original_root->balance_factor=height_of_avl_tree(parent_of_original_root->left)-height_of_avl_tree(parent_of_original_root->right);

    original_root->balance_factor=height_of_avl_tree(original_root->left)-height_of_avl_tree(original_root->right);

    original_left_child_of_root->balance_factor=height_of_avl_tree(original_left_child_of_root->left)-height_of_avl_tree(original_left_child_of_root->right);

    return original_left_child_of_root;
}

avl_tree_node *do_left_rotation(avl_tree_node *root)
{
    avl_tree_node *parent_of_original_root = root->parent;
    avl_tree_node *original_root = root;
    avl_tree_node *original_right_child_of_root = root->right;

    original_root->right = original_right_child_of_root->left;
    if (original_right_child_of_root->left != NULL)
    {
        original_right_child_of_root->left->parent = original_root;
    }

    original_right_child_of_root->left = original_root;
    original_root->parent = original_right_child_of_root;

    original_right_child_of_root->parent = root->parent;

    parent_of_original_root->balance_factor=height_of_avl_tree(parent_of_original_root->left)-height_of_avl_tree(parent_of_original_root->right);

    original_root->balance_factor=height_of_avl_tree(original_root->left)-height_of_avl_tree(original_root->right);

    original_right_child_of_root->balance_factor=height_of_avl_tree(original_right_child_of_root->left)-height_of_avl_tree(original_right_child_of_root->right);

    return original_right_child_of_root;
}

avl_tree_node *rotation(avl_tree_node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if (root->balance_factor == -1 || root->balance_factor == 0 || root->balance_factor == 1)
    {
        return root;
        // as the root is already balanced
    }
    if (root->balance_factor == 2 && (root->left != NULL && (root->left->balance_factor == 1 || root->left->balance_factor == 0)))
    {
        return do_right_rotation(root);
    }
    if (root->balance_factor == -2 && (root->right != NULL && root->right->balance_factor == -1 || root->right->balance_factor == 0))
    {
        return do_left_rotation(root);
    }
    if (root->balance_factor == 2 && (root->left != NULL && root->left->balance_factor == -1))
    {
        root->left=do_left_rotation(root->left);
        return do_right_rotation(root);
    }
    if (root->balance_factor == -2 && (root->right != NULL && root->right->balance_factor == 1))
    {
        root->right=do_right_rotation(root->right);
        return do_left_rotation(root);
    }
    return root;
}

int height_of_avl_tree(avl_tree_node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height_of_avl_tree(root->left);
    int rheight = height_of_avl_tree(root->right);
    if (lheight > rheight)
    {
        return 1 + lheight;
    }
    else
    {
        return 1 + rheight;
    }
}

avl_tree_node *insert_into_avl_tree(int x, avl_tree_node *root, avl_tree_node *parent)
{
    if (root == NULL)
    {
        avl_tree_node *new_node = create_a_avl_tree_node(x);
        new_node->parent = parent;
        return new_node;
    }
    if (root->val < x)
    {
        root->right = insert_into_avl_tree(x, root->right, root);
        root->balance_factor = height_of_avl_tree(root->left) - height_of_avl_tree(root->right);
        root=rotation(root);
        adjust_avl_tree_val(root);
        return root;
    }
    else if (root->val > x)
    {
        root->left = insert_into_avl_tree(x, root->left, root);
        root->balance_factor = height_of_avl_tree(root->left) - height_of_avl_tree(root->right);
        root=rotation(root);
        adjust_avl_tree_val(root);
        return root;
    }
}

int inorder_successor(avl_tree_node *root)
{
    if (root->left == NULL)
    {
        return root->val;
    }
    return inorder_successor(root->left);
}

avl_tree_node *delete_a_avl_tree_node(int x, avl_tree_node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->val == x)
    {
        // CASE 1 WHEN THE NODE TO BE DELETED HAS NO LEFT AND RIGHT SUBTREE
        return NULL;
    }
    if (root->left != NULL && root->right == NULL && root->val == x)
    {
        // CASE 2.a WHEN THE NODE TO BE DELETED HAS ONLY LEFT SUBTREE AND NO RIGHT SUBTREE
        root->left->parent = root->parent;
        avl_tree_node *temp = root->left;
        return temp;
    }
    if (root->left == NULL && root->right != NULL && root->val == x)
    {
        // CASE 2.B WHEN THE NODE TO BE DELETED HAS NO LEFT SUBTREE AND HAS ONLY RIGHT SUBTREE
        root->right->parent = root->parent;
        avl_tree_node *temp = root->right;
        return temp;
    }
    if (root->left != NULL && root->right != NULL && root->val == x)
    {
        // CASE 3 WHEN THE RIGHT AND THE LEFT SUBTREE OF THE NODE TO BE DELETED ARE NOT NULL
        int inorder_successor_val = inorder_successor(root->right);
        avl_tree_node *helper = delete_a_avl_tree_node(inorder_successor_val, root);
        root->val = inorder_successor_val;
        root->balance_factor = height_of_avl_tree(root->left) - height_of_avl_tree(root->right);
        root=rotation(root);
        return root;
    }

    if (root->val < x)
    {
        root->right = delete_a_avl_tree_node(x, root->right);
        root->balance_factor = height_of_avl_tree(root->left) - height_of_avl_tree(root->right);
        root=rotation(root);
        adjust_avl_tree_val(root);
        return root;
    }
    if (root->val > x)
    {
        root->left = delete_a_avl_tree_node(x, root->left);
        root->balance_factor = height_of_avl_tree(root->left) - height_of_avl_tree(root->right);
        root=rotation(root);
        adjust_avl_tree_val(root);
        return root;
    }
}

void printCurrentLevel(avl_tree_node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        printf("Node value : %d .\n Parent value : %d.\nBalance factor of node : %d.\n\n", root->val, root->parent->val, root->balance_factor);
        return;
    }
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void print_avl_tree(avl_tree_node *root)
{
    // prints level order traversal of tree
    int h = height_of_avl_tree(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
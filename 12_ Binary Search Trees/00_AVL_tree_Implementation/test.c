#include "avl_tree_function.h"

int main()
{
    int root_data;
    printf("Enter the value of the root data : ");
    scanf("%d", &root_data);
    avl_tree *my_tree = create_a_avl_tree(root_data);
    avl_tree_node *root = my_tree->root;
    printf("\nThe avl tree with root node value %d has been created.\n",root_data);
    int choice = 1;

    while (choice != -1)
    {
        printf("\n-> Enter 1 to insert a single value in the avl tree.\n-> Enter 2 to insert a list of values of in the avl tree.\n-> Enter 3 to delete a single value from the avl tree.\n-> Enter 4 to delete a list of values from the avl tree.\n-> Enter 5 to display the levelorder traversal of the tree\n->Enter -1 to exit the program.\n#YOUR CHOICE : ");
        scanf("%d", &choice);

        if (choice == 1)
        { // TO INSERT A SINGLE VALUE IN THE AVL TREE
            int num;
            printf("\nEnter the value to be inserted : ");
            scanf("%d", &num);
            root = insert_into_avl_tree(num, root, root->parent);
            printf("\nThe value %d inserted succesfully into the avl tree\n", num);
        }

        else if (choice == 2)
        { // TO INSERT A LIST OF VALUES IN THE AVL TREE
            int n;
            printf("\nEnter the number of values you want to insert in the avl tree : ");
            scanf("%d", &n);
            int arr[n];
            printf("\nEnter all the values that you want to insert in the avl tree : ");
            for (int i = 0; i < n; i += 1)
            {
                scanf("%d", &arr[i]);
            }
            for (int i = 0; i < n; i += 1)
            {
                root = insert_into_avl_tree(arr[i], root, root->parent);
                printf("\nThe value %d inserted succesfully into the avl tree", arr[i]);
            }
            printf("\n");
        }

        else if (choice == 3)
        { // TO DELETE A SINGLE VALUE FROM THE AVL TREE
            int num;
            printf("\nEnter the value to be deleted : ");
            scanf("%d", &num);
            root = delete_a_avl_tree_node(num, root);
            printf("\nThe value %d deleted succesfully from the avl tree\n", num);
        }

        else if (choice == 4)
        { // TO DELETE A LIST OF VALUES FROM THE AVL TREE
            int n;
            printf("\nEnter the number of values you want to delete from the avl tree : ");
            scanf("%d", &n);
            int arr[n];
            printf("\nEnter all the values that you want to delete from the avl tree : ");
            for (int i = 0; i < n; i += 1)
            {
                scanf("%d", &arr[i]);
            }
            for (int i = 0; i < n; i += 1)
            {
                root = delete_a_avl_tree_node(arr[i], root);
                printf("\nThe value %d deleted succesfully from the avl tree", arr[i]);
            }
            printf("\n");
        }

        else if (choice == 5)
        { // PRINTING LEVEL ORDER TRAVERSAL OF THE TREE
            printf("\nThe level order traversal of the given avl tree is as follows : \n");
            print_avl_tree(root);
            printf("\n");
        }

        else
        {
            if (choice != -1)
            {
                printf("\nYou entered the invalid choice. Please try again.\n");
            }
        }
    }
    return 0;
}

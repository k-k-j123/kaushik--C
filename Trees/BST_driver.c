#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
int main()
{
    int val, key, choice;
    struct node *root = NULL;
    do
    {
        printf("\nmenu\n");
        printf("\n1)create\n2)insert\n3)preorder\n4)inorder\n5)preorder\n6)search\n7)count nodes\n8)count leaf nodes\n9)Delete node\n99)exit");
        printf("\nenter your choice\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = create(root);
            break;
        case 2:
            printf("\nenter the node value to be inserted\t");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 3:
            printf("\npreorder traversal is\t");
            preorder(root);
            break;
        case 4:
            printf("\ninorder traversal is\t");
            Inorder(root);
            break;
        case 5:
            printf("postorder traversal is\t");
            postorder(root);
            break;
        case 6:
            printf("\nenter the element to search\t");
            scanf("%d", &key);
            root = search(root, key);
            break;
        case 7:
            printf("\nnumber of nodes are\t%d",countnodes(root));
            break;
        case 8:
             printf("\nnumber of nodes are\t%d",countleaf(root));
             break;
        case 9:
            printf("\nenter the key value to be deleted\n");
            scanf("%d",&key);
            delete(root,key);
            break;
        }
    } while (choice != 99);

    return 0;
}
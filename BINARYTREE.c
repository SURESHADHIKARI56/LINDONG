/*BINARY SEARCH TREE
NAME:LINDONG
DATE:02/02/2026
FILENAME:HAIBODONG.C
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeType
{
    int data;
    struct TreeType *left;
    struct TreeType *right;
} TREENODE;
TREENODE *Root = NULL;
void InsertNode(int x)
{
    TREENODE *prev, *cur, *Node;
    Node = (TREENODE *)malloc(sizeof(TREENODE));
    Node->data = x;
    Node->left = NULL;
    Node->right = NULL;
    /*if there is no tree make incoming node(s)as the root of the tree */
    if (Root == NULL)
    {
        Root = Node;
        return;
    }
    cur = Root;
    while (cur != NULL)
    {
        prev = cur;
        if (x < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (x < prev->data)
        prev->left = Node;
    else
        prev->right = Node;
}
void Inorder(TREENODE *Root)
{
    if (Root)
    {
        Inorder(Root->left);
        printf("%d ", Root->data);
        Inorder(Root->right);
    }
}
void Preorder(TREENODE *Root)
{
    if (Root)
    {
        printf("%d ", Root->data);
        Preorder(Root->left);
        Preorder(Root->right);
    }
}
void Postorder(TREENODE *Root)
{
    if (Root)
    {
        Postorder(Root->left);
        Postorder(Root->right);
        printf("%d ", Root->data);
    }
}
void leafnode(TREENODE *Root)
{
    if (Root)
    {
        if (Root->left == NULL && Root->right == NULL)
            printf("%d ", Root->data);
        leafnode(Root->left);
        leafnode(Root->right);
    }
}
int searchdata(int x, int *pos)
{
    TREENODE *cur = Root;
    *pos = 1;

    while (cur != NULL)
    {
        if (x == cur->data)
            return 1;

        else if (x < cur->data)
            cur = cur->left;
        else
            cur = cur->right;

        (*pos)++;
    }
    return -1;
}

int main()
{
    int choice, x, found, pos;
    Root = NULL;
    while (1)
    {
        printf("1.Insert Node\n");
        printf("2.Inorder Traversal\n");
        printf("3.Preorder Traversal\n");
        printf("4.Postorder Traversal\n");
        printf("5.Display LeafTree\n");
        printf("6.Search Data\n");
        printf("7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int i, n;
            printf("enter number of elements to insert:");
            scanf("%d", &n);
            printf("Enter %d elements:\n", n);
            for (i = 0; i < n; i++)
            {
                printf("Enter data to insert: ");
                scanf("%d", &x);
                InsertNode(x);
            }
            break;
        }
        case 2:
            printf("Inorder Traversal: ");
            Inorder(Root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal: ");
            Preorder(Root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal: ");
            Postorder(Root);
            printf("\n");
            break;
        case 5:
            printf("Leaf Nodes: ");
            leafnode(Root);
            printf("\n");
            break;
        case 6:
            printf("Enter data to search: ");
            scanf("%d", &x);

            found = searchdata(x, &pos);

            if (found == -1)
                printf("Data %d not found in the tree.\n", x);
            else
                printf("Data %d found at position (level) %d.\n", x, pos);
            break;

        case 7:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    struct node *left;
    int data;
    struct node *right;
};

typedef struct node* Node;  //Creates Alias for "Struct node*"

// Function to create a new node
Node newNode(int item) {
    Node temp = (Node)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node in the BST
Node insert(Node node, int key) {
    if (node == NULL)
        return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

// Function to search for a key in the BST
int search(Node root, int key) {
    if (root == NULL)
        return -1;
    if (root->data == key)
        return 1;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left,key);
}

// Inorder traversal
void inorder(Node root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(Node root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(Node root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

// Main function
int main() {
    int ch, ch1, key, pos;
    Node root = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1: Insert Node\n");
        printf("2: Traversal\n");
        printf("3: Search for Key\n");
        printf("4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;

            case 2:
                if (root == NULL) {
                    printf("BST is empty. No elements to traverse.\n");
                } else {
                    printf("Traversal Options:\n");
                    printf("1: Preorder\n");
                    printf("2: Inorder\n");
                    printf("3: Postorder\n");
                    printf("Enter your choice: ");
                    scanf("%d", &ch1);
                    switch (ch1) {
                        case 1:
                            printf("Preorder Traversal: ");
                            preorder(root);
                            printf("\n");
                            break;
                        case 2:
                            printf("Inorder Traversal: ");
                            inorder(root);
                            printf("\n");
                            break;
                        case 3:
                            printf("Postorder Traversal: ");
                            postorder(root);
                            printf("\n");
                            break;
                        default:
                            printf("Invalid choice for traversal\n");
                    }
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("BST is empty. No elements to search.\n");
                } else {
                    printf("Enter the key to be searched: ");
                    scanf("%d", &key);
                    pos = search(root, key);
                    if (pos == -1)
                        printf("Key is not found\n");
                    else
                        printf("Key is found\n");
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
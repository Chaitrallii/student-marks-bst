#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student node
struct Node {
    int roll;
    char name[50];
    int marks;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int roll, char name[], int marks) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->marks = marks;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int roll, char name[], int marks) {
    if (root == NULL)
        return createNode(roll, name, marks);

    if (roll < root->roll)
        root->left = insert(root->left, roll, name, marks);
    else
        root->right = insert(root->right, roll, name, marks);

    return root;
}

// Search in BST
struct Node* search(struct Node* root, int roll) {
    if (root == NULL || root->roll == roll)
        return root;

    if (roll < root->roll)
        return search(root->left, roll);

    return search(root->right, roll);
}

// Inorder traversal (sorted output)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Roll: %d | Name: %s | Marks: %d\n",
               root->roll, root->name, root->marks);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, roll, marks;
    char name[50];

    do {
        printf("\n--- Student Marks BST ---\n");
        printf("1. Insert\n2. Search\n3. Display (Sorted)\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &roll);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Marks: ");
                scanf("%d", &marks);

                root = insert(root, roll, name, marks);
                printf("Student added successfully!\n");
                break;

            case 2:
                printf("Enter Roll Number to search: ");
                scanf("%d", &roll);

                struct Node* result = search(root, roll);
                if (result != NULL)
                    printf("Found -> Name: %s, Marks: %d\n",
                           result->name, result->marks);
                else
                    printf("Student not found.\n");
                break;

            case 3:
                printf("\nSorted Student Records:\n");
                inorder(root);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
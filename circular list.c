#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the list is empty
int isEmpty(struct Node* head) {
    return head == NULL;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

// Function to insert a node after a specific node
void insertAfterNode(struct Node* head, int nodeData, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        printf("List is empty. Cannot perform insertion.\n");
        return;
    }
    struct Node* current = head;
    do {
        if (current->data == nodeData) {
            newNode->next = current->next;
            current->next = newNode;
            if (current == head) {
                head = newNode;
            }
            return;
        }
        current = current->next;
    } while (current != head);
    printf("Node with data %d not found.\n", nodeData);
}

// Function to delete a node from the list
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty. Cannot perform deletion.\n");
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current->data != data) {
        if (current->next == *head) {
            printf("Node with data %d not found.\n", data);
            return;
        }
        prev = current;
        current = current->next;
    }
    if (current == *head && current->next == *head) {
        *head = NULL;
        free(current);
        return;
    }
    if (current == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = current->next;
        prev->next = *head;
    } else if (current->next == *head) {
        prev->next = *head;
    } else {
        prev->next = current->next;
    }
    free(current);
}

// Function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 4);
    insertAfterNode(head, 2, 5);
    deleteNode(&head, 4);
    display(head);

    return 0;
}

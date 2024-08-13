#include <stdio.h>
#include <stdlib.h>
Struct Node {
    Int data;
    Struct Node* next;
};
Struct Node* createNode(int data) {
    Struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Void printList(struct Node* head) {
    Struct Node* temp = head;
    While (temp != NULL) {
        Printf(“%d -> “, temp->data);
        Temp = temp->next;
    }
    Printf(“NULL\n”);
}
Void insertAtBeginning(struct Node** head, int data) {
    Struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
Void deleteAtEnd(struct Node** head) {
    If (*head == NULL || (*head)->next == NULL) {
        If (*head != NULL) {
            Free(*head);
            *head = NULL;
        }
        Return;
    }

    Struct Node* temp = *head;
    While (temp->next->next != NULL) {
        Temp = temp->next;
    }
    Free(temp->next);
    Temp->next = NULL;
}
Void insertMiddle(struct Node** head, int data) {
    Struct Node* newNode = createNode(data);
    If (*head == NULL) {
        *head = newNode;
        Return;
    }

    Struct Node* slow = *head;
    Struct Node* fast = *head;
    Struct Node* prev = NULL;
    While (fast != NULL && fast->next != NULL) {
        Prev = slow;
        Slow = slow->next;
        Fast = fast->next->next;
    }
    newNode->next = slow;
    if (prev != NULL) {
        prev->next = newNode;
    } else {
        *head = newNode;
    }
}
Void deleteMiddle(struct Node** head) {
    If (*head == NULL || (*head)->next == NULL) {
        If (*head != NULL) {
            Free(*head);
            *head = NULL;
        }
        Return;
    }

    Struct Node* slow = *head;
    Struct Node* fast = *head;
    Struct Node* prev = NULL;
    While (fast != NULL && fast->next != NULL) {
        Prev = slow;
        Slow = slow->next;
        Fast = fast->next->next;
    }
    Prev->next = slow->next;
    Free(slow);
}
Int main() {
    Struct Node* head = NULL;
    Head = createNode(1);
    Head->next = createNode(2);
    Head->next->next = createNode(3);
    Head->next->next->next = createNode(4);
    Head->next->next->next->next = createNode(5);
    Printf(“Original list:\n”);
    printList(head);
    insertAtBeginning(&head, 0);
    printf(“List after inserting 0 at the beginning:\n”);
    printList(head);
    deleteAtEnd(&head);
    printf(“List after deleting the last node:\n”);
    printList(head);
    insertMiddle(&head, 99);
    printf(“List after inserting 99 in the middle:\n”);
    printList(head);
    deleteMiddle(&head);
    printf(“List after deleting the middle node:\n”);
    printList(head);

    return 0;
}

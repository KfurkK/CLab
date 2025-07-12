#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


int main() {
    // create a stack with 5 nodes
    struct Node *topPtr1 = createStack(5); // topPtr1 is head of the stack
    int count = countNodes(topPtr1);
    printf("The stack has {%d} nodes\n", count);

    // see one of the node's value
    printf("Value of the top node: %d\n",topPtr1->value);


    // create a stack with 3 nodes
    struct Node *topPtr2 = createStack(3); // topPtr1 is head of the stack

    int count2 = countNodes(topPtr2);
    printf("The stack has {%d} nodes\n", count2);

    // see one of the node's value
    printf("Value of the top node: %d\n",topPtr2->value);


    // combine two stacks
    topPtr1 = pushStack(&topPtr1, &topPtr2);
    printf("Number of nodes in the updated stack: %d\n", countNodes(topPtr1));

    topPtr1 = sortStack(&topPtr1);
    printStackValues(topPtr1);

    freeStack(topPtr1);

    return 0;

}

int pop(struct Node **topPtr) {
    struct Node *temp = *topPtr;
    int val = temp->value;
    *topPtr = (*topPtr)->next;
    free(temp);
    return val;
}

void push(struct Node **topPtr, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = *topPtr;
    *topPtr = newNode;
}

// count number of nodes
int countNodes(struct Node *top) {
    struct Node *temp = top;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;

    }
    return count;
}

void freeStack(struct Node *top) {
    while (top != NULL) {
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }
}

void printStackValues(struct Node *top) {
    struct Node *temp = top;
    printf("Sorted: ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

struct Node * sortStack(struct Node **topPtr) {
    if (*topPtr == NULL || (*topPtr)->next == NULL)
        return *topPtr;

    struct Node *endPtr = NULL;
    int t;
    bool swapped;

    do {
        struct Node *temp = *topPtr;
        swapped = false;
        while (temp->next != endPtr) {
            int value = temp->value;
            if (value > temp->next->value) {
                // swapping...
                t = temp->value ;
                temp -> value = temp->next->value;
                temp->next->value = t;
                swapped = true;
            }
            temp = temp->next;
        }
        endPtr = temp; // exclude the largest element which is positioned correctly

        } while (swapped); // if no swapping occurs don't try to sort
    return *topPtr;
}

struct Node * pushStack(struct Node **stack1, struct Node **stack2) {

    /*
     * Performs combining two stacks by making the last node of the first stack
     * to point the top of the second stack.
     */

    // jump to the last node
    struct Node * temp = *stack1;

    while (temp->next != NULL) {
        temp = temp->next;

    } // now temp points to the last node of the stack
    temp->next = *stack2;

    return *stack1;
}

struct Node * createStack(int nodeCount) {
    // Allocate mem for top node

    struct Node *temp = NULL;
    for (int i = 0; i < nodeCount; i++) {
        push(&temp, i); // temp is updated internally
    }

    return temp; // temp is basically head now
}


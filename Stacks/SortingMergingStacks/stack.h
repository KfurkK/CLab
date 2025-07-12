#ifndef STACK_H
#define STACK_H

struct Node {
    int value; // 4 bytes
    struct Node *next; // 8 bytes
    // -> 12 bytes total
};


int pop(struct Node **topPtr);
void push(struct Node **topPtr, int value);
struct Node * createStack(int nodeCount);
int countNodes(struct Node *top);
struct Node * pushStack(struct Node **stack, struct Node **stac);
void freeStack(struct Node *top);
struct Node * sortStack(struct Node **topPtr);
void printStackValues(struct Node *top);


#endif //STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStr {
    int value;
    struct NodeStr *next_node;
    struct NodeStr *prev_node;
} Node;

typedef struct Stack {
    Node *tail;
    int length;
} Stack;

// add new element to the stack
Node* push(Stack *stack, int value);
// remove last element from stack
Node* pop(Stack *stack);
// check pop
int peek(Stack *stack);
int get_length(Stack *stack);
void print_stack(Stack *stack);
void free_stack(Stack *stack);


Stack* initialize_stack() {
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->tail = NULL;
    stack->length = 0;
    return stack;
}

Node* push(Stack *stack, int value) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL;
    }
    
    new_node->value = value;
    new_node->next_node = NULL;
    new_node->prev_node = stack->tail;
    
    if (stack->tail != NULL) {
        stack->tail->next_node = new_node;
    }
    
    stack->tail = new_node;
    stack->length++;
    
    return new_node;
}

Node *pop(Stack *stack) {
    if (stack->tail == NULL) {
        return NULL;
    }
    
    Node *node = stack->tail;
    int value = node->value;
    
    stack->tail = node->prev_node;
    if (stack->tail != NULL) {
        stack->tail->next_node = NULL;
    }
    
    stack->length--;
    free(node);
    
    return value;
}

int peek(Stack *stack) {
    if (stack->tail == NULL) {
        return;
    }
    return stack->tail->value;
}

int get_length(Stack *stack) {
    return stack->length;
}

void print_stack(Stack *stack) {
    Node *node = stack->tail;
    while (node != NULL) {
        printf("(%d) -> ", node->value);
        node = node->prev_node;
    }
    printf("End; length = %d\n", stack->length);
}

void free_stack(Stack *stack) {
    Node *node = stack->tail;
    while (node != NULL) {
        Node *prev = node->prev_node;
        free(node);
        node = prev;
    }
    free(stack);
}

int main() {
    Stack *stack = initialize_stack();

    printf("\n____push 4____\n");
    push(stack, 5);
    push(stack, 9);
    push(stack, 3);
    push(stack, 7);
    print_stack(stack);

    printf("Length = %d\n", get_length(stack));
    printf("Peek = %d\n", peek(stack));

    printf("\n____pop 1____\n");
    int value = pop(stack);
    printf("Pop = %d\n", value);
    print_stack(stack);

    printf("Length = %d\n", get_length(stack));

    free_stack(stack);
}
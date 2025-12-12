#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStr {
    int value;
    struct NodeStr *next_node;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
    int length;
} Queue;

Queue* initialize_queue() {
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->length = 0;
    return queue;
}

Node* enqueue(Queue *queue, int value) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->value = value;
    new_node->next_node = NULL;

    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next_node = new_node;
        queue->tail = new_node;
    }

    queue->length++;
    return new_node;
}

Node* dequeue(Queue *queue) {
    if (queue->head == NULL) {
        return NULL;
    }

    Node *node = queue->head;
    queue->head = node->next_node;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    queue->length--;

    return node;
}

void print_queue(Queue *queue) {
    Node *node = queue->head;
    while (node != NULL) {
        printf("(%d) -> ", node->value);
        node = node->next_node;
    }
    printf("End; length = %d\n", queue->length);
}

int peek(Queue *queue) {
    if (queue->head == NULL) {
        return;
    }
    return queue->head->value;
}

int get_length(Queue *queue) {
    return queue->length;
}

void free_queue(Queue *queue) {
    Node *node = queue->head;
    while (node != NULL) {
        Node *next = node->next_node;
        free(node);
        node = next;
    }
    free(queue);
}

int main() {
    Queue *queue = initialize_queue();
    
    printf("\n____add 3 queue____\n");
    enqueue(queue, 5);
    enqueue(queue, 9);
    enqueue(queue, 3);
    print_queue(queue);

    printf("Length = %d\n", get_length(queue));
    printf("Peek = %d\n", peek(queue));

    printf("\n____xoa dau____\n");
    Node *node = dequeue(queue); 
    printf("Dequeue = %d\n", node->value);
    free(node);
    print_queue(queue);

    printf("Length = %d\n", get_length(queue));
    free_queue(queue);
}
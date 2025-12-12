#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStr {
    int value;
    struct NodeStr *next_node;
    struct NodeStr *prev_node;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
    int length;
} List;

List* intitialize_list () {
    List *list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    } 
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;   
    return list;
}

Node* intitialize_node (int value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    } 
    node->value = value;
    node->next_node = NULL;
    node->prev_node = NULL;
    return node;
}

int get_length(List *list) {
    return list->length;
}

Node* add_node (List *list, int value) {
    Node *new_node = intitialize_node (value);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->prev_node = list->tail;
        list->tail->next_node = new_node;
        list->tail = new_node;
    }
    list->length++;
    return new_node;
}

Node *add_node_at(List *list, int value, int index) {
    if (index < 0 || index > list->length) {
        return NULL;
    }

    Node *new_node = intitialize_node(value);
    int count = 0;
    Node *node = list->head;

    while (node != NULL && count != index) {
        count++;
        node = node->next_node;
    }

    Node *prev = node->prev_node;

    prev->next_node = new_node;
    new_node->prev_node = prev;

    new_node->next_node = node;
    node->prev_node = new_node;

    list->length++;
    return new_node;
}

void print_list(List *list) {
    Node *node = list->head;
    while (node != NULL) {
        printf("(%d) <-> ", node->value);
        node = node->next_node;
    }
    printf("End; length = %d\n", list->length);
}

Node* get_node(List* list, int index) {
    int count = 0;
    Node *node = list->head;
    while (node != NULL && count != index) {
        count++;
        node = node->next_node;
    }
    return node;
}

void remove_head(List* list) {
    if (list->length == 0) {
        return;
    }
    Node *node = list->head;
    list->length--;
    list->head = node->next_node;
    if (node == list->tail) {
        list->tail = NULL;
    }
    free(node);
}

void remove_node(List *list, int value) {
    Node *node = list->head;
    while (node != NULL && node->value != value) {
        node = node->next_node;
    }

    if (node == NULL) {
        return;
    }

    if (node->prev_node == NULL) {
        remove_head(list);
    } else {
        list->length--;
        node->prev_node->next_node = node->next_node;
        node->next_node->prev_node = node->prev_node;
        free(node);
    }
}

void remove_at(List* list, int index) {
    if (index < 0 || index >= list->length) {
        return;
    }

    int i = 0;
    Node *node = list->head;

    while (node != NULL && i != index) {
        i++;
        node = node->next_node;
    }

    if (node == NULL) {
        return;
    }

    if (i == 0) {
        remove_head(list);
    } else {
        list->length--;
        node->prev_node->next_node = node->next_node;
        node->next_node->prev_node = node->prev_node;
        free(node);
    }
}
    
void remove_tail(List* list) {
    if (list->tail == NULL) {
	    return;
    }
    Node *prev = list->tail->prev_node;
    free(list->tail);
    if (prev == NULL) {
	    list->head = NULL;
        list->tail = NULL;
    } else {
	    prev->next_node = NULL;
	    list->tail = prev;
    }
    list->length--;
}

void free_list(List *list) {
    Node *node = list->head;
    Node *next = NULL;
    while (node != NULL) {
        next = node->next_node;
        free(node);
        node = next;
    }
    free(list);
}

int main() {
    List *list = intitialize_list();
    print_list(list);

    printf("\n____add 2 nodes____\n");
    add_node(list, 5);
    add_node(list, 9);
    print_list(list);

    printf("\n____romove index 0____\n");
    remove_at(list, 0);
    print_list(list);

    printf("\n____add 5 nodes____\n");
    add_node(list, 3);
    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 7);
    add_node(list, 0);
    print_list(list);
    
    printf("\n____remove node value = 3____\n");
    remove_node(list, 3);
    print_list(list);

    Node *m = get_node(list, 2);
    printf("List[%d] = %d\n",2 , m->value);
    
    printf("\n____remove node value = 2____\n");
    remove_node(list, 2);   
    print_list(list);

    printf("\n____remove node at index 2____\n");
    remove_at(list, 2);
    print_list(list);

    printf("\n____add node to index 2, value = 1____\n");
    add_node_at(list, 1, 2);
    print_list(list);
    
    free_list(list);
    printf("List pointer = %p\n", list);
    
}
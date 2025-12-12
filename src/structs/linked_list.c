#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStr {
    int value;
    struct NodeStr *next_node;
    
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
    return list;
}

Node* intitialize_node (int value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    } 
    node->value = value;
    node->next_node = NULL;
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

    Node *new_node = intitialize_node (value);

    if (index == 0) {
        new_node->next_node = list->head;
        list->head = new_node;

        if (list->tail == NULL) 
            list->tail = new_node;
        return new_node;
    }

    if (index == list->length) {
        list->tail->next_node = new_node;
        list->tail = new_node;
        return new_node;
    }

    int count = 0;
    Node *node = list->head;
    Node *prev = NULL;
    while (node != NULL && count != index) {
        count++;
        prev = node;
        node = node->next_node;
    }
    if (prev == NULL) {
        prev = node->next_node;
    }
    prev->next_node = new_node;
    new_node->next_node = node;
    list->length++;

    return new_node;
}

void print_list(List *list) {
    Node *node = list->head;
    while (node != NULL) {
        printf("(%d) -> ", node->value);
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
    Node *prev = NULL;
    while (node != NULL && node->value != value) {
        prev = node;
        node = node->next_node;
    }

    if (node == NULL) {
        return;
    }

    if (prev == NULL) {
        remove_head(list);
    } else {
        list->length--;
        prev->next_node = node->next_node;
        free(node);
    }
}

void remove_at(List* list, int index) {
    if (index < 0 || index >= list->length) {
        return;
    }

    int i = 0;
    Node *prev = NULL;
    Node *node = list->head;

    while (node != NULL && i != index) {
        i++;
        prev = node;
        node = node->next_node;
    }

    if (node == NULL) {
        return;
    }

    if (prev == NULL) {
        remove_head(list);
    } else {
        list->length--;
        prev->next_node = node->next_node;
        free(node);
    }
}
    
void remove_tail(List* list) {
    remove_at(list, list->length -1);
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

    printf("\n____add 4 nodes____\n");
    add_node(list, 5);
    // add_node(list, 9);

    print_list(list);
    remove_at(list, 0);
    print_list(list);

    add_node(list, 3);
    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 7);
    add_node(list, 0);
    print_list(list);
    remove_node(list, 3);
    print_list(list);

    Node *m = get_node(list, 2);
    printf("List[%d] = %d\n",2 , m->value);
    
    // remove_node(list, 2);   
    // print_list(list);

    printf("\n____remove node at index 2____\n");
    remove_at(list, 2);
    print_list(list);

    printf("\n____add node to index 2, value = 1____\n");
    add_node_at(list, 1, 2);
    print_list(list);
    
    free_list(list);
    printf("List pointer = %p\n", list);

}
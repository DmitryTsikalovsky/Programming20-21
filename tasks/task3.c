#include <stdlib.h>
#include <stdio.h>

typedef struct Item {
    char data;
    struct Item *next;
} Item;

typedef struct List {
    Item *head;
    Item *tail;
} List;

List *list_new() {
    return (List *) calloc(1, sizeof(List));
}

void list_delete(List *list) {
    Item *ptr = list->head, *ptr_prev;
    while (ptr) {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    free(list);
}

void list_print(const List *list) {
    Item *ptr = list->head;
    while (ptr) {
        printf("%c ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void list_reverse(List *list) {
    Item *ptr;
    Item *ptr_prev = list->head;
    Item *ptr_next = ptr_prev->next;
    list->tail = ptr_prev;
    ptr_prev->next = NULL;
    while(ptr_next){
        ptr = ptr_next;
        ptr_next = ptr_next->next;
        ptr->next = ptr_prev;
        ptr_prev = ptr;
    }
    list->head = ptr_prev;
}
int list_palindrom_search(Item **ptr_head,Item *ptr_tail) {
    int a = 1;
    int p, t;
    if (ptr_tail->next != NULL) {
        a = list_palindrom_search(ptr_head, ptr_tail->next);
    }
    if (a == 0) {
        return 0;
    } else if (a == 3){
        return 3;
    }
    if ((*ptr_head) == ptr_tail) {
        return 3;

    }
    while ((*ptr_head)->data == ' ') {
        *ptr_head = (*ptr_head)->next;
    }
    if (ptr_tail->data == ' ') {
        return a;
    }

    if ( (*ptr_head)->data == ptr_tail->data){
        *ptr_head = (*ptr_head)->next;
        return 1;
    } else {
        return  0;
    }
}

void list_print_reverse(Item *ptr){
    if (ptr != NULL){
        list_print_reverse(ptr->next);
        printf("%c ",ptr->data);
    }
}

//ревёрс с копированием
List *list_reverse_copy(List *list) {
    List *reverse = list_new();
    Item *ptr = list->head;
    Item *ptr_prev;
    Item *ptr_reverse = (Item *) malloc(sizeof(Item));
    ptr_reverse->data = ptr->data;
    ptr_reverse->next = NULL;
    reverse->tail = ptr_reverse;
    ptr_prev = reverse->tail;
    ptr = ptr->next;
    while(ptr){
        Item *ptr_reverse = (Item *) malloc(sizeof(Item));
        ptr_reverse->data = ptr->data;
        ptr_reverse->next = ptr_prev;
        ptr_prev = ptr_reverse;
        ptr = ptr->next;
    }
    reverse->head = ptr_prev;
    return reverse;
}


int list_insert(List *list, char data) {
    Item *ptr = list->head, *ptr_prev = NULL;
    while (ptr) {
        ptr_prev = ptr;
        ptr = ptr->next;
    }
    Item *new = (Item *) malloc(sizeof(Item));
    if (!new) {
        return -1;
    }
    new->data = data;
    new->next = ptr;
    if (ptr_prev) {
        ptr_prev->next = new;
    } else {
        list->head = new;
    }
    if (!ptr) {
        list->tail = new;
    }
    return 0;
}

void list_remove(List *list, int data) {
    Item *ptr = list->head, *ptr_prev = NULL;
    while (ptr && ptr->data != data) {
        ptr_prev = ptr;
        ptr = ptr->next;
    }
    if (!ptr) {
        return;
    }
    if (ptr == list->head) {
        list->head = ptr->next;
    }
    if (ptr == list->tail) {
        list->tail = ptr_prev;
    }
    if (ptr_prev) {
        ptr_prev->next = ptr->next;
    }
    free(ptr);
}

int main() {
    List *l = list_new();
    List *reverse = list_new();
    list_insert(l, 'a');
    list_print(l);
    list_insert(l, 'b');
    list_insert(l, ' ');
    list_print(l);
    list_insert(l, 'c');
    list_print(l);
    list_insert(l, 'a');
    list_print(l);
    list_insert(l, 'c');
    list_print(l);
    list_insert(l, ' ');
    list_insert(l, 'b');
    list_insert(l, 'a');
    list_insert(l, ' ');
    list_print(l);
    list_print_reverse(l->head);
    printf("\n");
    list_reverse(l);
    list_print(l);
    Item *ptr = l->head;
    int a = list_palindrom_search(&ptr,ptr);
    if (a == 3 || a == 1){
        printf("Полиндром! Повезло повезло\n");
    } else {
        printf("Не полиндром :( \n");
    }
    list_print(l);
    list_delete(l);
    return 0;
}
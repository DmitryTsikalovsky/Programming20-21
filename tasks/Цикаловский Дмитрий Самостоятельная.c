#include <stdlib.h>
#include <stdio.h>

typedef struct Item {
    int data;
    struct Item *next;
    struct Item *prev;
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
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int list_push_back(List *list, int data) {
    Item *ptr = (Item *) malloc(sizeof(Item));
    if (!ptr) {
        return -1;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (!list->head) {
        list->head = ptr;
        list->tail = ptr;
    } else {
        ptr->prev = list->tail;
        list->tail->next = ptr;
        list->tail = ptr;
    }
    return 0;
}

int list_insert(List *list, int data) {
    Item *ptr = (Item *) malloc(sizeof(Item));
    if (!ptr) {
        return -1;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (!list->tail) {
        list->head = ptr;
        list->tail = ptr;
    } else {
        list->head->prev = ptr;
        ptr->next = list->head;
        list->head = ptr;
    }
    return 0;
}

void insert_number(List *list, int number, int data) {
    Item *ptr_prev = list->head;
    Item *ptr = (Item *) malloc(sizeof(Item));
    ptr->data = data;
    Item *ptr_next;
    int i = 1;
    while (ptr_prev && i < number) {
        ptr_prev = ptr_prev->next;
        i++;
    }
    if (i == number) {
        ptr->next = ptr_prev->next;
        ptr->prev = ptr_prev;
        ptr_prev->next = ptr;
        if (ptr_prev == list->tail) list->tail = ptr;
    }

}

void delete_number(List *list, int number) {
    Item *ptr = list->head;
    Item *ptr_prev;
    Item *ptr_next;
    int i = 1;
    while (ptr && i < number) {
        ptr = ptr->next;
        i++;
    }
    if (i == number) {
        if (ptr == list->head){
            ptr_next = ptr->next;
            if (ptr_next){
                free(list->head);
                list->head = ptr_next;
                list->head->prev = NULL;
            }
        } else if (ptr == list->tail){
            ptr_prev = ptr->prev;
            if (ptr_prev ) {
                free(list->tail);
                list->tail = ptr_prev;
            }
        } else {
            ptr_next = ptr->next;
            ptr_prev = ptr->prev;
            free(ptr);
            ptr_prev->next = ptr_next;
            ptr_next->prev = ptr_prev;
        }

    }

}
void list_concatinate(List *listmain,List *list2){
    if (listmain){
        Item *ptr = listmain->tail;
        list2->head->prev = ptr;
        ptr->next= list2->head;
    } else {
        listmain->head = list2;
    }
    list2 = NULL;
}

List *list_plus(List *l1,List *l2){
    if (!l1->head && !l2->head) return NULL;
    List *listnew = list_new();
    Item *ptr1 = l1->head;
    Item *ptr2 = l2->head;
    while (ptr1 || ptr2){
        if (ptr1 == NULL){
            list_push_back(listnew, ptr2->data);
            ptr2 = ptr2->next;
        } else if (ptr2 == NULL) {
            list_push_back(listnew, ptr1->data);
            ptr1 = ptr1->next;
        } else {
            if (ptr1->data >= ptr2->data) {
                list_push_back(listnew, ptr2->data);
                ptr2 = ptr2->next;
            } else if (ptr1->data <= ptr2->data) {
                list_push_back(listnew, ptr1->data);
                ptr1 = ptr1->next;
            }

        }

    }
    return listnew;
}

int *array_plus(int *a1, int *a2, int l1, int l2){
    int i = 0, k = 0, j = 0;
    int *a3 = (int*)calloc((l1 + l2 + 1), sizeof(int));
    while ( k < l1 || j < l2){
        if (k == l1) {
            a3[i] = a2[j];
            j++;
            i++;
        } else if (j == l2){
            a3[i] = a1[k];
            k++;
            i++;
        } else if (a1[k] >= a2[j]) {
            a3[i] = a2[j];
            i++;
            j++;
        } else if (a1[k] <= a2[j]){
            a3[i] = a1[k];
            i++;
            j++;
        }
    }
    return a3;
}

int main() {
    List *l = list_new();
    List *l2 = list_new();
    List *listnew = list_new();

//    list_push_back(l, 3);
//    list_push_back(l, 5);
//    list_insert(l, 1);
//    list_push_back(l2, 4);
//    list_push_back(l2, 6);
//    list_insert(l2, 2);
    int a[] = {1 , 3 , 5};
    int b[] = {2 , 4 , 6};
    int Length1 = sizeof(a)/sizeof(int);
    int Length2 = sizeof(b)/sizeof(int);
    int *a3 = array_plus(a,b,Length1,Length2);
    for(int i = 0; i < (Length1+Length2); i++){
        printf("%d \n", a3[i]);
    }
    free(a3);
//    list_insert(l, 10);
//    list_insert(l, 20);
//    list_insert(l, 30);
//    list_print(l);
//    insert_number(l, 3, 5);
//    list_print(l);
//    delete_number(l, 3);
//    list_print(l);
//    list_insert(l2, 11);
//    list_insert(l2, 11);
//    list_insert(l2, 11);
//    list_print(l2);
//    list_concatinate(l,l2);
    list_print(l);
    list_print(l2);
    listnew = list_plus(l,l2);
    list_print(listnew);
    list_delete(l);
    list_delete(l2);
    return 0;
}
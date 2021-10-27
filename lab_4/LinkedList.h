//
// Created by al1enware on 28.05.2021.
//
#include <iostream>
#include <cassert>
#include "Sequence.h"
using namespace std;
#ifndef CPP_LINKEDLIST_H
#define CPP_LINKEDLIST_H



//Линкед лист
template <typename T>
// Структура элеметна односвязного списка
struct Item {
    T data;
    struct Item *next;
};
template <typename T>
// Структура данных для класса односвязного списка
struct List {
    Item<T> *head;
    Item<T> *tail;
};


// Наследник виртуального класса sequence, в котором реализована работа всех виртуальных методов с помощью односвязного списка
template<typename T> class LinkedList: public sequence<T> {
    List<T> *list;
    int size;
public:
    T &operator[](int index) override;

    LinkedList();

    LinkedList(T *items, int inputSize);
    LinkedList(const LinkedList<T> &other);

    ~LinkedList() override;

    void subSequence(int startIndex,int endIndex,  sequence<T>* Sub)  override;
    void deleteOne(int index) override;
    void concat(sequence<T>* Sub) override ;

    void append(T data) override;

    int getSize() override;

    void prepend(T data) override;

    void set(int index, T value) override;

    T getFirst() override;

    T getLast() override;

    void sort(bool (*function)(T data1, T data2), int type) override;
    void bubble_sort(bool (*function)(T data1, T data2));
    void choices_sort(bool (*function)(T data1, T data2));
    void choices_sort_func(Item<T> *head,bool (*function)(T data1, T data2));
    void quick_sort(bool (*function)(T data1, T data2));
    Item<T>* quick_sort_func(Item<T> *head,Item<T> *tail, bool (*function)(T data1, T data2));
    Item<T>* partition(Item<T> *head, Item<T> *end, Item<T> **newHead, Item<T> **newEnd,bool (*function)(T data1, T data2));
    Item<T>* getTail(Item<T> *cur);
    void merge_sort(bool (*function)(T data1, T data2));
    void merge_sort_func(Item<T> **head,bool (*function)(T data1, T data2));
    Item<T>* merge_sort_func2(Item<T> *head1, Item<T> *head2, bool (*function)(T data1, T data2));



    void map(T (*function)(T data, int option), int option) override;

    void where(bool (*function)(T data, int option), int option) override;
};

template<class T> void LinkedList<T>::sort(bool (*function)(T data1, T data2), int type) {
    switch(type) {
        case 1 : bubble_sort(function);
            break;
        case 2 :
            choices_sort(function);
            break;
        case 3 :
            merge_sort(function);
            break;
        case 4 :
            quick_sort(function);
            break;
        default: break;
    }
}

template<class T> void LinkedList<T>::bubble_sort(bool (*function)(T data1, T data2)) {
    int swapped, i;
    Item<T> *ptr1;
    Item<T> *start = list->head;
    Item<T> *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (function(ptr1->data,ptr1->next->data))
            {
                T temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

template<class T> void LinkedList<T>::merge_sort(bool (*function)(T data1, T data2)){
    merge_sort_func(&(list->head), function);
}

template<class T> void LinkedList<T>::merge_sort_func(Item<T> **head, bool (*function)(T data1, T data2))
{
    Item<T> *first = new Item<T>;
    Item<T> *second = new Item<T>;
    Item<T> *temp = new Item<T>;
    first = *head;
    temp = *head;

    // Return if list have less than two nodes.
    if(first == NULL || first->next == NULL)
    {
        return;
    }
    else
    {
        // Break the list into two half as first and second as head of list.
        while(first->next != NULL)
        {
            first = first->next;
            if(first->next != NULL)
            {
                temp = temp->next;
                first = first->next;
            }
        }
        second = temp->next;
        temp->next = NULL;
        first = *head;
    }

    // Implementing divide and conquer approach.
    merge_sort_func(&first, function);
    merge_sort_func(&second, function);

    // Merge the two part of the list into a sorted one.
    *head = merge_sort_func2(first, second, function);

}

template<class T> Item<T>* LinkedList<T>::merge_sort_func2(Item<T> *h1,Item<T> *h2, bool (*function)(T data1, T data2)){
    Item<T> *t1 = new Item<T>;
    Item<T> *t2 = new Item<T>;
    Item<T> *temp = new Item<T>;

    // Return if the first list is empty.
    if(h1 == NULL)
        return h2;

    // Return if the Second list is empty.
    if(h2 == NULL)
        return h1;

    t1 = h1;

    // A loop to traverse the second list, to merge the nodes to h1 in sorted way.
    while (h2 != NULL)
    {
        // Taking head node of second list as t2.
        t2 = h2;

        // Shifting second list head to the next.
        h2 = h2->next;
        t2->next = NULL;

        // If the data value is lesser than the head of first list add that node at the beginning.
        if(h1->data > t2->data)
        {
            t2->next = h1;
            h1 = t2;
            t1 = h1;
            continue;
        }

        // Traverse the first list.
        flag:
        if(t1->next == NULL)
        {
            t1->next = t2;
            t1 = t1->next;
        }
        // Traverse first list until t2->data more than node's data.
        else if(function(t2->data, (t1->next)->data))
        {
            t1 = t1->next;
            goto flag;
        }
        else
        {
            // Insert the node as t2->data is lesser than the next node.
            temp = t1->next;
            t1->next = t2;
            t2->next = temp;
        }
    }

    // Return the head of new sorted list.
    return h1;
}

template<class T> void LinkedList<T>::choices_sort(bool (*function)(T data1, T data2)) {
    choices_sort_func(list->head, function);
}

template<class T> void LinkedList<T>::choices_sort_func(Item<T> *head,bool (*function)(T data1, T data2)) {
    if(head == NULL || head->next == NULL) {
        return;
    }
    Item<T> *t1 = (*head).next;
    while(t1 != NULL) {
        T sec_data = t1->data;
        int found = 0;
        Item<T> *t2 = head;
        while(t2 != t1) {
            if( !function(t1->data, t2->data) && found == 0) {
                sec_data = t2->data;
                t2->data = t1->data;
                found = 1;
                t2 = t2->next;
            } else {
                if(found == 1) {
                    T temp = sec_data;
                    sec_data = t2->data;
                    t2->data = temp;
                }
                t2 = t2->next;
            }
        }
        t2->data = sec_data;
        t1 = t1->next;
    }
}

template<class T> void LinkedList<T>::quick_sort(bool (*function)(T data1, T data2)) {
    list->head = quick_sort_func(list->head, list->tail, function);
    return;
}

template<class T> Item<T>* LinkedList<T>::quick_sort_func(Item<T> *head,Item<T> *end, bool (*function)(T data1, T data2)) {
    // base condition
    if (!head || head == end)
        return head;

    Item<T> *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    Item<T> *pivot = partition(head, end, &newHead, &newEnd, function);

    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the LLNode before the pivot LLNode as NULL
        Item<T> *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // Recur for the list before pivot
        newHead = quick_sort_func(newHead, tmp,function);

        // Change next of last LLNode of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }

    // Recur for the list after the pivot element
    pivot->next = quick_sort_func(pivot->next, newEnd, function);

    return newHead;
}

template<class T> Item<T>* LinkedList<T>::getTail(Item<T> *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

template<class T> Item<T>* LinkedList<T>::partition(Item<T> *head, Item<T> *end, Item<T> **newHead, Item<T> **newEnd, bool (*function)(T data1, T data2)) {
    Item<T> *pivot = end;
    Item<T> *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (!function(cur->data, pivot->data))
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else // If cur LLNode is greater than pivot
        {
            // Move cur LLNode to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            Item<T> *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    // Update newEnd to the current last node
    (*newEnd) = tail;

    // Return the pivot LLNode
    return pivot;
}



template<class T>  T& LinkedList<T>::operator[](int index){
        assert(index < size && index >-1 && "Ошибка: Вы пытаетесь указать индекс, выходит за заполненное пространство массива");
            Item<T> *ptr = list->head;
            for (int i = 0; i < index; ++i) {
                ptr = ptr->next;
            }
            return ptr->data;

}

template<class T>  LinkedList<T>::LinkedList() {
    list = (List<T> *) calloc(1, sizeof(List<T>));
    list->head = NULL;
    list->tail = NULL;
    size = 0;
}

template<class T>  LinkedList<T>::LinkedList(T *items, int inputSize) : LinkedList() {
    for (int i = 0; i < inputSize; ++i) {
        append(items[i]);
    }
}

template<class T>  LinkedList<T>::LinkedList(const LinkedList<T> &other) : LinkedList() {
    Item<T> *ptr = other.list->head;
    for (int i = 0; i < other.size; ++i) {
        append(ptr->data);
        ptr = ptr->next;
    }
}

template<class T>  LinkedList<T>::~LinkedList() {
    Item<T> *ptr = list->head, *ptr_prev;
    while (ptr) {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    free(list);
    size = 0;
}

template<class T>  void LinkedList<T>::subSequence(int startIndex, int endIndex,  sequence<T>* Sub) {
    if (startIndex < size && size > endIndex && startIndex < endIndex && startIndex >= 0 && endIndex > 0) {
        Item<T> *ptr = list->head;
        for (int i = 0; i <= endIndex; ++i) {
            if (i>= startIndex && i <= endIndex) {
                Sub->append(ptr->data);
            }
            ptr = ptr->next;
        }
    } else {
        cout << "Ошибка: Начальный индекс больше конечного/Конечный индекс больше максимального/Пустой список" << endl;
    }

}
template<class T>  void LinkedList<T>::deleteOne(int index) {
    if (index >= size){
        return;
    }
    if(index == 0){
        Item<T> *item = list->head;
        list->head = list->head->next;
        free(item);
        size--;
    } else {
        Item<T> *ptr = list->head, *ptr_prev;
        for (int i = 0; i < index; ++i) {
            ptr_prev = ptr;
            ptr = ptr->next;
        }
        ptr_prev->next = ptr->next;
        if (index == size-1){
            list->tail = ptr_prev;
        }
        free(ptr);
        size--;
    }
}

template<class T>  void LinkedList<T>::concat(sequence<T>* Sub){
    if (Sub->getSize() > 0) {
        for (int i = 0; i < Sub->getSize(); ++i) {
            append((*Sub)[i]);
        }
    }
}

template<class T>  void LinkedList<T>::append(T data)  {
    Item<T> *ptr = (Item<T> *) calloc(1, sizeof(Item<T>));
    if (!ptr) {
        return;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (!list->head) {
        list->head = ptr;
        list->tail = ptr;
    } else {
        list->tail->next = ptr;
        list->tail = ptr;
    }
    size++;
    return;
}

template<class T> int LinkedList<T>::getSize(){ return size; }

template<class T>  void LinkedList<T>::prepend(T data) {
    Item<T> *ptr = (Item<T> *) calloc(1, sizeof(Item<T>));
    if (!ptr) {
        return;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (!list->head) {
        list->head = ptr;
        list->tail = ptr;
    } else {
        ptr->next = list->head;
        list->head = ptr;
    }
    size++;
    return;
}

template<class T>  void LinkedList<T>::set(int index, T value)  {
    if(index < size && index >= 0 ) {
        Item<T> *ptr = list->head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        ptr->data = value;
    } else {
        cout << "Ошибка: Вы пытаетесь указать индекс, выходит за заполненное пространство списка" << endl;
    }
}

template<class T>  T LinkedList<T>::getFirst()  {
    if (!list->head) {
        return NULL;
    } else {
        return list->head->data;
    }
}

template<class T>  T LinkedList<T>::getLast(){
    if (!list->head) {
        return NULL;
    } else {
        return list->tail->data;
    }
}

template<class T>  void LinkedList<T>:: map(T (*function)(T data, int option), int option){
    Item<T> *ptr = list->head;
    for (int i = 0; i < size; ++i) {
        ptr->data = function(ptr->data, option);
        ptr = ptr->next;
    }
}

template<class T>  void LinkedList<T>::where(bool (*function)(T data, int option), int option){
Item<T> *ptr = list->head, *ptr_prev;
int i = 0;
    while (i < size) {
    if (!function(ptr->data, option)) {
        if(i == 0){
            list->head = list->head->next;
            free(ptr);
            ptr = list->head;
            ptr_prev = ptr;
            size--;
        } else {
            ptr_prev->next = ptr->next;
            if (i == size-1){
                list->tail = ptr_prev;
            }
            free(ptr);
            ptr = ptr_prev->next;
            size--;
        }
    } else {
        ptr_prev = ptr;
        ptr = ptr->next;
        i++;
    }

    }
}

#endif //CPP_LINKEDLIST_H

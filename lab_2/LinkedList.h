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

    T &operator[](const int index) override;

    LinkedList();

    LinkedList(T *items, int inputSize);
    LinkedList(const LinkedList<T> &other);

    ~LinkedList() override;

    void subSequence(const int startIndex, const int endIndex,  sequence<T>* Sub)  override;
    void deleteOne(int index) override;
    void concat(sequence<T>* Sub) override ;

    void append(T data) override;

    int getSize() override;

    void prepend(T data) override;

    void set(int index, T value) override;

    T getFirst() override;

    T getLast() override;


    void map(T (*function)(T data, int option), int option) override;

    void where(bool (*function)(T data, int option), int option) override;
};

template<class T>  T& LinkedList<T>::operator[](const int index){
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

template<class T>  void LinkedList<T>::subSequence(const int startIndex, const int endIndex,  sequence<T>* Sub) {
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

    } else {
        return list->head->data;
    }
}

template<class T>  T LinkedList<T>::getLast(){
    if (!list->head) {

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

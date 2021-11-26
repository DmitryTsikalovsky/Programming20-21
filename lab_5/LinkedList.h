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
template <class T> struct ItemList {
    T data;
    struct ItemList *next;
};
template <class T> struct List {
    ItemList<T> *head;
    ItemList<T> *tail;
};


// Наследник виртуального класса sequence, в котором реализована работа всех виртуальных методов с помощью односвязного списка
template<typename T> class LinkedList: public sequence<T> {

public:
    List<T> *list;
    int size;
    T&operator[](int index) override{
        assert(index < size && index > -1 &&
               "Ошибка: Вы пытаетесь указать индекс, выходит за заполненное пространство массива");
        ItemList<T> *ptr = list->head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        return ptr->data;
    }

    LinkedList(){
        list = (List<T> *) calloc(1, sizeof(List<T>));
        list->head = NULL;
        list->tail = NULL;
        size = 0;
    }

    LinkedList(T *items, int inputSize){
        for (int i = 0; i < inputSize; ++i) {
            append(items[i]);
        }
    }
    LinkedList(const LinkedList<T> &other): LinkedList() {
            ItemList<T> *ptr = other.list->head;
            for (int i = 0; i < other.size; ++i) {
                append(ptr->data);
                ptr = ptr->next;
            }
    }

    ~LinkedList() override{
        ItemList<T> *ptr = list->head, *ptr_prev;
        while (ptr) {
            ptr_prev = ptr;
            ptr = ptr->next;
            free(ptr_prev);
        }
        free(list);
        size = 0;
    }

    void subSequence(int startIndex,int endIndex,  sequence<T>* Sub)  override{
        if (startIndex < size && size > endIndex && startIndex < endIndex && startIndex >= 0 && endIndex > 0) {
            ItemList<T> *ptr = list->head;
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

    void deleteOne(int index) override{
        if (index >= size){
            return;
        }
        if(index == 0){
            ItemList<T> *item = list->head;
            list->head = list->head->next;
            free(item);
            size--;
        } else {
            ItemList<T> *ptr = list->head, *ptr_prev;
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

    void concat(sequence<T>* Sub) override{
        if (Sub->getSize() > 0) {
            for (int i = 0; i < Sub->getSize(); ++i) {
                append((*Sub)[i]);
            }
        }
    }

    void append(T data) override{
        ItemList<T> *ptr = (ItemList<T> *) calloc(1, sizeof(ItemList<T>));
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

    int getSize() override{return size;}

    void prepend(T data) override{
        ItemList<T> *ptr = (ItemList<T> *) calloc(1, sizeof(ItemList<T>));
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

    void set(int index, T value) override{
        if(index < size && index >= 0 ) {
            ItemList<T> *ptr = list->head;
            for (int i = 0; i < index; ++i) {
                ptr = ptr->next;
            }
            ptr->data = value;
        } else {
            cout << "Ошибка: Вы пытаетесь указать индекс, выходит за заполненное пространство списка" << endl;
        }
    }
    T& getFirst() override{
        return list->head->data;
    }

    T& getLast() override {
        return list->tail->data;
    }

    void map(T (*function)(T data, int option), int option) override{
        ItemList<T> *ptr = list->head;
        for (int i = 0; i < size; ++i) {
            ptr->data = function(ptr->data, option);
            ptr = ptr->next;
        }
    }

    void where(bool (*function)(T data, int option), int option) override{
        ItemList<T> *ptr = list->head, *ptr_prev;
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
};

#endif //CPP_LINKEDLIST_H

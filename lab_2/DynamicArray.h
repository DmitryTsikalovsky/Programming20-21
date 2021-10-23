//
// Created by al1enware on 28.05.2021.
//
#include <iostream>
#include <cassert>
#include "Sequence.h"
using namespace std;
#ifndef CPP_DYNAMICARRAY_H
#define CPP_DYNAMICARRAY_H

template<class T> class DynamicArray: public sequence<T>{
    T *data;
    int size;
    int capacity;
public:
    T& operator[](const int index);

    DynamicArray();

    explicit DynamicArray(int inputsize);

    DynamicArray(T* items, int inputSize);
    DynamicArray(const DynamicArray<T> &other);
    ~DynamicArray() override;
    void append(T value) override;

    void appendClass(const T& value);
    void deleteOne(int index) override;
    void subSequence(const int startIndex, const int endIndex,   sequence<T>* Sub) override;
    void concat(sequence<T>* Sub) override;
    int getSize() override;

    T getFirst() override;
    T getLast() override;

    void prepend(T data) override;
    void resize(int newSize);
    void set(int index, T value) override;
    void map(T (*function)(T data, int option), int option)override;
    void where(bool (*function)(T data, int option), int option) override;
};

template<class T> T& DynamicArray<T>::operator[](const int index){
    assert(index < size && "Ошибка: Вы пытаетесь указать индекс, выходит за заполненное пространство массива");
    return data[index];
}
template<class T> DynamicArray<T>::DynamicArray(){
    size = 0;
    capacity = 1;
    this->data = (T*)calloc(capacity, sizeof(T));
}

template<class T> DynamicArray<T>:: DynamicArray(int inputsize){
    size = inputsize;
    capacity = inputsize;
    this->data = (T*)calloc(inputsize, sizeof(T));
}

template<class T> DynamicArray<T>:: DynamicArray(T* items, int inputSize):DynamicArray(inputSize) {
        for (int i = 0; i < inputSize; ++i) {
            this->data[i] = items[i];
        }
}

template<class T> DynamicArray<T>:: DynamicArray(const DynamicArray<T> &other): DynamicArray(other.data, other.size){

}

template<class T> DynamicArray<T>:: ~DynamicArray(){
    size = 0;
    capacity = 0;
    free(this->data);
}

template<class T> void DynamicArray<T>::append(T value){
    if(this->size + 1 > this->capacity) {
    resize(this->capacity + 10);
    }
    this->data[this->size] = value;
    this->size++;
}
template<class T> void DynamicArray<T>::appendClass(const T& value) {
    if(this->size + 1 > this->capacity) {
        resize(this->capacity + 10);
    }
    this->data[this->size] = value;
    this->size++;
}
template<class T> void DynamicArray<T>::deleteOne(int index){
    if (index > size || index < 0 || size == 0){
    cout << "Индекс выходит за область заполенных значений, или же отсутсвтуют элементы" << endl;
    return;
    }
    for (int i = index; i < size; ++i) {
    data[i] = data[i+1];
    }
    size--;
}

template<class T> void DynamicArray<T>::subSequence(const int startIndex, const int endIndex,   sequence<T>* Sub)  {
    if (startIndex < size && size > endIndex && startIndex < endIndex  && startIndex >= 0 && endIndex > 0) {
        if (Sub->getSize() > 0) {
            return;
        }
        for (int i = startIndex; i <= endIndex; ++i) {
            Sub->append(this->data[i]);
        }
    } else {
        cout << "Ошибка: Начальный индекс больше конечного/Конечный индекс больше максимального/Пустой массив" << endl;
    }

}

template<class T>  void DynamicArray<T>:: concat(sequence<T>* Sub){
    for (int i = 0; i < Sub->getSize(); ++i) {
        append((*Sub)[i]);
    }
}
template<class T> int DynamicArray<T>::getSize() { return size;}

template<class T> T DynamicArray<T>::getFirst()  {
    return data[0];
}

template<class T>  T DynamicArray<T>::getLast() {
    return data[size-1];
}

template<class T>  void DynamicArray<T>::prepend(T data) {
    if(size + 1 > capacity) {
        resize(capacity + 10);
    }
    if(size == 0) {
        append(data);
    } else if(size == 1) {
        this->data[1] = this->data[0];
        this->data[0] = data;
        size++;
    }else {
        for (int i = size-1; i >= 0; --i) {
        this->data[i+1] = this->data[i];
    }
        this->data[0] = data;
        size++;
    }

}

template<class T>  void DynamicArray<T>::resize(int newSize) {
    if (newSize == capacity) {
        return;
    }
    if (newSize > capacity){
        T *newData = (T*)calloc(newSize, sizeof(T));
        memcpy(newData, this->data, sizeof(T));
        free(this->data);
        this->data = newData;
        capacity = newSize;
    } else {
        capacity = newSize;
    }
}

template<class T>  void DynamicArray<T>:: set(int index, T value) {
    if(index > size + 1) {
        cout << "Ошибка: Вы пытаетесь указать индекс, который создаёт пустое пространство внутри массива" << endl;
        return;
    } else {
        if(size + 1 > capacity) {
        resize(capacity + 10);
    }
        this->data[index] = value;
    }

}
template<class T>  void DynamicArray<T>:: map(T (*function)(T data, int option), int option) {
    for (int i = 0; i < size; ++i) {
        data[i] = function(data[i], option);
    }
}
template<class T> void DynamicArray<T>:: where(bool (*function)(T data, int option), int option) {
    int i = 0;
    int newSize = 0;
    while(i < size) {
        if (!function(this->data[i], option)){
            i++;
        } else {
            this->data[newSize] = this->data[i];
            newSize++;
            i++;
        }
    }
    size = newSize;
}

#endif //CPP_DYNAMICARRAY_H

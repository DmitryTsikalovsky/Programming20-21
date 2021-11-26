//
// Created by al1enware on 28.05.2021.
//
#include <iostream>
#include <cassert>
#include <cstring>
#include <stdlib.h>
#include "Sequence.h"
using namespace std;
#ifndef CPP_DYNAMICARRAY_H
#define CPP_DYNAMICARRAY_H

template<class T> class DynamicArray: public sequence<T>{

public:
    T *data;
    int size;
    int capacity;
    T& operator[](int index) override{
        assert(index < size && "Ошибка: Вы пытаетесь указать индекс, выходит за заполненное пространство массива");
        return data[index];
    }

    DynamicArray(){
        size = 0;
        capacity = 1;
        this->data = (T*)calloc(capacity, sizeof(T));
    }

    explicit DynamicArray(int inputsize){
        this->size = inputsize;
        this->capacity = inputsize;
        this->data = (T*)calloc(inputsize, sizeof(T));
    }

    DynamicArray(T* items, int inputSize):DynamicArray(inputSize){
        for (int i = 0; i < inputSize; ++i) {
            this->data[i] = items[i];
        }
    }

    DynamicArray(DynamicArray<T> &other): DynamicArray(other.data, other.size){

    }

    ~DynamicArray() override{
        size = 0;
        capacity = 0;
        free(this->data);
    }

    void append(T value) override{
        if(this->size + 1 > this->capacity) {
            resize(this->capacity * 2);
        }
        this->data[this->size] = value;
        this->size++;
    }

    void appendClass(const T& value){
        if(this->size + 1 > this->capacity) {
            resize(this->capacity + 10);
        }
        this->data[this->size] = value;
        this->size++;
    }

    void deleteOne(int index) override{
        if (index > size || index < 0 || size == 0){
            cout << "Индекс выходит за область заполенных значений, или же отсутсвтуют элементы" << endl;
            return;
        }
        for (int i = index; i < size; ++i) {
            data[i] = data[i+1];
        }
        size--;
    }

    void subSequence(int startIndex, int endIndex,   sequence<T>* Sub) override{
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

    void concat(sequence<T>* Sub) override{
        for (int i = 0; i < Sub->getSize(); ++i) {
            append((*Sub)[i]);
        }
    }

    int getSize() override{ return size;}

    T& getFirst() override{
        return data[0];
    }

    T& getLast() override{
        return data[size-1];
    }
//
//    void remove(T& removeData){
//        for (int i = 0; i < size; ++i) {
//            if (removeData == data[i]) deleteOne(i);
//        }
//    }

    void prepend(T data) override{
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

    void resize(int newSize){
        if (newSize == capacity) {
            return;
        }
        if (newSize > capacity){
            T *newData = (T*)calloc(newSize, sizeof(T));
            std::memcpy(newData, this->data, sizeof(T));
            free(this->data);
            this->data = newData;
            capacity = newSize;
        } else {
            capacity = newSize;
        }
    }

    void set(int index, T value) override{
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

    void map(T (*function)(T data, int option), int option)override{
        for (int i = 0; i < size; ++i) {
            data[i] = function(data[i], option);
        }
    }

    void where(bool (*function)(T data, int option), int option) override{
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
};


#endif //CPP_DYNAMICARRAY_H

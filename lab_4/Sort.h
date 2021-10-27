//
// Created by Dmitry Tsikalovsky on 24.10.2021.
//
#include "Sequence.h"
#include <iostream>
#ifndef INC_2SEMPROGA_SORT_H
#define INC_2SEMPROGA_SORT_H


template<class T> class Sort{

    void bubble_sort(sequence<T>& Object, bool (*function)(T& data1, T& data2)){
        for (int i = 0; i < Object.getSize(); i++) {
            for (int j = 0; j < Object.getSize()-1; j++) {
                if (function(Object[j], Object[j+1])) { // оператор [] возвращает T&
                    std::swap(Object[j],Object[j+1]);
                }
            }
        }
    }

    void merge_sort(sequence<T>& Object, bool (*function)(T& data1, T& data2)){
        merge_sort_func(Object, function, 0, Object.getSize()-1 );
    }
    //функция, сливающая массивы
    void merge_sort_func2(sequence<T>& Object, bool (*function)(T& data1, T& data2),int first, int last) {
        int middle, start, final, j;
        T *mas = new T[Object.getSize()];
        middle = (first + last) / 2;  //вычисление среднего элемента
        start = first;                //начало левой части
        final = middle + 1;           //начало правой части
        for (j = first; j <= last; j++)  //выполнять от начала до конца
            if ((start <= middle) && ((final > last) || (!function(Object[start] , Object[final]) ))) {
                mas[j] = std::move(Object[start]);
                start++;
            } else {
                mas[j] = std::move(Object[final]);
                final++;
            }
        //возвращение результата в список
        for (j = first; j <= last; j++)
            Object[j] = std::move(mas[j]);
        delete[] mas;
    };
    //рекурсивная процедура сортировки
    void merge_sort_func(sequence<T>& Object, bool (*function)(T& data1, T& data2), int first, int last) {
        if (first < last) {
            merge_sort_func(Object, function, first, (first + last) / 2);  //сортировка левой части
            merge_sort_func(Object, function, (first + last) / 2 + 1, last);  //сортировка правой части
            merge_sort_func2(Object, function, first, last);  //слияние двух частей
        }
    }

    void quick_sort(sequence<T>& Object, bool (*function)(T& data1, T& data2)){
        quick_sort_func(function, 0, size-1);
    }

    void quick_sort_func(sequence<T>& Object, bool (*function)(T& data1, T& data2), int low, int high) {
        if (low >= high) return;
        int index = partition(sequence<T>& Object, function , low, high);
        quick_sort_func(sequence<T>& Object, function, low, index - 1);
        quick_sort_func(sequence<T>& Object, function, index + 1, high);
    }

    int partition(sequence<T>& Object, bool (*function)(T& data1, T& data2), int low, int high)
    {
        int pivotindex = low;
        T pivotvalue = std::move(Object[high]);
        for (int i = low; i < high; i++)
        {
            if (Object[i] < pivotvalue)
            {
                std::swap(Object[j],Object[pivotindex]);
                pivotindex++;
            }
        }
        std::swap(Object[pivotindex],Object[high]);
        return pivotindex;
    }

    void choices_sort(sequence<T>& Object, bool (*function)(T& data1, T& data2)) // сортировка выбором (поиск наименьшего элемента)
    {
        for (int i = 0; i < size; i++)
        {
            T *temp = Object[i]; // указатель на найменьший элемент
            for (int j = i + 1; j < size; j++)
            {
                if (function(temp,Object[j]))
                {
                    temp = Object[j];
                }
                std::swap(Object[i], temp);
            }
        }
    }
};


#endif //INC_2SEMPROGA_SORT_H

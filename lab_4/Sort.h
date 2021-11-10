//
// Created by Dmitry Tsikalovsky on 24.10.2021.
//
#include "Sequence.h"
#include <iostream>
#include <cstdio>
#ifndef INC_2SEMPROGA_SORT_H
#define INC_2SEMPROGA_SORT_H


template<class T, class S> class Sort{

private:
    static void bubble_sort(T *sequence, bool (*function)(const S& data1, const S& data2)){
        for (int i = 0; i < sequence->getSize(); i++) {
            for (int j = 0; j < sequence->getSize()-1; j++) {
                if (function( sequence[0][j], sequence[0][j+1])) { // оператор [] возвращает T&
                    std::swap(sequence[0][j],sequence[0][j+1]);
                }
            }
        }
    }

    static void merge_sort(T * sequence, bool (*function)(const S& data1,const S& data2)){
        merge_sort_func(sequence, function, 0, sequence->getSize()-1 );
    }
    //функция, сливающая массивы
    static void merge_sort_func2(T * sequence, bool (*function)(const S& data1,const S& data2),int first, int last) {
        int middle, start, final, j;
        S *mas = new S[sequence->getSize()];
        middle = (first + last) / 2;  //вычисление среднего элемента
        start = first;                //начало левой части
        final = middle + 1;           //начало правой части
        for (j = first; j <= last; j++)  //выполнять от начала до конца
            if ((start <= middle) && ((final > last) || (!function(sequence[0][start] , sequence[0][final]) ))) {
                mas[j] = sequence[0][start];
                start++;
            } else {
                mas[j] = sequence[0][final];
                final++;
            }
        //возвращение результата в список
        for (j = first; j <= last; j++)
            sequence[0][j] = mas[j];
        delete[] mas;
    };
    //рекурсивная процедура сортировки
    static void merge_sort_func(T * sequence, bool (*function)(const S& data1,const S& data2), int first, int last) {
        if (first < last) {
            merge_sort_func(sequence, function, first, (first + last) / 2);  //сортировка левой части
            merge_sort_func(sequence, function, (first + last) / 2 + 1, last);  //сортировка правой части
            merge_sort_func2(sequence, function, first, last);  //слияние двух частей
        }
    }

    static void quick_sort(T * sequence, bool (*function)(const S& data1,const S& data2)){
        quick_sort_func(sequence, function, 0, sequence->getSize()-1);
    }

    static void quick_sort_func(T * sequence, bool (*function)(const S& data1,const S& data2), int low, int high) {
        if (low >= high) return;
        int index = partition(sequence, function , low, high);
        quick_sort_func(sequence, function, low, index - 1);
        quick_sort_func(sequence, function, index + 1, high);
    }

    static int partition(T * sequence, bool (*function)(const S& data1,const S& data2), int low, int high)
    {
        int pivotindex = low;
        S pivotvalue = sequence[0][high];
        for (int i = low; i < high; i++)
        {
            if (sequence[0][i] < pivotvalue)
            {
                std::swap(sequence[0][i],sequence[0][pivotindex]);
                pivotindex++;
            }
        }
        std::swap(sequence[0][pivotindex],sequence[0][high]);
        return pivotindex;
    }

    static void choices_sort(T * sequence, bool (*function)(const S& data1,const S& data2)) // сортировка выбором (поиск наименьшего элемента)
    {
        for (int i = 0; i < sequence->getSize(); i++)
        {
            int tempIndex = i; // указатель на найменьший элемент
            for (int j = i + 1; j < sequence->getSize(); j++)
            {
                if (function(sequence[0][tempIndex],sequence[0][j]))
                {
                    tempIndex = j;
                }
            }
            std::swap(sequence[0][i], sequence[0][tempIndex]);
        }
    }
public:
    //    Sort() = default;
    static void sort(T* sequnece, bool (*function)(const S& data1,const S& data2), int type) {
        switch(type) {
            case 1 :
                bubble_sort(sequnece, function); // prints "1"
            break;       // and exits the switch
            case 2 :
                choices_sort(sequnece, function);
            break;
            case 3 :
                merge_sort(sequnece, function);
            break;
            default:
                quick_sort(sequnece, function);
            break;
        }

    }

};

template<class S>void Sort<LinkedList<S>, S>::bubble_sort(S *sequence, bool (*function)(const S& data1, const S& data2))

#endif //INC_2SEMPROGA_SORT_H

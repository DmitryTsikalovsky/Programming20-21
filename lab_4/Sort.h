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
            if (function(pivotvalue,sequence[0][i]))
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

    static void Listbubble_sort(List<S>* List,bool (*function)(const S& data1,const S& data2))
    {
        int swapped, i;
        Item<S> *ptr1;
        Item<S> *start = List->head;
        Item<S> *lptr = NULL;

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
                    std::swap(ptr1->data,ptr1->next->data);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        }
        while (swapped);
    }

    static void Listmerge_sort(List<S>* list, bool (*function)(const S& data1,const S& data2)){
        Listmerge_sort_func(&(list->head), function);
    }
    static   void Listmerge_sort_func(Item<S> **head, bool (*function)(const S& data1,const S& data2))
    {
        Item<S> *first = new Item<S>;
        Item<S> *second = new Item<S>;
        Item<S> *temp = new Item<S>;
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
        Listmerge_sort_func(&first, function);
        Listmerge_sort_func(&second, function);

        // Merge the two part of the list into a sorted one.
        *head = Listmerge_sort_func2(first, second, function);
    }

static Item<S>* Listmerge_sort_func2(Item<S> *h1,Item<S> *h2, bool (*function)(const S& data1,const S& data2)){
    Item<S> *t1 = new Item<S>;
    Item<S> *t2 = new Item<S>;
    Item<S> *temp = new Item<S>;

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
        if(function(h1->data,t2->data))
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

static void Listchoices_sort(List<S> *list, bool (*function)(const S& data1,const S& data2)) {
    Listchoices_sort_func(list->head, function);
}

static void Listchoices_sort_func(Item<S> *head,bool (*function)(const S& data1,const S& data2)) {
    if(head == NULL || head->next == NULL) {
        return;
    }
    Item<S> *t1 = (*head).next;
    while(t1 != NULL) {
        S sec_data = t1->data;
        int found = 0;
        Item<S> *t2 = head;
        while(t2 != t1) {
            if( !function(t1->data, t2->data) && found == 0) {
                sec_data = t2->data;
                t2->data = t1->data;
                found = 1;
                t2 = t2->next;
            } else {
                if(found == 1) {
                    S temp = sec_data;
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

static void Listquick_sort(List<S> *list, bool (*function)(const S& data1,const S& data2)) {
    list->head = Listquick_sort_func(list->head, list->tail, function);
    return;
}

static Item<S>* Listquick_sort_func(Item<S> *head,Item<S> *end, bool (*function)(const S& data1,const S& data2)) {
    // base condition
    if (!head || head == end)
        return head;

    Item<S> *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    Item<S> *pivot = Listpartition(head, end, &newHead, &newEnd, function);

    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the LLNode before the pivot LLNode as NULL
        Item<S> *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // Recur for the list before pivot
        newHead = Listquick_sort_func(newHead, tmp,function);

        // Change next of last LLNode of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }

    // Recur for the list after the pivot element
    pivot->next = Listquick_sort_func(pivot->next, newEnd, function);

    return newHead;
}

static Item<S>* getTail(Item<S> *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

static Item<S>* Listpartition(Item<S> *head, Item<S> *end, Item<S> **newHead, Item<S> **newEnd, bool (*function)(const S& data1,const S& data2)) {
    Item<S> *pivot = end;
    Item<S> *prev = NULL, *cur = head, *tail = pivot;

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
            Item<S> *tmp = cur->next;
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

public:
    //    Sort() = default;

    static void sort(T* sequnece, bool (*function)(const S& data1,const S& data2), int type) {
        LinkedList<S> *List = dynamic_cast<LinkedList<S>*>(List);
        if (List == nullptr) {
            switch(type) {
                case 1 :
                    Listbubble_sort(List->list, function); // prints "1"
                    break;       // and exits the switch
                case 2 :
                    Listchoices_sort(List->list, function); // выбором
                    break;
                case 3 :
                    Listmerge_sort(List->list, function);
                    break;
                default:
                    Listquick_sort(List->list, function);
                    break;
            }
        } else {
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
    }

};

//template<class S>void Sort<LinkedList<S>, S>::bubble_sort(S *sequence, bool (*function)(const S& data1, const S& data2))

#endif //INC_2SEMPROGA_SORT_H

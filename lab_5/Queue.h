//
// Created by al1enware on 28.05.2021.
//
#include <iostream>
#include "Sequence.h"
#include "LinkedList.h"
using namespace std;
#ifndef CPP_QUEUE_H
#define CPP_QUEUE_H

template<class V>struct ItemQueue{
    V key;
    int timeCreate;
};

template<class T>class Queue {
private:
    LinkedList<T> *List;
public:
    Queue(){
        List = new LinkedList<T>;
    }
    void push(T data){
        List->append(data);
    }
    T& pop(){
        return List->getFirst();
    }
    void remove(){
        List->deleteOne(0);
    }

};

#endif //CPP_QUEUE_H

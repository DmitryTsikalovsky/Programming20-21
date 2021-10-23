//
// Created by al1enware on 28.05.2021.
//
#include <iostream>
#include "Sequence.h"
using namespace std;
#ifndef CPP_QUEUE_H
#define CPP_QUEUE_H

// Наследник виртуального класса sequence, в котором реализована работа всех виртуальных методов с помощью созданных классов Dynamic Array и Linked List
template<class T, class Main = LinkedList<T>>class Queue {
private:
    Main* sequence;
public:
//    T& operator[](const int index)override;
//    void set(int index, T value) override;
//    void subSequence(const int startIndex, const int endIndex,  sequence<T>* Sub)override;
//    void concat(sequence<T> *Sub) override;
//    void map(T (*function)(T data, int option), int option) override;
//    void deleteOne(int index) override;
//    void where(bool (*function)(T data, int option), int option);
//    int getSize() override;
//    T getFirst();
//    void append(T data) override;
//    void prepend(T data) override;
//    T getLast() override;
//    ~Queue() override;

    void push(T data);
    void setIndex(int index, T data);
    T pop();
    void deleteOne(int index);

};



template<class T, class Main>  void Queue<T, Main>::push(T data) {
    QueueData.append(data);
}

template<class T, class Main>  void Queue<T, Main>::setIndex(int index, T data) {
    QueueData.set(index, data);
}

template<class T, class Main>  T Queue<T, Main>::pop() {
    T data = QueueData[0];
    QueueData.deleteOne(0);
    return data;
}

template<class T, class Main>  void Queue<T, Main>::deleteOne(int index) {
    QueueData.deleteOne(index);
}


//template<class T, class Main>  void Queue<T, Main>::set(int index, T value){
//    QueueData.set(index,value);
//}
//
//template<class T, class Main>  T& Queue<T, Main>::operator[](const int index){
//    return QueueData[index];
//}
//
//template<class T, class Main>  void Queue<T, Main>::subSequence(const int startIndex, const int endIndex,  sequence<T>* Sub){
//    QueueData.subSequence(startIndex, endIndex, Sub);
//}
//template<class T, class Main>  void Queue<T, Main>::concat(sequence<T> *Sub) {
//    QueueData.concat(Sub);
//}
//template<class T, class Main>  void Queue<T, Main>::map(T (*function)(T data, int option), int option){
//    QueueData.map(function, option);
//}
//template<class T, class Main>  void Queue<T, Main>::deleteOne(int index) {
//    QueueData.deleteOne(index);
//}
//template<class T, class Main>  void Queue<T, Main>::where(bool (*function)(T data, int option), int option) {
//    QueueData.where(function, option);
//}
//
//template<class T, class Main>  int Queue<T, Main>::getSize() {
//    return QueueData.getSize();
//}
//template<class T, class Main> T Queue<T, Main>::getFirst() {
//    return QueueData.getFirst();
//}
//template<class T, class Main>  void Queue<T, Main>::append(T data) {
//    QueueData.append(data);
//}
//template<class T, class Main>  void Queue<T, Main>::prepend(T data) {
//    QueueData.prepend(data);
//}
//template<class T, class Main>  T Queue<T, Main>::getLast()  {
//    return QueueData.getLast();
//}
//
//
//template<class T, class Main>  Queue<T, Main>::~Queue(){
//
//}

#endif //CPP_QUEUE_H

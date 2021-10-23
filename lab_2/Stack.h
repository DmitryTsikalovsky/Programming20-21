//
// Created by al1enware on 28.05.2021.
//
#include <iostream>
#include "Sequence.h"
using namespace std;
#ifndef CPP_STACK_H
#define CPP_STACK_H


// Наследник виртуального класса sequence, в котором реализована работа всех виртуальных методов с помощью созданных классов Dynamic Array и Linked List
template<typename T, class Main = LinkedList<T>>class Stack {
    Main StackData;
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
//    ~Stack() override;
    void push(T data);
    void setIndex(int index, T data);
    T pop();
    void deleteOne(int index);

};

template<class T, class Main>  void Stack<T, Main>::push(T data) {
    StackData.prepend(data);
}

template<class T, class Main>  void Stack<T, Main>::setIndex(int index, T data) {
    StackData.set(index, data);
}

template<class T, class Main>  T Stack<T, Main>::pop() {
    T data = StackData[0];
    StackData.deleteOne(0);
    return data;
}

template<class T, class Main>  void Stack<T, Main>::deleteOne(int index) {
    StackData.deleteOne(index);
}


//template<class T, class Main>  void Stack<T, Main>::set(int index, T value){
//    StackData.set(index,value);
//}
//
//template<class T, class Main>  T& Stack<T, Main>::operator[](const int index){
//    return StackData[index];
//}
//
//template<class T, class Main>  void Stack<T, Main>::subSequence(const int startIndex, const int endIndex,  sequence<T>* Sub){
//    StackData.subSequence(startIndex, endIndex, Sub);
//}
//template<class T, class Main>  void Stack<T, Main>::concat(sequence<T> *Sub) {
//    StackData.concat(Sub);
//}
//template<class T, class Main>  void Stack<T, Main>::map(T (*function)(T data, int option), int option){
//    StackData.map(function, option);
//}
//template<class T, class Main>  void Stack<T, Main>::deleteOne(int index) {
//    StackData.deleteOne(index);
//}
//template<class T, class Main>  void Stack<T, Main>::where(bool (*function)(T data, int option), int option) {
//    StackData.where(function, option);
//}
//
//template<class T, class Main>  int Stack<T, Main>::getSize() {
//    return StackData.getSize();
//}
//template<class T, class Main> T Stack<T, Main>::getFirst() {
//    return StackData.getFirst();
//}
//template<class T, class Main>  void Stack<T, Main>::append(T data) {
//    StackData.prepend(data);
//}
//template<class T, class Main>  void Stack<T, Main>::prepend(T data) {
//    StackData.append(data);
//}
//template<class T, class Main>  T Stack<T, Main>::getLast()  {
//    return StackData.getLast();
//}
//
//
//template<class T, class Main>  Stack<T, Main>::~Stack(){


#endif //CPP_STACK_H

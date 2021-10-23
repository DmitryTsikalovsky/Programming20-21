//
// Created by al1enware on 29.05.2021.
//
#include <iostream>
#include "Sequence.h"
#include "Functions.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
#ifndef CPP_MENU_H
#define CPP_MENU_H

// Функция ввода одного элемента
int inputInt();

// Функция ввода одного элемента
double inputDouble();

// Функция ввода одного элемента
complexNumber inputComplex();

// Функция ввода одного элемента
// Меню для взаимодействия с объёктом класса через консоль
template<typename T> void menuInt(sequence<T>* Data);

template<typename T> void menuDouble(sequence<T>* Data);

template<typename T> void menuComplex(sequence<T>* Data);

template<typename T> void menuStudent(sequence<T>* Data);

void mainMenu();


#endif //CPP_MENU_H

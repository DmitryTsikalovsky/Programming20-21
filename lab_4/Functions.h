//
// Created by al1enware on 29.05.2021.
//
#include <iostream>
#include <string.h>
using namespace std;
#ifndef CPP_FUNCTIONS_H
#define CPP_FUNCTIONS_H

class student {
public:
    int age{};
    int group{};
    string name;
    student() {
        cout << "Введите имя:" << endl;
        cin >> this->name;
        cout << "Введите группу:" << endl;
        cin >> this->group;
        cout << "Введите возраст:" << endl;
        cin >> this->age;
    }
};



// Тип хранимых данных
struct complexNumber{
    double real;
    double image;
};

// функция обработки данных для where
bool whereint(int data, int option);

// функция обработки данных для where
bool wheredouble(double data, int option);

// функция обработки данных для where
bool wherecomplex(complexNumber data, int option);

// функция обработки данных для where
bool wherestudent(student data, int option);
// функция преобразования данных для map
int mapint(int data, int option);
// функция преобразования данных для map
double mapdouble(double data, int option);

// функция преобразования данных для map
complexNumber mapcomplex(complexNumber data, int option);

// функция преобразования данных для map
student mapstudent(student data, int option);



#endif //CPP_FUNCTIONS_H

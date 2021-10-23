//
// Created by al1enware on 29.05.2021.
//

#include "Functions.h"
// функция обработки данных для where
bool whereint(int data, int option) {
    if (data > option) {
        return true;
    } else {
        return false;
    }

}

// функция обработки данных для where
bool wheredouble(double data, int option) {
    if (data > option) {
        return true;
    } else {
        return false;
    }
}

// функция обработки данных для where
bool wherecomplex(complexNumber data, int option) {
    if (data.real > option && data.image > option) {
        return true;
    } else {
        return false;
    }
}

// функция обработки данных для where
bool wherestudent(student data, int option) {
    if (data.age> option) {
        return true;
    } else {
        return false;
    }
}

// функция преобразования данных для map
int mapint(int data, int option) {
    return data * option;
}

// функция преобразования данных для map
double mapdouble(double data, int option) {
    return data * option;
}

// функция преобразования данных для map
complexNumber mapcomplex(complexNumber data, int option) {
    data.real *= option;
    data.image *= option;
    return data;
}

// функция преобразования данных для map
student mapstudent(student data, int option) {
    data.age *= option;
    data.group *= option;
    return data;
}
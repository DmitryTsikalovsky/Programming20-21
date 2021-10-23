//
// Created by al1enware on 29.05.2021.
//
#include "Menu.h"

// Функция ввода одного элемента
int inputInt() {
    int output;
    cout << "Введите число:" << endl;
    cin >> output;
    return output;
}

// Функция ввода одного элемента
double inputDouble() {
    double output;
    cout << "Введите число:" << endl;
    cin >> output;
    return output;
}

// Функция ввода одного элемента
complexNumber inputComplex() {
    complexNumber output;
    cout << "Введите реальную часть:" << endl;
    cin >> output.real;
    cout << "Введите мнимую часть:" << endl;
    cin >> output.image;
    return output;
}

// Функция ввода одного элемента
// Меню для взаимодействия с объёктом класса через консоль
template<typename T> void menuInt(sequence<T>* Data){
    int option = -1;
    while(option != 10) {
        option = -1;
        cout << "Введите цифру необходимого вам пункта:" << endl;
        cout << "1)Добавить один элемент" << endl;
        cout << "2)Ввод определённого количества элементов" << endl;
        cout << "3)Установить элемент по индексу" << endl;
        cout << "4)Показать элемент по индексу" << endl;
        cout << "5)Показать количество элементов" << endl;
        cout << "6)Функция map" << endl;
        cout << "7)Функция Where" << endl;
        cout << "8)Получить подпоследовательность по индексам" << endl;
        cout << "9)Удалить элемент по индексу" << endl;
        cout << "10)Выход из меню" << endl;
        cin >> option;

        if (option > 0 && option < 10){
            switch (option) {
                case 1:
                    Data->append(inputInt());
                    cout << "Элемент добалвен" << endl;
                    break;
                case 2: {
                    int length = 0;
                    cout << "Введите количество элементов:" << endl;
                    cin >> length;
                    if (length < 1) {
                        cout << "Ошибка: количество элементов меньше 1" << endl;
                    } else {
                        for (int i = 0; i < length; ++i) {
                            Data->append(inputInt());
                            cout << "Элемент добалвен" << endl;
                        }
                    }
                    break;
                }
                case 3: {
                    int index = 0;
                    cout << "Введите индекс:" << endl;
                    cin >> index;
                    if (index > Data->getSize()) {
                        cout << "Ошибка: Вы ввели идекс, который выходит за область массива:" << endl;
                        break;
                    }
                    Data->set(index, inputInt());
                    cout << "Элемент добалвен" << endl;
                    break;
                }
                case 4:{
                    int index = 0;
                    cout << "Введите индекс:" << endl;
                    cin >> index;
                    if (index > Data->getSize()) {
                        cout << "Ошибка: Вы ввели идекс, который выходит за количество заполненных элеметов:" << endl;
                        break;
                    } else if (Data->getSize() > 0) {
                        cout << (*Data)[index] << endl;
                    } else {
                        cout << "Ошибка: Количество заполненных элеметов равно нулю" << endl;
                    }
                    break;
                }

                case 5:
                    cout << "Количество заполненных элементов:" << Data->getSize() << endl;
                    break;
                case 6:{
                    int number;

                    cout << "Введите число, на которое хотите умножить данные:" << endl;
                    cin >> number;
                    Data->map(mapint, number);
                    break;
                }

                case 7:{
                    int number;
                    cout << "Введите число, на которое хотите умножить данные:" << endl;
                    cin >> number;
                    Data->where(whereint, number);
                    break;
                }
                case 8:{
                    int index1;
                    int index2;

                    cout << "Введите начальный индекс:" << endl;
                    cin >> index1;
                    if (index1 < 0 && index1 > Data->getSize()) {
                        cout << "Ошибка: вы ввели индекс, который или меньше нуля, или выходит за область заполненных элеметов" << endl;
                        break;
                    }
                    cout << "Введите конечный индекс:" << endl;
                    cin >> index2;
                    if (index2 < 0 && index2 > Data->getSize() && index1 > index2) {
                        cout << "Ошибка: вы ввели индекс, который или меньше нуля, или выходит за область заполненных элеметов, или меньше начального индекса" << endl;
                        break;
                    }

                    DynamicArray<T> Sub;
                    Data->subSequence(index1,index2, &Sub);
                    for (int i = 0; i < Sub.getSize(); ++i) {
                        cout << Sub[i] << " ";
                    }
                    cout << endl;
                    break;
                }
                case 9:{
                    int index = 0;
                    cout << "Введите начальный индекс:" << endl;
                    cin >> index;
                    if (index < 0 && index > Data->getSize() && Data->getSize() == 0) {
                        cout << "Ошибка: вы ввели индекс, который или меньше нуля, или выходит за область заполненных элеметов" << endl;
                        break;
                    }
                    Data->deleteOne(index);
                    cout << "Элемент удалён" << endl;
                    break;
                }
            }
        } else if (option != 10){
            cout << "Пункта, имеющего данный номер не существует" << endl;
        }
    }
}

template<typename T> void menuDouble(sequence<T>* Data){
    int option = -1;
    while(option != 10) {
        option = -1;
        cout << "Введите цифру необходимого вам пункта:" << endl;
        cout << "1)Добавить один элемент" << endl;
        cout << "2)Ввод определённого количества элементов" << endl;
        cout << "3)Установить элемент по индексу" << endl;
        cout << "4)Показать элемент по индексу" << endl;
        cout << "5)Показать количество элементов" << endl;
        cout << "6)Функция map" << endl;
        cout << "7)Функция Where" << endl;
        cout << "8)Получить подпоследовательность по индексам" << endl;
        cout << "9)Удалить элемент по индексу" << endl;
        cout << "10)Выход из меню" << endl;
        cin >> option;

        if (option > 0 && option < 10){
            switch (option) {
                case 1:
                    Data->append(inputDouble());
                    cout << "Элемент добалвен" << endl;
                    break;
                case 2: {
                    int length = 0;
                    cout << "Введите количество элементов:" << endl;
                    cin >> length;
                    if (length < 1) {
                        cout << "Ошибка: количество элементов меньше 1" << endl;
                    } else {
                        for (int i = 0; i < length; ++i) {
                            Data->append(inputDouble());
                            cout << "Элемент добалвен" << endl;
                        }
                    }
                    break;
                }
                case 3: {
                    int index = 0;
                    cout << "Введите индекс:" << endl;
                    cin >> index;
                    if (index > Data->getSize()) {
                        cout << "Ошибка: Вы ввели идекс, который выходит за область массива:" << endl;

                    } else {
                        Data->set(index, inputDouble());
                        cout << "Элемент добалвен" << endl;
                    }
                    break;
                }
                case 4:{
                    int index = 0;
                    cout << "Введите индекс:" << endl;
                    cin >> index;
                    if (index > Data->getSize()) {
                        cout << "Ошибка: Вы ввели идекс, который выходит за количество заполненных элеметов:" << endl;
                    } else {
                        if (Data->getSize() > 0) {
                            cout << (*Data)[index] << endl;
                        } else {
                            cout << "Ошибка: Количество заполненных элеметов равно нулю" << endl;
                        }
                    }

                    break;
                }

                case 5:
                    cout << "Количество заполненных элементов:" << Data->getSize() << endl;
                    break;
                case 6:{
                    int number;

                    cout << "Введите число, на которое хотите умножить данные:" << endl;
                    cin >> number;
                    Data->map(mapdouble, number);
                    break;
                }

                case 7:{
                    int number;
                    cout << "Введите число, на которое хотите умножить данные:" << endl;
                    cin >> number;
                    Data->where(wheredouble, number);
                    break;
                }
                case 8:{
                    int index1;
                    int index2;

                    cout << "Введите начальный индекс:" << endl;
                    cin >> index1;
                    if (index1 < 0 && index1 > Data->getSize()) {
                        cout << "Ошибка: вы ввели индекс, который или меньше нуля, или выходит за область заполненных элеметов" << endl;

                    } else {
                        cout << "Введите конечный индекс:" << endl;
                        cin >> index2;
                        if (index2 < 0 && index2 > Data->getSize() && index1 > index2) {
                            cout << "Ошибка: вы ввели индекс, который или меньше нуля, или выходит за область заполненных элеметов, или меньше начального индекса" << endl;

                        } else {

                            DynamicArray<T> Sub;
                            Data->subSequence(index1,index2, &Sub);
                            for (int i = 0; i < Sub.getSize(); ++i) {
                                cout << Sub[i] << " ";
                            }
                            cout << endl;

                        }


                    }
                    break;
                }
                case 9:{
                    int index = 0;
                    cout << "Введите  индекс:" << endl;
                    cin >> index;
                    if (index > Data->getSize() || index < 0 || Data->getSize() == 0) {
                        cout << "Ошибка: вы ввели индекс, который или меньше нуля, или выходит за область заполненных элеметов" << endl;
                    } else {
                        Data->deleteOne(index);
                        cout << "Элемент удалён" << endl;
                    }

                    break;
                }
            }
        } else if (option != 10){
            cout << "Пункта, имеющего данный номер не существует" << endl;
        }
    }
}

template<typename T> void menuComplex(sequence<T>* Data){
    int option = -1;
    while(option != 10) {
        option = -1;
        cout << "Введите цифру необходимого вам пункта:" << endl;
        cout << "1)Добавить один элемент" << endl;
        cout << "2)Ввод определённого количества элементов" << endl;
        cout << "3)Установить элемент по индексу" << endl;
        cout << "4)Показать элемент по индексу" << endl;
        cout << "5)Показать количество элементов" << endl;
        cout << "6)Функция map" << endl;
        cout << "7)Функция Where" << endl;
        cout << "8)Получить подпоследовательность по индексам" << endl;
        cout << "9)Удалить элемент по индексу" << endl;
        cout << "10)Выход из меню" << endl;
        cin >> option;

        if (option > 0 && option < 10){
            switch (option) {
                case 1:
                    Data->append(inputComplex());
                    cout << "Элемент добалвен" << endl;
                    break;
                case 2: {
                    int length = 0;
                    cout << "Введите количество элементов:" << endl;
                    cin >> length;
                    if (length < 1) {
                        cout << "Ошибка: количество элементов меньше 1" << endl;
                    } else {
                        for (int i = 0; i < length; ++i) {
                            Data->append(inputComplex());
                            cout << "Элемент добалвен" << endl;
                        }
                    }
                    break;
                }
                case 3: {
                    int index = 0;
                    cout << "Введите индекс:" << endl;
                    cin >> index;
                    if (index > Data->getSize()) {
                        cout << "Ошибка: Вы ввели идекс, который выходит за область массива:" << endl;
                    } else {
                        Data->set(index, inputComplex());
                        cout << "Элемент добалвен" << endl;
                    }
                    break;
                }
                case 4:{
                    int index = 0;
                    cout << "Введите индекс:" << endl;
                    cin >> index;
                    if (index >= Data->getSize()) {
                        cout << "Ошибка: Вы ввели идекс, который выходит за количество заполненных элеметов:" << endl;
                    } else if (Data->getSize() > 0) {
                        cout << (*Data)[index].real << "+"<< (*Data)[index].image << "i " << endl;
                    } else {
                        cout << "Ошибка: Количество заполненных элеметов равно нулю" << endl;
                    }
                    break;
                }

                case 5:
                    cout << "Количество заполненных элементов:" << Data->getSize() << endl;
                    break;
                case 6:{
                    int number;

                    cout << "Введите число, на которое хотите умножить данные:" << endl;
                    cin >> number;
                    Data->map(mapcomplex, number);
                    break;
                }

                case 7:{
                    int number;
                    cout << "Введите число, на которое хотите умножить данные:" << endl;
                    cin >> number;
                    Data->where(wherecomplex, number);
                    break;
                }
                case 8:{
                    int index1;
                    int index2;

                    cout << "Введите начальный индекс:" << endl;
                    cin >> index1;
                    if (index1 < 0 && index1 > Data->getSize()) {
                        cout << "Ошибка: вы ввели индекс, который или меньше нуля, или выходит за область заполненных элеметов" << endl;

                    } else {
                        cout << "Введите конечный индекс:" << endl;
                        cin >> index2;
                        if (index2 < 0 && index2 > Data->getSize() && index1 > index2) {
                            cout << "Ошибка: вы ввели индекс, который или меньше нуля, или выходит за область заполненных элеметов, или меньше начального индекса" << endl;
                        } else {
                            DynamicArray<T> Sub;
                            Data->subSequence(index1,index2, &Sub);
                            for (int i = 0; i < Sub.getSize(); ++i) {
                                cout << Sub[i].real << "+";
                                cout << Sub[i].image << "i" << " ";
                            }
                            cout << endl;
                        }
                    }
                    break;
                }
                case 9:{
                    int index = 0;
                    cout << "Введите начальный индекс:" << endl;
                    cin >> index;
                    if (index > Data->getSize() || index < 0 || Data->getSize() == 0) {
                        cout << "Ошибка: вы ввели индекс, который или меньше нуля, или выходит за область заполненных элеметов" << endl;
                    } else {
                        Data->deleteOne(index);
                        cout << "Элемент удалён" << endl;
                    }

                    break;
                }
            }
        } else if (option != 10) {
            cout << "Пункта, имеющего данный номер не существует" << endl;
        }
    }
}

template<typename T> void menuStudent(sequence<T>* Data){
    int option = -1;
    while(option != 10) {
        option = -1;
        cout << "Введите цифру необходимого вам пункта:" << endl;
        cout << "1)Добавить один элемент" << endl;
        cout << "2)Ввод определённого количества элементов" << endl;
        cout << "3)Установить элемент по индексу" << endl;
        cout << "4)Показать элемент по индексу" << endl;
        cout << "5)Показать количество элементов" << endl;
        cout << "6)Функция map" << endl;
        cout << "7)Функция Where" << endl;
        cout << "8)Получить подпоследовательность по индексам" << endl;
        cout << "9)Удалить элемент по индексу" << endl;
        cout << "10)Выход из меню" << endl;
        cin >> option;

        if (option > 0 && option < 10){
            switch (option) {
                case 1: {
                    student Input;
                    Data->append(Input);
                    cout << "Элемент добалвен" << endl;
                    break;
                }
                case 2: {
                    int length = 0;
                    cout << "Введите количество элементов:" << endl;
                    cin >> length;
                    if (length < 1) {
                        cout << "Ошибка: количество элементов меньше 1" << endl;
                    } else {
                        for (int i = 0; i < length; ++i) {
                            student Input;
                            Data->append(Input);
                            cout << "Элемент добалвен" << endl;
                        }
                    }
                    break;
                }
                case 3: {
                    int index = 0;
                    cout << "Введите индекс:" << endl;
                    cin >> index;
                    if (index > Data->getSize()) {
                        cout << "Ошибка: Вы ввели идекс, который выходит за область массива:" << endl;
                    } else {
                        student Input;
                        Data->set(index, move(Input));
                        cout << "Элемент добалвен" << endl;
                    }
                    break;
                }
                case 4:{
                    int index = 0;
                    cout << "Введите индекс:" << endl;
                    cin >> index;
                    if (index >= Data->getSize()) {
                        cout << "Ошибка: Вы ввели идекс, который выходит за количество заполненных элеметов:" << endl;
                    } else if (Data->getSize() > 0) {
                        cout << " Возраст " << (*Data)[index].age<< " Группа " << (*Data)[index].group<< " Имя "<< (*Data)[index].name  << endl;

                    } else {
                        cout << "Ошибка: Количество заполненных элеметов равно нулю" << endl;
                    }
                    break;
                }

                case 5:
                    cout << "Количество заполненных элементов:" << Data->getSize() << endl;
                    break;
                case 6:{
                    int number;

                    cout << "Введите число, на которое хотите умножить данные:" << endl;
                    cin >> number;
                    Data->map(mapstudent, number);
                    break;
                }

                case 7:{
                    int number;
                    cout << "Введите число, на которое хотите умножить данные:" << endl;
                    cin >> number;
                    Data->where(wherestudent, number);
                    break;
                }
                case 8:{
                    int index1;
                    int index2;

                    cout << "Введите начальный индекс:" << endl;
                    cin >> index1;
                    if (index1 < 0 && index1 > Data->getSize()) {
                        cout << "Ошибка: вы ввели индекс, который или меньше нуля, или выходит за область заполненных элеметов" << endl;

                    } else {
                        cout << "Введите конечный индекс:" << endl;
                        cin >> index2;
                        if (index2 < 0 && index2 > Data->getSize() && index1 > index2) {
                            cout << "Ошибка: вы ввели индекс, который или меньше нуля, или выходит за область заполненных элеметов, или меньше начального индекса" << endl;
                        } else {
                            DynamicArray<T> Sub;
                            Data->subSequence(index1,index2, &Sub);
                            for (int index = 0; index < Sub.getSize(); ++index) {
                                cout << " Возраст " << (*Data)[index].age<< " Группа " << (*Data)[index].group<< " Имя "<< (*Data)[index].name  << endl;
                            }
                            cout << endl;
                        }
                    }
                    break;
                }
                case 9:{
                    int index = 0;
                    cout << "Введите начальный индекс:" << endl;
                    cin >> index;
                    if (index > Data->getSize() || index < 0 || Data->getSize() == 0) {
                        cout << "Ошибка: вы ввели индекс, который или меньше нуля, или выходит за область заполненных элеметов" << endl;
                    } else {
                        Data->deleteOne(index);
                        cout << "Элемент удалён" << endl;
                    }

                    break;
                }
            }
        } else if (option != 10) {
            cout << "Пункта, имеющего данный номер не существует" << endl;
        }
    }
}

void mainMenu(){
    int typeData;
    int typeClass;
    int subClass;
    cout << "Введите цифру необходимого типа данных: 1)Int 2)double 3)complex 4)student" << endl;
    cin >> typeData;
    cout << "Выберите тип класса: 1)List 2)Array 3)Stack 4)Queue" << endl;
    cin >> typeClass;
    if (typeClass > 2) {
        cout << "Введите цифру необходимого подкласса: 1)List 2)Array" << endl;
        cin >> subClass;
    }
    if (typeClass == 1) {
        if (typeData == 1) {
            LinkedList<int> Data;
            menuInt<int>(&Data);
        } else if(typeData == 2) {
            LinkedList<double> Data;
            menuDouble<double>(&Data);
        } else if (typeData == 3) {
            LinkedList<complexNumber> Data;
            menuComplex<complexNumber>(&Data);
        } else if (typeData == 4) {
            LinkedList<student> Data;
            menuStudent<student>(&Data);
        } else {
            cout << "Вы ввели число класса, которого не сущесвтует" << endl;
        }
    } else if(typeClass == 2) {
        if (typeData == 1) {
            DynamicArray<int> Data;
            menuInt<int>(&Data);
        } else if(typeData == 2) {
            DynamicArray<double> Data;
            menuDouble<double>(&Data);
        } else if (typeData == 3) {
            DynamicArray<complexNumber> Data;
            menuComplex<complexNumber>(&Data);
        } else if (typeData == 4) {
            DynamicArray<student> Data;
            menuStudent<student>(&Data);
        } else {
            cout << "Вы ввели число класса, которого не сущесвтует" << endl;
        }
    } else if (typeClass == 3) {
        if (typeData == 1 && subClass == 1) {
            Stack<int, LinkedList<int>> Data;
            menuInt<int>(&Data);
        } else if(typeData == 2 && subClass == 1) {
            Stack<double, LinkedList<double>> Data;
            menuDouble<double>(&Data);
        } else if (typeData == 3 && subClass == 1) {
            Stack<complexNumber, LinkedList<complexNumber>> Data;
            menuComplex<complexNumber>(&Data);
        } else if (typeData == 4 && subClass == 1) {
            Stack<student, LinkedList<student>> Data;
            menuStudent<student>(&Data);
        } else if(typeData == 1 && subClass == 2) {
            Stack<int, DynamicArray<int>> Data;
            menuInt<int>(&Data);
        }else if(typeData == 2 && subClass == 2) {
            Stack<double, DynamicArray<double>> Data;
            menuDouble<double>(&Data);
        } else if (typeData == 3 && subClass == 2) {
            Stack<complexNumber, DynamicArray<complexNumber>> Data;
            menuComplex<complexNumber>(&Data);
        } else if (typeData == 4 && subClass == 2) {
            Stack<student, DynamicArray<student>> Data;
            menuStudent<student>(&Data);
        }else {
            cout << "Вы ввели число класса, которого не сущесвтует" << endl;
        }
    } else if (typeClass == 4) {
        if (typeData == 1 && subClass == 1) {
            Queue<int, LinkedList<int>> Data;
            menuInt<int>(&Data);
        } else if(typeData == 2 && subClass == 1) {
            Queue<double, LinkedList<double>> Data;
            menuDouble<double>(&Data);
        } else if (typeData == 3 && subClass == 1) {
            Queue<complexNumber, LinkedList<complexNumber>> Data;
            menuComplex<complexNumber>(&Data);
        } else if (typeData == 4 && subClass == 1) {
            Queue<student, LinkedList<student>> Data;
            menuStudent<student>(&Data);
        } else if(typeData == 1 && subClass == 2) {
            Queue<int, DynamicArray<int>> Data;
            menuInt<int>(&Data);
        }else if(typeData == 2 && subClass == 2) {
            Queue<double, DynamicArray<double>> Data;
            menuDouble<double>(&Data);
        } else if (typeData == 3 && subClass == 2) {
            Queue<complexNumber, DynamicArray<complexNumber>> Data;
            menuComplex<complexNumber>(&Data);
        } else if (typeData == 4 && subClass == 2) {
            Queue<student, DynamicArray<student>> Data;
            menuStudent<student>(&Data);
        }else {
            cout << "Вы ввели число класса, которого не сущесвтует" << endl;
        }
    } else {
        cout << "Вы ввели число класса, которого не сущесвтует" << endl;
    }

}
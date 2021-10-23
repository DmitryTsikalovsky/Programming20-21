#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef DATATYPES_H
#define DATATYPES_H

typedef int (*funcPointer)(int a);

struct Floats {
    float *array;
    int length;
    int type;
};
struct complexNumber{
    double real;
    double image;
};

struct complexArray{
    struct complexNumber *array;
    int length;
    int type;
};

struct Functions {
    funcPointer *array;
    int length;
    int type;
};

struct Array {
    struct Floats *nums;
    struct Functions *func;
    struct complexArray *complex;
};
//Структура динамик аррау для одного типа данных внутри звёздочка, указатель на какие-то данные. поле с количеством и размером типа, капасити(размер массива)
struct Array *createArray(int len);
struct Floats *numsNew();
struct Functions *funcNew();
struct complexArray *complexNew();
void deleteArray(struct Array *ptr, int len);



#endif

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//#include "menu.h"
//
//int main()
//{   struct Array *arr = (struct Array *) calloc(1, sizeof(struct Array));
//    printf("Проверка № 1 на корректность ввода.\nНеобходимо ввести в каждый тип данных 1 (для функций sum)\n");
//    getData(arr);
//    getData(arr);
//    getData(arr);
//    float a = 1;
//    double b = 1;
//    assert( (arr->nums->array)[0] == a);
//    assert( (arr->func->array)[0] == sum);
//    assert( (arr->complex->array)[0].real == b);
//    assert( (arr->complex->array)[0].image == b);
//    printf("Проверка пройдена\n");
//    printf("Проверка № 2 на работу функции add one.\nВведите для элементов каждого типа данных 2 (для функий difference)\n");
//    addOne(arr);
//    addOne(arr);
//    addOne(arr);
//    assert( (arr->nums->array)[1] == ++a);
//    assert( (arr->func->array)[1] == sum);
//    assert( (arr->complex->array)[1].real == ++b);
//    assert( (arr->complex->array)[1].image == b);
//    printf("Проверка пройдена\n");
//    printf("Проверка № 3 на работу функции map.\nВыберите тип данных float, а затем complex\n");
//    map(arr, &plus);
//    map(arr, &plus);
//    a = 2;
//    b = 2;
//    assert( (arr->nums->array)[0] == a);
//    assert( (arr->nums->array)[1] == a*2);
//    assert( (arr->complex->array)[0].real == b);
//    assert( (arr->complex->array)[0].image == b);
//    assert( (arr->complex->array)[1].real == b*2);
//    assert( (arr->complex->array)[1].image == b*2);
//    printf("Проверка пройдена\n");
//    printf("Проверка № 4 на работу функции where.\nВыберите тип данных float, а затем complex\n");
//    where(arr, &bool);
//    where(arr, &bool);
//    a = 4;
//    b = 4;
//    assert( (arr->nums->array)[0] == a);
//    assert( (arr->complex->array)[0].real == b);
//    assert( (arr->complex->array)[0].image == b);
//    printf("Проверка пройдена\n");
//    printf("Проверка № 5 на работу функции concatenation.\nДобавьте к каждому типу данных по 2 элемента: 3, 2 (для функций multiplication и difference)\n");
//    concatenation(arr);
//    concatenation(arr);
//    concatenation(arr);
//    a = 3;
//    b = 3;
//    assert( (arr->nums->array)[1] == a);
//    assert( (arr->nums->array)[2] == a-1);
//    assert( (arr->complex->array)[1].real == b);
//    assert( (arr->complex->array)[1].image == b);
//    assert( (arr->complex->array)[2].real == b-1);
//    assert( (arr->complex->array)[2].image == b-1);
//    printf("Проверка пройдена\n");
//    deleteArray(arr, 1);
//
//    return 0;
//}
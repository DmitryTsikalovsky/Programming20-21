
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datatypes.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int difference(int a);
int sum(int a);
int multiplication(int a);
void concatenation(struct Array *Array);
void addOne(struct Array *Array);
void getData(struct Array *Array);
void map(struct Array *arr);
void where(struct Array *arr);
void plus(void *arr,int i, int type);
int bool1(void *arr, int i, int type);
int bool2(void *arr, int i, int type);
int bool3(void *arr, int i, int type);
typedef void (*comparisonPointer)(void *arr,int i, int type);
typedef int(*boolPointer)(void *arr, int i, int type);

void division(void *arr,int i, int type);
void square(void *arr,int i, int type);
void printData(struct Array *arr);

#endif

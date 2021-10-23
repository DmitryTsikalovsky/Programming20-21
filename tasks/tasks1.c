#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int *numbersArray){
    int i = 0;

    printf("Массив:");
    while (numbersArray[i]){
        printf("%d ",numbersArray[i]);
        i++;
    }
    printf("\n");
}
//1.1 -> Написать функцию удаления всех чётных чисел из массива
int *evenDelete(int *numbersArray, int arrayLength){
    int *newArray = (int*)calloc(arrayLength + 1, sizeof(int));
    int k = 0;

    for (int i = 0; i < arrayLength; ++i) {
        if (numbersArray[i] % 2 > 0){
            newArray[k] = numbersArray[i];
            k++;
        }
    }
    return newArray;
}
//1.2 -> Написать функцию поиска наибольшего и наименьшего числа в массиве
int *smallBigSearch(int *numbersArray, int arrayLength){
    int small = numbersArray[0];
    int big = numbersArray[0];

    for (int i = 0; i < arrayLength; ++i) {
        if (big < numbersArray[i]){
            big = numbersArray[i];
        }
        if(small > numbersArray[i]){
            small = numbersArray[i];
        }
    }

    int *parametrs = (int*)calloc(2, sizeof(int));
    parametrs[0] = big;
    parametrs[1] = small;
    return  parametrs;
}
//1.3 -> Написать функцию реверсирования строки
char *stringReverse(char *string, int stringLength){
    char *reverseString = (char*)calloc(stringLength + 1, sizeof(char));
    int k = 0;

    for(int i = stringLength; i - 1 > 0 ; --i) {
        reverseString[k]= string[i-2];
        k++;
    }
    return reverseString;
}
//1.4 -> Написать функцию бинарного поиска в отсортированном массиве
int binarySearch(int key, int min, int max, int *sortArray){
    int midIndex;
    do {
        midIndex = floor((min + max)/2);
        if (sortArray[midIndex] > key){
            max = midIndex;
        } else if (sortArray[midIndex] < key){
            min = midIndex;
        }
    } while (sortArray[midIndex] != key && min != max);
    if (sortArray[midIndex] != key) {
        return NULL;
    } else {
        return midIndex;
    }
}

int main(){
    int numbersArray[] = {5, 4, 6, 3, 7, 2, 8, 1, 9, 0};
    int arrayLength = sizeof(numbersArray)/sizeof(int);
    int *evenArray = evenDelete(numbersArray, arrayLength);
    printArray(evenArray);
    free(evenArray);

    int *bigSmall = smallBigSearch(numbersArray, arrayLength);
    printf("Наибольшее %d Наименьшее %d \n", bigSmall[0], bigSmall[1]);
    free(bigSmall);

    char normalString[]="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce rhoncus est vel nisi dignissim, ac venenatis purus iaculis.";
    int stringLength = sizeof(normalString)/sizeof(char);
    char *newString = stringReverse(normalString, stringLength);
    printf("%s \n", newString);
    free(newString);

    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int sortLength = sizeof(sortedArray)/sizeof(int);
    int searchIndex = binarySearch(7, 0, sortLength, sortedArray);
    if (searchIndex == NULL){
        printf("Число не найдетно \n");
    } else {
        printf("Число находится под индексом %d \n", searchIndex);
    }
}
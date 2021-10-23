#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Array {
    void *data;
    size_t size;
    int len;
    int type;

};

struct Array* new(){
    return (struct Array *)calloc(1,sizeof(struct Array));
}

void makeData(struct Array *arr){
    int choise;
    int len;
    printf("Введите тип 1 для интов 2 для флоатов\n");
    scanf("%d", &choise);
    printf("Введите количество элементов:\n");
    scanf("%d", &len);
    if (choise == 1){
        arr->len = len;
        arr->size = sizeof(int);
        arr->type = 1;
        arr->data = calloc(len, arr->size);

        for (int i = 0; i < arr->len; ++i) {
            scanf("%d", &((int*)arr->data)[i]);
        }
    } else if (choise == 2){
        arr->len = len;
        arr->size = sizeof(float);
        arr->type = 2;
        arr->data = calloc(len, arr->size);

        for (int i = 0; i < arr->len; ++i) {
            scanf("%f", &((float*)arr->data)[i]);
        }
    }
}

void printData1(struct Array *arr){
    if (arr->type == 1){

        for (int i = 0; i < arr->len; ++i) {
            printf("%d", ((int*)arr->data)[i]);
        }
    } else if (arr->type == 2){
        for (int i = 0; i < arr->len; ++i) {
            printf("%f", ((float*)arr->data)[i]);
        }
    }
}

void map(struct Array *arr, len) {
        for(int i = 0; i < len; i++) {
                for (int j = 0; j < arr[i].len; ++j) {
                    arr[i].data[j] =  arr[i].data[j] * 2;
                }
            }

        }
}

int main(){
    struct Array *Integer = new();
    struct Array *Float = new();
    struct Array *Array = new();
    makeData(Integer);
    makeData(Float);
    printData1(Integer);
    printData1(Float);
    Array->data = calloc(2, sizeof (struct Array));
    Array->type = 3;
    Array->len = 2;
    Array->size = sizeof(struct Array);
    memcpy(Array->data + 1 * Array->size, Integer, Array->size);
    memcpy(Array->data + 2 * Array->size, Float, Array->size);
   


}
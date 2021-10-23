#include "datatypes.h"

struct Array *createArray(int len) {
    return (struct Array *) calloc(len, sizeof(struct Array));
}

struct Floats *numsNew() {
    return (struct Floats *) calloc(1, sizeof(struct Floats));
}

struct Functions *funcNew() {
    return (struct Functions *) calloc(1, sizeof(struct Functions));
}

struct complexArray *complexNew() {
    return (struct complexArray *) calloc(1, sizeof(struct complexArray));
}

void deleteArray(struct Array *Array, int len) {
    struct Array *ptr;
    for (int i = 0; i < len; i++) {
        ptr = &Array[i];
        if (ptr->nums){
            free(ptr->nums->array);
            free(ptr->nums);
        }
        if (ptr->func){
            free(ptr->func->array);
            free(ptr->func);
        }
        if (ptr->complex){
            free(ptr->complex->array);
            free(ptr->complex);
        }
    }

    free(Array);
}
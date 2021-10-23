#include "functions.h"

int difference(int a){
    return a - a;
}

int sum(int a){
    return a + a;
}
int multiplication(int a){
    return a * a;
}




//Осуществляет добавление новых данных по заданному количеству к выбранному пользователем данным
void concatenation(struct Array *Array){
    int n, type;
    printf("Enter a number of elements: ");
    scanf("%d", &n);
    if (n == 0){
        return;
    }
    printf("Select type of elements: \n1)float\n2)functions\n3)complex\n ");
    scanf("%d", &type);

    if(type == 1){
        if (Array->nums == NULL){
            Array->nums = numsNew();
            Array->nums->type = type;
            Array->nums->length = 0;
            Array->nums->array = calloc(n, sizeof(float ));
        } else {
            Array->nums->array = realloc(Array->nums->array, (Array->nums->length + n) * sizeof(float ));
        }

        for (int i = 0; i < n; i++) {
            printf("Enter an element: ");
            scanf("%f", &((Array->nums->array)[Array->nums->length + i]));
            printf("%d element added successfully!\n", i+1);
        }
        Array->nums->length += n;

        printf("input finished!\n");
    } else if (type == 2) {
        if (Array->func == NULL){
            Array->func = funcNew();
            Array->func->type = type;
            Array->func->length = 0;
            Array->func->array = calloc(n, sizeof(funcPointer ));
        } else {
            Array->func->array = realloc(Array->func->array, (Array->func->length + n) * sizeof(funcPointer ));
        }
        funcPointer funcArray[3];
        funcArray[0] = sum;
        funcArray[1] = difference;
        funcArray[2] = multiplication;

        int choise;
        int i = 0;
        while( i < n) {
            printf("Select type of %d function:\n1)sum\n2)difference\n3)multiplication\n", i+1);
            scanf("%d", &choise);
            if ( 0 < choise && choise < 4){
                (Array->func->array)[i + Array->func->length] = funcArray[choise-1];
                printf("%d element added successfully!\n", i+1);
                i++;
            } else {
                printf("Incorrect input\n");
            }

        }
        Array->func->length += n;

    } else if (type == 3){
        if (Array->complex == NULL){
            Array->complex = complexNew();
            Array->complex->type = type;
            Array->complex->length = 0;
            Array->complex->array = calloc(n, sizeof(struct complexNumber ));
        } else {
            Array->complex->array =  realloc(Array->complex->array, (Array->complex->length + n) * sizeof(struct complexNumber ));
        }

        int choise = 3;
        int i = 0;
        while(i < n) {
            printf("Enter real element: ");
            scanf("%lf", &((Array->complex->array)[i + Array->complex->length ].real));
            printf("Enter image element: ");
            scanf("%lf", &((Array->complex->array)[i + Array->complex->length].image));
            if ((Array->complex->array)[i + Array->complex->length].image != 0){
                printf("%d element added successfully!\n", i+1);
                i++;
            } else {
                printf("Entered number is not complex\nIf you want to keep the number enter 1, if you want to delete enter 0");
                while (choise > 1 || choise < 0)
                    scanf("%d", &choise);
                if (choise == 0){

                } else if (choise == 1){
                    i++;
                } else{
                    printf("Incorrect input. Try again.\n");
                }
            }

        }
        Array->complex->length += n;
        printf("input finished!\n");
    } else {
        printf("input type is incorrect\n");
    }

}

//Осуществляет добавление ОДНОГО элемента к выбранному пользователем данным
void addOne(struct Array *Array){
    int type = 0;
    while (type < 1 || type > 3){
        printf("Enter type of element, whitch you want to add:\n 1)Float\n2)Function\n3)Complex\n");
        scanf("%d", &type);
    }

    int success = 0;
    if (type == 1){
        if (Array->nums == NULL) {
            Array->nums = numsNew();
            Array->nums->length = 1;
            Array->nums->array = calloc(Array->nums->length, sizeof(float ));
            printf("Enter an element: ");
            scanf("%f", &((Array->nums->array))[0]);
            printf("element added successfully!\n");

        } else {
            float *new = calloc(Array->nums->length + 1, sizeof(float));
            int i = 0;
            for (i; i < Array->nums->length; i++) {
                new[i] = (Array->nums->array)[i];
            }
            printf("Enter an element: ");
            scanf("%f", &(new)[i]);
            printf("element added successfully!\n");
            free(Array->nums->array);
            Array->nums->array = new;
            Array->nums->length += 1;
        }
    } else if (type == 2){
        funcPointer funcArray[3];
        funcArray[0] = sum;
        funcArray[1] = difference;
        funcArray[2] = multiplication;
        int choise;
        if (Array->func == NULL){
            Array->func = funcNew();
            Array->func->length = 1;
            Array->func->array = calloc(Array->func->length, sizeof(funcPointer));

            while (success == 0) {
                printf("Select type of function:\n1)sum\n2)difference\n3)multiplication\n");
                scanf("%d", &choise);
                if ( 0 < choise && choise < 4) {
                    (Array->func->array)[0] = funcArray[choise-1];
                    printf("element added successfully!\n");
                    success = 1;
                } else {
                    printf("Incorrect input\n");
                }
            }
        } else {
            funcPointer *new = calloc(Array->func->length + 1, sizeof(funcPointer));
            int i = 0;
            for (i; i < Array->func->length; i++) {
                new[i] = ((funcPointer *)(Array->func->array))[i];
            }
            while (success == 0){
                printf("Select type of function:\n1)sum\n2)difference\n3)multiplication\n");
                scanf("%d", &choise);
                if (  0 < choise && choise < 4){
                    new[i] = funcArray[choise-1];
                    printf("element added successfully!\n");
                    success = 1;
                } else {
                    printf("Incorrect input\n");
                }
                free(Array->func->array);
                Array->func->array = new;
                Array->func->length += 1;
            }
        }
    } else if (type == 3){
        if (Array->complex == NULL){
            Array->complex = complexNew();
            Array->complex->length = 1;
            Array->complex->array = calloc(Array->complex->length, sizeof(struct complexNumber));

            printf("Enter real element: ");
            scanf("%lf", &((Array->complex->array)[0].real));
            printf("Enter image element: ");
            scanf("%lf", &((Array->complex->array)[0].image));
            printf("element added successfully!\n");

        } else {
            struct complexNumber *new = calloc(Array->complex->length + 1, sizeof(struct complexNumber));
            int i = 0;
            for (i; i < Array->complex->length; i++) {
                new[i] = (Array->complex->array)[i];
            }
            printf("Enter real element: ");
            scanf("%lf", &(new[i].real));
            printf("Enter image element: ");
            scanf("%lf", &(new[i].image));
            printf("element added successfully!\n");
            free(Array->complex->array);
            Array->complex->array = new;
            Array->complex->length += 1;
        }
    } else {
        printf("input type is incorrect\n");
    }
}


//Осуществляет добавление новых данных с указанием количества и типа данных. При повторном использовании на заполненный тип данных, заменяет текущие данные новыми.
void getData(struct Array *Array) {
    int n, type;
    printf("Enter a number of elements: ");
    scanf("%d", &n);
    if(n == 0) return;
    printf("Select type of elements: \n1)float\n2)functions\n3)complex\n ");
    scanf("%d", &type);

    if(type == 1){
        if (Array->nums != NULL) {
            if(Array->nums->array) {
                free(Array->nums->array);
                Array->nums->array = NULL;
            }
        } else{
            Array->nums = numsNew();
        }
        Array->nums->length = n;
        Array->nums->type = type;
        Array->nums->array = calloc(Array->nums->length, sizeof(float ));
        for (int i = 0; i < Array->nums->length; i++) {
            printf("Enter an element: ");
            scanf("%f", &((Array->nums->array)[i]));
            printf("%d element added successfully!\n", i+1);
        }
    } else if (type == 2) {
        if (Array->func != NULL) {
            if(Array->func->array) {
                free(Array->func->array);
                Array->func->array = NULL;
            }
        } else{
            Array->func = funcNew();
        }

        Array->func->length = n;
        Array->func->type= type;
        Array->func->array = calloc(Array->func->length,  sizeof(funcPointer));
        funcPointer funcArray[3];
        funcArray[0] = sum;
        funcArray[1] = difference;
        funcArray[2] = multiplication;
        int choise;
        int i = 0;
        while( i < Array->func->length) {
            printf("Select type of %d function:\n1)sum\n2)difference\n3)multiplication\n", i+1);
            scanf("%d", &choise);
            if ( 0 < choise && choise < 4){

                ((funcPointer*)Array->func->array)[i]  = funcArray[choise-1];
                printf("%d element added successfully!\n", i+1);
                i++;
            } else {
                printf("Incorrect input\n\n");
            }

        }

    } else if (type == 3){
        if (Array->complex != NULL) {
            if(Array->complex->array) {
                free(Array->complex->array);
                Array->complex->array = NULL;
            }
        } else{
            Array->complex = complexNew();
        }

        Array->complex->length = n;
        Array->complex->type = type;
        Array->complex->array = calloc(Array->complex->length,  sizeof(struct complexNumber));
        int choise = 3;
        int i = 0;
        while(i < Array->complex->length) {
            printf("Enter real element: ");
            scanf("%lf", &((Array->complex->array)[i].real));
            printf("Enter image element: ");
            scanf("%lf", &((Array->complex->array)[i].image));
            if ((Array->complex->array)[i].image != 0){
                printf("%d element added successfully!\n", i+1);
                i++;
            } else {
                printf("Entered number is not complex\nIf you want to keep the number enter 1, if you want to delete enter 0\n");
                while (choise > 1 || choise < 0)
                    scanf("%d", &choise);
                if (choise == 0){

                } else if (choise == 1){
                    i++;
                } else{
                    printf("Incorrect input. Try again.\n");
                }
            }

        }

    } else {
        printf("input type is incorrect\n\n");
    }
    printf("input finished!\n\n");


}

//Осущетвляет обработку данных выбранного пользователем типа и способом обработки. Полученные данные записываются вместо текущих.
void map(struct Array *arr) {
    int type, functype = 0;
    printf("Select type of elements: \n1)float\n2)functions\n3)complex\n ");
    scanf("%d", &type);
    while (functype > 3 || functype < 1){
        printf("Select type of map function: \n1)sum\n2)multiplication\n3)division\n");
        scanf("%d", &functype);
    }
    comparisonPointer map[3];
    map[0] = plus;
    map[1] = square;
    map[2] = division;

    if (type == 1){
        if (arr->nums == NULL) {
            printf("Array is empty\n");
            return;
        }
        int len = arr->nums->length;
        for(int i = 0; i < len; i++) {
            map[functype-1](arr->nums->array,i, arr->nums->type);
        }
    } else if (type == 3){
        if (arr->complex == NULL) {
            printf("Array is empty\n");
            return;
        }
        int len = arr->complex->length;
        for(int i = 0; i < len; ++i) {
            map[functype-1](arr->complex->array,i, arr->complex->type);
        }
    }else {
        printf("Invalid data type specified\n");
    }
}

//Осуществляет фильтрацию выбранного пользователем типа данных по выбранному условию. Результат фильтрации записывается на место выбранных выбранного типа
void where(struct Array *arr) {
    int type, functype = 0;
    printf("Select type of elements: \n1)float\n2)functions\n3)complex\n ");
    scanf("%d", &type);
    while (functype > 3 || functype < 1){
        printf("Select type of map function: \n1)more than 1\n2)more than 2\n3)more than 3\n");
        scanf("%d", &functype);
    }

    boolPointer wherePointer[3];
    wherePointer[0] = bool1;
    wherePointer[1] = bool2;
    wherePointer[2] = bool3;
    if (type == 1) {
        if (arr->nums == NULL) {
            printf("Array is empty\n");
            return;
        }
        int len = arr->nums->length;
        float *where = calloc(len, sizeof(float));
        int k = 0;

        for (int i = 0; i < len; ++i) {
            if ( wherePointer[functype-1](arr->nums->array, i, arr->nums->type)) {
                where[k] = ((float *) arr->nums->array)[i];
                k++;
            }

        }
        arr->nums->length = k;
        free(arr->nums->array);
        arr->nums->array = where;
        return;
    } else if (type == 3){
        if (arr->complex == NULL) {
            printf("Array is empty\n");
            return;
        }
        int len = arr->complex->length;
        struct complexNumber *where = calloc(len, sizeof(struct complexNumber));
        int k = 0;

        for(int i = 0; i < len; ++i) {
            if (wherePointer[functype-1](arr->complex->array,i, arr->complex->type) == 1){
                where[k].real = arr->complex->array[i].real;
                where[k].image = arr->complex->array[i].image;
                k++;
            }
        }
        arr->complex->length = k;
        free(arr->complex->array);
        arr->complex->array = where;
        return;
    } else {
        printf("Invalid data type specified\n\n");
        return;
    }
}

//функция используется внутри map. Является одним из условий обработки. Для пользователя не доступна
void plus(void *arr,int i, int type){
    if (type == 1){
        ((float*)arr)[i]  = (((float*)arr)[i] + ((float*)arr)[i]);
        return;
    } else if (type == 3) {
        ((struct complexNumber*)arr)[i].real =  ((struct complexNumber*)arr)[i].real + ((struct complexNumber*)arr)[i].real;
        ((struct complexNumber*)arr)[i].image =  ((struct complexNumber*)arr)[i].image + ((struct complexNumber*)arr)[i].image;
        return;
    }
    return;
}


//функция используется внутри map. Является одним из условий обработки. Для пользователя не доступна
void square(void *arr,int i, int type){
    if (type == 1){
        ((float*)arr)[i]  = (((float*)arr)[i] * ((float*)arr)[i]);
        return;
    } else if (type == 3) {
        ((struct complexNumber*)arr)[i].real =  ((struct complexNumber*)arr)[i].real * ((struct complexNumber*)arr)[i].real;
        ((struct complexNumber*)arr)[i].image =  ((struct complexNumber*)arr)[i].image * ((struct complexNumber*)arr)[i].image;
        return;
    }
    return;
}

//функция используется внутри map. Является одним из условий обработки. Для пользователя не доступна
void division(void *arr,int i, int type){
    if (type == 1){
        ((float*)arr)[i]  = (((float*)arr)[i] / 2);
        return;
    } else if (type == 3) {
        ((struct complexNumber*)arr)[i].real =  ((struct complexNumber*)arr)[i].real / 2;
        ((struct complexNumber*)arr)[i].image =  ((struct complexNumber*)arr)[i].image / 2;
        return;
    }
    return;
}

//функция используется внутри where. Является одним из условий обработки. Для пользователя не доступна
int bool1(void *arr, int i, int type){
    if (type == 1){
        float *floatPtr = (float*)arr;
        if (floatPtr[i] > 1){
            return 1;
        } else{
            return 0;
        }
    }
    if (type == 3){
        if ( ((struct complexNumber*)arr)[i].real > 1 ){
            return 1;
        } else{
            return 0;
        }
    }
    return 0;
}

//функция используется внутри where. Является одним из условий обработки. Для пользователя не доступна
int bool2(void *arr, int i, int type){
    if (type == 1){
        float *floatPtr = (float*)arr;
        if (floatPtr[i] > 2){
            return 1;
        } else{
            return 0;
        }
    }
    if (type == 3){
        if ( ((struct complexNumber*)arr)[i].real > 2 ){
            return 1;
        } else{
            return 0;
        }
    }
    return 0;
}

//функция используется внутри where. Является одним из условий обработки. Для пользователя не доступна
int bool3(void *arr, int i, int type){
    if (type == 1){
        float *floatPtr = (float*)arr;
        if (floatPtr[i] > 3){
            return 1;
        } else{
            return 0;
        }
    }
    if (type == 3){
        if ( ((struct complexNumber*)arr)[i].real > 3 ){
            return 1;
        } else{
            return 0;
        }
    }
    return 0;
}

//Выводит в консоль содержимое выбранного типа данных
void printData(struct Array *arr) {
    int type;
    if (arr == NULL) {
        printf("Array is empty\n");
        return;
    } else{
        printf("Whitch type you want to print?\n 1)float\n2)functions\n3)complex\n");
        scanf("%d", &type);
    }
    if (type == 1){
        if (arr->nums == NULL) {
            printf("Array is empty\n");
            return;
        }
        printf("\n\n");
        for (int i = 0; i < arr->nums->length; i++) {
            printf("%f | ", ((float *)(arr->nums->array))[i]);
        }
        printf("\n\n");
    } else if(type == 3){
        if (arr->complex == NULL) {
            printf("Array is empty\n");
            return;
        }
        printf("\n\n");
        for (int i = 0; i < arr->complex->length; i++) {
            printf("%lf", (arr->complex->array)[i].real);
            if ((arr->complex->array)[i].image > 0){
                printf("+");
            }
            printf("%lf i | ", (arr->complex->array)[i].image);
        }
        printf("\n\n");
    } else {
        printf("This data type does not exist or cannot be printed\n\n");
        return;
    }

}
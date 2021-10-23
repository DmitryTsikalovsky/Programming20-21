#include "menu.h"

void menu(struct Array *arr){

    int z = 0;
    int type = 0;
    do {
        printf("Choose one of the options:\n1)Add new data\n2)Print data\n3)Add one element to data\n4)Concatenate data\n5)Use \"map\" function\n6)Use \"where\" function\n7)Go to next item\n");
        scanf("%d", &z);
        switch (z) {
            case 1:
                getData(arr);
                break;
            case 2:
                printData(arr);
                break;
            case 3:
                addOne(arr);
                break;
            case 4:
                concatenation(arr);
                break;
            case 5:
                map(arr);
                break;
            case 6:
                where(arr);
                break;
        }
        if (z > 7 || z < 1 ){
            printf("Incorrect menu input. Try again\n");
        }
    } while(z != 7);
}
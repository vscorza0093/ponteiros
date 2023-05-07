#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void itemsToSwap(int array[]){
    for (int i = 0; i < 4; i = i + 2){
        swap((array + i), (array + i + 1));
    }

    for (int i = 0; i < 5; i++){
        printf("%d", array[i]);
    }
}

int main(void){
    int myAge = 30;
    int num = 10;
    int index = num;
    printf("num %d\nend de memoria %d\n", num, index);
    int* memoryAddress = &num;
    printf("num %d\nend de memoria %d\n", num, memoryAddress);
    int array[5] = {1, 2, 3, 4, 5};
    itemsToSwap(array);
    printf("\n");
    printf("Array0: %hx\n", array);
    printf("Array1: %hx\n", &num);
    printf("Array2: %hx\n", &array[0]);
    printf("Array3: %p\n", &num);
    printf("Array3: %d\n", &num);
    printf("%p\n", memoryAddress);
    printf("%p", &myAge);
}
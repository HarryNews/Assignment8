/* Harry Brickner
Generates an array and then sorts it */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], unsigned int length, int ascending){
    for(int loops = 1; loops < length; loops++){
        for(int i = 0; i < length - loops; i++){
            if((array[i] > array[i + 1]) == ascending){
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

int main(){
    printf("How long should the array be?\n");
    unsigned int length;
    scanf("%u", &length);
    int* unsorted = malloc(length * sizeof(int));
    int* ascending = malloc(length * sizeof(int));
    int* descending = malloc(length * sizeof(int));
    srand(time(0));
    for(int i = 0; i < length; i++){
        unsorted[i] = rand() % 100;
        ascending[i] = unsorted[i];
        descending[i] = unsorted[i];
    }
    bubbleSort(ascending, length, 1);
    bubbleSort(descending, length, 0);
    for(int i = 0; i < length; i++)
        printf("%d ", unsorted[i]);
    printf("\n");
    for(int i = 0; i < length; i++)
        printf("%d ", ascending[i]);
    printf("\n");
    for(int i = 0; i < length; i++)
        printf("%d ", descending[i]);
    printf("\n");
    free(unsorted);
    free(ascending);
    free(descending);
    return 0;
}

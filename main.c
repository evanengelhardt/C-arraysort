#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int * pArray, int howMany);
void quickSort(int * pArray, int start, int end);
void swap(int *x, int *y);

int main()
{
    int i, howMany;
    int * pArrayToSort;
    char typeOfSort;

    printf("How many numbers would you like to sort?\n");
    scanf(" %d", &howMany);

    pArrayToSort = (int *) malloc(howMany * sizeof(int));

    printf("Enter each number followed by clicking enter\n");

    for(i = 0 ; i < howMany ; i++){
        scanf(" %d", &pArrayToSort[i]);
    }

    printf("here are your unsorted numbers numbers\n");

    for(i = 0 ; i < howMany ; i++){
        printf("%d ", *(pArrayToSort + i));
    }

    printf("\nWhat type of sort would you like to do?\nType b for bubblesort\nType q for quicksort\nType m for mergesort\n");
    scanf(" %c", &typeOfSort);

    printf("\nYou chose the %c sort\n", typeOfSort);

    switch(typeOfSort){
        case 'b' :
            bubbleSort(pArrayToSort, howMany);
            break;
        case 'q' :
            quickSort(pArrayToSort, 0, howMany - 1);
            break;
        default:
            printf("No Correct Sort Chosen\n");
    }


    printf("Sorted Array\n");

    for(i = 0 ; i < howMany ; i++){
        printf("%d ", *(pArrayToSort + i));
    }


    return 0;
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}

void bubbleSort(int * pArray, int howMany){
    int i;
    int j;
    for(i = 0 ; i < howMany - 1 ; i++){
        for(j = 0 ; j < howMany - 1 ; j++){
            if(*(pArray + j) > *(pArray + j + 1)){
                swap((pArray + j), (pArray+j+1));
            }
        }
    }
    return;
}

void quickSort(int * pArray, int start, int end){
    if(start < end){
        int pivot = *(pArray + end);
        int swapPos = start-1;
        int i;
        for(i = start; i < end ; i++){
            if(*(pArray + i) < pivot){
                swapPos++;
                swap((pArray + i), (pArray + swapPos));
            } else {
                continue;
            }
        }
        printf("Out of loop");
        swapPos++;
        swap((pArray + swapPos), (pArray + i));
        if(start < swapPos - 1){
            quickSort(pArray, start, swapPos - 1);
        }
        if(swapPos + 1 < end){
            quickSort(pArray, swapPos + 1, end);
        }
    }

    return;
}

void mergeSort(int * pArray, int start, int end){

}



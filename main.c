#include <stdio.h>
#include <stdlib.h>

void getArray();
void bubbleSort(int * pArray, int howMany);
void quickSort(int * pArray, int start, int end);
void mergeSort(int* pArray, int length);
void mergeSortHelp(int * pArray, int * pTempArray, int start, int end);
void merge(int * pArray, int * pTempArray, int leftStart, int mid, int rightEnd);
void swap(int *x, int *y);

int i, howMany;
int * pArrayToSort;
char typeOfSort;


int main()
{

    getArray();

    switch(typeOfSort){
        case 'b' :
            printf("Using bubblesort\n");
            bubbleSort(pArrayToSort, howMany);
            break;
        case 'q' :
            printf("Using quicksort\n");
            quickSort(pArrayToSort, 0, howMany - 1);
            break;
        case 'm' :
            printf("Using mergesort\n");
            mergeSort(pArrayToSort, howMany);
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

/*
getArray
communicates with the user and takes the input of
array size, array contents, and type of sorting to proceed with
*/
void getArray(){
    printf("How many numbers would you like to sort?\n");
    scanf(" %d", &howMany);

    pArrayToSort = (int *) malloc(howMany * sizeof(int));

    printf("\nEnter each number followed by clicking enter\n");
    for(i = 0 ; i < howMany ; i++){
        scanf(" %d", &pArrayToSort[i]);
    }

    printf("\n\nHere are your unsorted numbers numbers\n");
    for(i = 0 ; i < howMany ; i++){
        printf("%d ", *(pArrayToSort + i));
    }

    printf("\n\nWhat type of sort would you like to do?\nType b for bubblesort\nType q for quicksort\nType m for mergesort\n");
    scanf(" %c", &typeOfSort);

    printf("\n\nYou chose the %c sort\n\n", typeOfSort);
}

/*
bubbleSort
sorts the array using the bubbleSort algorithm
*/
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

/*
quickSort
sorts algorithm using the quicksort algorithm
*/
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

/*
mergeSort
main mergesort functions that creates the temp array and passes
args to the helper
*/
void mergeSort(int * pArray, int length){

    int * pTempArray;
    pTempArray = (int *) malloc(length * sizeof(int));

    mergeSortHelp(pArray, pTempArray, 0, length-1);
    return;
}

/*
mergeSortHelp
recursively calls itself on its left and right halves and then calls merge
on both of them
*/
void mergeSortHelp(int * pArray, int * pTempArray, int start, int end){
    if(start < end){
        int mid = (start+end)/2;

        mergeSortHelp(pArray, pTempArray, start, mid);
        mergeSortHelp(pArray, pTempArray, mid + 1, end);

        merge(pArray, pTempArray, start, mid, end);
    }

    return;
}

/*
merge
merges two sorted list into one complete sorted list
*/
void merge(int * pArray, int * pTempArray, int leftStart, int mid, int rightEnd){
    int size = rightEnd - leftStart + 1;

    int lIndex = leftStart;
    int rIndex = mid + 1;
    int index = leftStart;

    while(lIndex <= mid && rIndex <= rightEnd){
        if(*(pArray + lIndex) <= *(pArray + rIndex)){
            *(pTempArray + index) = *(pArray + lIndex);
            lIndex++;
        } else {
            *(pTempArray + index) = *(pArray + rIndex);
            rIndex++;
        }
        index++;
    }

    while(lIndex <= mid){
        *(pTempArray + index) = *(pArray + lIndex);
        lIndex++;
        index++;
    }

    while(rIndex <= rightEnd){
        *(pTempArray + index) = *(pArray + rIndex);
        rIndex++;
        index++;
    }

    index = leftStart;
    while(index <= rightEnd){
        *(pArray + index) = *(pTempArray + index);
        index++;
    }

    return;

}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}

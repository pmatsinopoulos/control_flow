#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUMBER_OF_ELEMENTS 20
#define UPPER_RANDOM_NUMBER 100

void fillInRandomly(int array[], int numberOfElements, unsigned int upperRandomNumber);
int compare(const void *a, const void *b);
int binarySearch(int array[], int numberOfElements, int numberGiven);

int main(void) {
    int array[NUMBER_OF_ELEMENTS];
    fillInRandomly(array, NUMBER_OF_ELEMENTS, UPPER_RANDOM_NUMBER);
    qsort(array, NUMBER_OF_ELEMENTS, sizeof(int), compare);

    printf("Give me a number and I will tell you whether I have it in my list. Number should be 1 up to %d\n", UPPER_RANDOM_NUMBER);

    int numberGiven = -1;
    char input[1000];
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = 0;
    numberGiven = atoi(input);

    puts("");
    for(int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
        printf("%d,", array[i]);
    }
    puts("");

    if(binarySearch(array, NUMBER_OF_ELEMENTS, numberGiven)) {
        puts("Number you gave was indeed found!");
    }
    else {
        puts("Number was not found!");
    }

    return 0;
}

void fillInRandomly(int array[], int numberOfElements, unsigned int upperRandomNumber) {
    srand(time(NULL));
    for(int i = 0; i < numberOfElements; i++) {
        array[i] = (rand() % upperRandomNumber) + 1;
    }
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int binarySearch(int array[], int numberOfElements, int numberGiven) {
    int i = 0;
    int j = numberOfElements - 1;
    while(i <= j) {
        int midPosition = (i + j) / 2;
        if (array[midPosition] == numberGiven) {
            return 1;
        }
        else if(array[midPosition] > numberGiven) {
            j = midPosition - 1;
        }
        else {
            i = midPosition + 1;
        }
    }
    return 0;
}

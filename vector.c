#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

int initVectorChar(VectorChar* vec)
{
    // assuming that when string is empty that it points to null
    if (vec == NULL) {
        printf("VectorChar* must point to something!\n");
        return 1;
    } else if (vec->arr != NULL) {
        printf("Perform the following tasks before calling init:%s\n%s\n",
            "free(vec->arr) //if initializing from pre-existing array",
            "vec->arr = NULL");
        return 2;
    }
    vec->arr = (char*) malloc(sizeof(char));
    vec->capacity = 1;
    vec->size = 0;

    // function pointers so users don't accidentally call wrong function in 
    // case more vector types are used.
    vec->init    = initVectorChar;
    vec->push    = pushVectorChar;
    vec->pusharr = pushArrVectorChar;
    vec->delete  = deleteVectorChar;
    return 0;
}

void deleteVectorChar(VectorChar* vec)
{
    if (vec->arr != NULL) {
        free(vec->arr);
        vec->arr = NULL;
    }
    vec->capacity = 1;
    vec->size = 0;
}

void pushVectorChar(VectorChar* vec, char c)
{
    vec->arr[vec->size] = c;
    vec->size++;
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        char* newArr = (char*) malloc(sizeof(char) * vec->capacity);
        for (unsigned int i = 0; i < vec->size; i++) {
            newArr[i] = vec->arr[i];
        }
        free(vec->arr);
        vec->arr = newArr;
    }
    vec->arr[vec->size] = '\0';
}

void pushArrVectorChar(VectorChar* vec, char* arr)
{
    unsigned int i = 0;
    while(arr[i] != '\0') {
        vec->push(vec, arr[i]);
        i++;
    }
}
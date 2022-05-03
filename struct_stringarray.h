#ifndef STRUCT_STRINGARRAY_H
#define STRUCT_STRINGARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>




typedef struct text_array
{
    char* arr; 
    int arrsize; 
    int capacity;
} text_arr;


void array_copy(char* a, char* b, int size);
void arr_print(char tab[], int size);

text_arr* text_array_init();
void text_array_push(text_arr* a, char e);
char text_array_pop(text_arr* a);
char text_array_get(text_arr* a, int index);
void text_array_set(text_arr* a, int index, char e);


typedef struct struct string_array
{
    text_arr* arr; 
    int arrsize; 
    int capacity;
} string_arr;

void matrix_copy(char* a, char* b, int size);
void matrix__print(char tab[], int size);

text_arr* string_array_init();
void string_array_push(string_arr* a, char e);
char string_array_pop(string_arr* a);
char string_array_get(string_arr* a, int index);
void string_array_set(string_arr* a, int index, char e);



#endif
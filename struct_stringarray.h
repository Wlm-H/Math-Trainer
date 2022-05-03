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


void array_copy(unsigned char* a, unsigned char* b, int size);
void arr_print(unsigned char tab[], int size);

text_arr* text_array_init();
void text_array_push(text_arr* a, unsigned char e);
unsigned char text_array_pop(text_arr* a);
unsigned char text_array_get(text_arr* a, int index);
void text_array_set(text_arr* a, int index, unsigned char e);
void text_array_delete(text_arr* a);


typedef struct string_array
{
    text_arr* arr; 
    int arrsize; 
    int capacity;
} string_arr;

void matrix_copy(string_arr* a, string_arr* b, int size);
void matrix_print(string_arr* tab);

text_arr* string_array_init();
void string_array_push(string_arr* a, text_arr e);
text_arr string_array_pop(string_arr* a);
text_arr string_array_get(string_arr* a, int index);
void string_array_set(string_arr* a, int index, text_arr e);
void string_array_delete(string_arr* a);



#endif
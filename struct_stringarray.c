#include "struct_dynarray.h"


/*
    List of Chars
*/

void array_copy(char* a, char* b, int size){
    
    for(int i = 0; i < size; i++){
        b[i] = a[i];
    }
}

void arr_print(char tab[], int size){
    printf("[");
    for(int i = 0; i < size - 1; i++){
        printf("%c, ", tab[i]);
    }
    printf("%c] \n", tab[size - 1]);
}

text_arr* text_array_init(){
    text_arr* a = (text_arr*)malloc(sizeof(text_arr));
    a->arr = NULL;
    a->arrsize = 0;
    a->capacity = 0; 
    return a;
}

void text_array_push(text_arr* a, char e){
    if(a->arrsize >= a->capacity){
        if (a->capacity == 0){
            a->capacity++;
            a->arr = (char*)malloc(sizeof(char));
        }
        else{
            char* narr = (char*)malloc((a->capacity * 2) * sizeof(char));
            array_copy(a->arr, narr, a->capacity);
            a->capacity *= 2;
            free(a->arr);
            a->arr = narr;
        }
    }

    (a->arr)[a->arrsize] = e;
    a->arrsize++;
}


char text_array_pop(text_arr* a){
    assert(a->arrsize > 0);
    a->arrsize--;

    if (a->capacity > 4 * a->arrsize){
        char* narr = (char*)malloc((a->arrsize * 2) * sizeof(char));
        array_copy(a->arr, narr, a->capacity);
        a->capacity = a->arrsize * 2;
        free(a->arr);
        a->arr = narr;
    }
    return (a->arr[a->arrsize]);
}


char text_array_get(text_arr* a, int index){
    assert(index >= 0 && index < a->arrsize);
    return a->arr[index];
}
void text_array_set(text_arr* a, int index, char e){
    assert(index >= 0 && index < a->arrsize);
    a->arr[index] = e;
}


/*
    List of Strings
*/


void matrix_copy(string_arr a, string_arr b, int nbLines){
    for(int y = 0; y < nbLines; y++){
        for(int x = 0; x < a->arr[y]->arrsize; x++){
            b->arr[y][x] = a->arr[y][x];
        }
    }
}

void matrix__print(string_arr* tab){
    printf("[");
    for(int i = 0; i < tab->arrsize ; i++){
        arr_print(tab->arr , tab->arr->arrsize);
    }
    printf("]\n");
}

string_arr* string_array_init(){
    string_arr* a = (string_arr*)malloc(sizeof(string_arr));
    a->arr = NULL;
    a->arrsize = 0;
    a->capacity = 0; 
    return a;
}

void string_array_push(string_arr* a, text_arr* e){
    if(a->arrsize >= a->capacity){
        if (a->capacity == 0){
            a->capacity++;
            a->arr = (text_arr*)malloc(sizeof(text_arr));
        }
        else{
            text_arr* narr = (text_arr*)malloc((a->capacity * 2) * sizeof(text_arr));
            matrix_copy(a->arr, narr, a->capacity);
            a->capacity *= 2;
            free(a->arr);
            a->arr = narr;
        }
    }

    (a->arr)[a->arrsize] = e;
    a->arrsize++;
}

char* string_array_pop(string_arr* a){
    assert(a->arrsize > 0);
    a->arrsize--;

    if (a->capacity > 4 * a->arrsize){
        text_arr* narr = (text_arr*)malloc((a->arrsize * 2) * sizeof(text_arr));
        matrix_copy(a->arr, narr, a->capacity);
        a->capacity = a->arrsize * 2;
        free(a->arr);
        a->arr = narr;
    }
    return (a->arr[a->arrsize]);
}

char* string_array_get(string_arr* a, int index){
    assert(index >= 0 && index < a->arrsize);
    return a->arr[index];
}
void string_array_set(string_arr* a, int index, char e){
    assert(index >= 0 && index < a->arrsize);
    a->arr[index] = e;
}
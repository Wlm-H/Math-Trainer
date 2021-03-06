#include "struct_stringarray.h"


/*
    List of Chars
*/

void array_copy(unsigned char* a, unsigned char* b, int size){  //COPY FROM A TO B
    
    for(int i = 0; i < size; i++){
        b[i] = a[i];
    }
}

void arr_print(text_arr* tab){
    printf("[");
    for(int i = 0; i < tab->arrsize - 1; i++){
        printf("%c, ", tab->arr[i]);
    }
    printf("%c] \n", tab->arr[tab->arrsize - 1]);
}

text_arr* text_array_init(){
    text_arr* a = (text_arr*)malloc(sizeof(text_arr));
    a->arr = NULL;
    a->arrsize = 0;
    a->capacity = 0; 
    return a;
}

void text_array_push(text_arr* a, unsigned char e){
    if(a->arrsize >= a->capacity){
        if (a->capacity == 0){
            a->capacity++;
            a->arr = (unsigned char*)malloc(sizeof(unsigned char));
        }
        else{
            unsigned char* narr = (unsigned char*)malloc((a->capacity * 2) * sizeof(unsigned char));
            array_copy(a->arr, narr, a->capacity);
            a->capacity *= 2;
            free(a->arr);
            a->arr = narr;
        }
    }

    (a->arr)[a->arrsize] = e;
    a->arrsize++;
}


unsigned char text_array_pop(text_arr* a){
    assert(a->arrsize > 0);
    a->arrsize--;

    if (a->capacity > 4 * a->arrsize){
        unsigned char* narr = (unsigned char*)malloc((a->arrsize * 2) * sizeof(unsigned char));
        array_copy(a->arr, narr, a->capacity);
        a->capacity = a->arrsize * 2;
        free(a->arr);
        a->arr = narr;
    }
    return (a->arr[a->arrsize]);
}


unsigned char text_array_get(text_arr* a, int index){
    assert(index >= 0 && index < a->arrsize);
    return a->arr[index];
}
void text_array_set(text_arr* a, int index, unsigned char e){
    assert(index >= 0 && index < a->arrsize);
    a->arr[index] = e;
}

void text_array_delete(text_arr* a){
    free(a->arr);
    free(a);
}

void text_array_duplicate(text_arr* a, text_arr* b){
    if(b == NULL) printf("Couldn't allocate Memory for a new line :(");

    b->arr = (unsigned char*)malloc((a->capacity) * sizeof(unsigned char));
    b->arrsize = a->arrsize;
    b->capacity = a->capacity;
    array_copy(a->arr, b->arr, a->arrsize);
}


/*
    List of Strings
*/


void matrix_copy(text_arr* a, text_arr* b, int nbLines){
    for(int i = 0; i < nbLines; i++){
        b[i] = a[i];
    }
}

void matrix_print(string_arr* tab){
    printf("[");
    for(int i = 0; i < tab->arrsize ; i++){
        arr_print(&(tab->arr[i]));
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

void string_array_push(string_arr* a, text_arr e){
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

text_arr string_array_pop(string_arr* a){
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

text_arr string_array_get(string_arr* a, int index){
    assert(index >= 0 && index < a->arrsize);
    return a->arr[index];
}

void string_array_set(string_arr* a, int index, text_arr e){
    assert(index >= 0 && index < a->arrsize);
    a->arr[index] = e;
}

void string_array_delete(string_arr* a){
    for(int i = 0; i < a->arrsize; i++){
        printf("ok1 : %d\n", i);
        text_array_delete(&(a->arr[i]));
    }
    free(a);
}
#include "parse_pdf.h"

#define CHAR_BUFFER_SIZE 1 

string_arr* parse(char* fileName){
    string_arr* Lines = string_array_init();
    FILE* file;
    assert((file = fopen(fileName, "rb")) != NULL);

    unsigned char c[CHAR_BUFFER_SIZE];      //J'aimerais avoir le luxe du getc mais EOF ne va pas ...
    size_t READ_BYTES = CHAR_BUFFER_SIZE;

    text_arr* curLine = text_array_init();

    while(READ_BYTES == CHAR_BUFFER_SIZE){

        READ_BYTES = fread(c, sizeof(c[0]), CHAR_BUFFER_SIZE, file);

        if((int)c[0] == (int)'\n'){
            text_arr* toInsert = (text_arr*)malloc(sizeof(text_arr));
            text_array_duplicate(curLine, toInsert);  // TO KEEP THE DATA 
            //printf("%p\n", toInsert);
            string_array_push(Lines, *toInsert);
            text_array_delete(curLine);
            curLine = text_array_init();
        }

        else{
            text_array_push(curLine, c[0]);

        }
    }

    return Lines;
    
}
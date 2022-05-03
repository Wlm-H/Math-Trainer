#include "parse_pdf.h"

string_arr* parse(char* fileName){
    string_arr* Lines = string_array_init();
    FILE* file;
    assert((file = fopen(fileName)) != NULL);
    unsigned char c;
    text_arr* curLine = text_array_init();
    while((c = fgetc(file)) != EOF){
        if((int)c == (int)'\n'){
            string_array_push(Lines, *curLine);
            text_array_delete(curLine);
            curLine = text_array_init();
        }

        else{
            text_array_push(curLine, c);
        }
    }

    return Lines;
    
}
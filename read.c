#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <wchar.h>

#define CHAR_BUFFER_SIZE 1 //Read Character-By-Character
#define MAX_PDF_LINESIZE 256 //Read Character-By-Character

int main(int argc, char* argv[]){

    FILE* in;
    FILE* out;
    char* inName = "Corrections/Correction_Chap_13.pdf";
    char* outName = "output/out";
    if(argc >= 2) inName = argv[1];
    if(argc >= 3) outName = argv[2];
    assert(( in = fopen(inName, "rb")) != NULL);
    assert(( out = fopen(outName, "wb+")) != NULL);


    unsigned char byteCharacters[CHAR_BUFFER_SIZE];
    size_t READ_BYTES = CHAR_BUFFER_SIZE; 

    while(READ_BYTES == CHAR_BUFFER_SIZE){
        READ_BYTES = fread(byteCharacters, sizeof(byteCharacters[0]), CHAR_BUFFER_SIZE, in);
        fwrite(byteCharacters, sizeof(byteCharacters[0]), READ_BYTES, out);
    } 


    fclose(in);
    fclose(out);
    return EXIT_SUCCESS;
}
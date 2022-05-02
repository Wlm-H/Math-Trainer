#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <wchar.h>


int main(int argc, char* argv[]){

    FILE* in;
    FILE* out;
    char* inName = "Corrections/Correction_Chap_13.pdf";
    char* outName = "out";
    printf("%d\n",argc);
    if(argc >= 2) inName = argv[1];
    if(argc >= 3) outName = argv[2];
    assert(( in = fopen(inName, "rb")) != NULL);
    assert(( out = fopen(outName, "wb")) != NULL);

    unsigned char byteCharacters[8];
    size_t READ_BYTES = 8; 

    while(READ_BYTES == 8){
        READ_BYTES = fread(byteCharacters, sizeof(byteCharacters[0]), 8, in);
        fwrite(byteCharacters, sizeof(byteCharacters[0]), READ_BYTES, out);
    }   

    fclose(in);
    fclose(out);
    return EXIT_SUCCESS;
}
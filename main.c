#include "parse_pdf.h"
#include "struct_stringarray.h"

int main(int argc, char* argv[]){
    char* inName = "Corrections/Correction_Chap_13.pdf";
    if(argc >= 2) inName = argv[1];
    string_arr* Lines = parse(inName);
    matrix_print(Lines);
    string_array_delete(Lines);
    return EXIT_SUCCESS;
}
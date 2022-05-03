#ifndef BUILD_EXERCISES_H
#define BUILD_EXERCISES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct pdf_object 
{
    char* arguments[];  //EVEN = object, ODD following EVEN = argument(s) of the object before
    unsigned char steam[];
    int obj_id[2];
} pdf_object;


pdf_object*  pdo_initPdfObject(char* objectString);
pdf_object** poa_getStreamObjects(char* file);



#endif
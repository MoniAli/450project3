//
//  util.c
//  
//
//  Created by Moni Ali on 10/31/17.
//
//

#include "util.h"

int8_t format(char* fileName){
    FILE *fp;
    
    fp = fopen(fileName, "w+");
    
    char* array = {'a','b','c','d'}

    
    fwrite(array, sizeof(char), sizeof(array), fp);

    return 0;
}

//
//  util.c
//  
//
//  Created by Moni Ali on 10/31/17.
//
//

#include "util.h"

int8_t format(){
    char* fileName = malloc(sizeof(char)*100);
    
    printf("Please enter the name of the file that contains the file system ");
    scanf("%99s", fileName);
    printf("%s is the filename\n", fileName);
    free(fileName);
    return 0;
}

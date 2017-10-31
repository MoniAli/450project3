//
//  util.c
//  
//
//  Created by Moni Ali on 10/31/17.
//
//

#include "util.h"

int8_t format(){
    char fileName[50] = {0};
    
    printf("Please enter the name of the file that contains the file system ");
    scanf("%49s", fileName);
    printf("%s is the filename\n", fileName);
    return 0;
}

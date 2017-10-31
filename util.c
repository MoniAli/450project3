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
    
    char* data = malloc(sizeof(char) * (NUM_SECTORS * SECTOR_SIZE));

    
    fwrite(data, 1, sizeof(data), fp);

    return 0;
}

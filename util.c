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
    for (int i = 0; i < sizeof(char) * (NUM_SECTORS * SECTOR_SIZE); i++){
        data[i] = 'x';
    }
    
    fwrite(data, sizeof(char), sizeof(data), fp);

    return 0;
}

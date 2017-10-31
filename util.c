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
    
    char data[NUM_SECTORS * SECTOR_SIZE];
    for (int i = 0; i < NUM_SECTORS * SECTOR_SIZE; i++){
        printf("%d", i);
        data[i] = itoa(i);
    }
    printf("%ld", sizeof(*data));
    
    fwrite(data, 1, NUM_SECTORS * SECTOR_SIZE, fp);

    return 0;
}

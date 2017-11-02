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
    
    fp = fopen(fileName, "wb");
    
    superBlock_t sb = {0, 0, 0, 0, NULL, NULL};
    sb.magic = 0xDEADBEEF;
    sb.size = 1;
    sb.inode_count = 9;
    for (int8_t i = 0; i < 144; i++){
        sb.inode_stats[i] = 0;
    }
    for (int8_t i = 0; i < 246; i++){
        sb.datablock_stats[i] = 0;
    }
    
    
   // fwrite(data, 1, NUM_SECTORS * SECTOR_SIZE, fp);

    return 0;
}

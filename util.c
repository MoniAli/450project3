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
    int i;
    fp = fopen(fileName, "wb");
    
    superBlock_t sb = {0, 0, 0, 0, NULL, NULL};
    sb.magic = 0xDEADBEEF;
    sb.size = 1;
    sb.inode_count = 9;
    *sb.inode_stats = malloc(sizeof(char)*144);
    *sb.datablock_stats = malloc(sizeof(char)*246);
    for (i = 0; i < 144; i++){
        sb.inode_stats[i] = 0;
    }
    for (i = 0; i < 246; i++){
        sb.datablock_stats[i] = 0;
    }
    
    fwrite(&sb.magic, 1, 4, fp);
    fseek(fp, 0, SEEK_SET);
    uint32_t magic;
    fread(&magic, 4, 1, fp);
    printf("What we read was %d\n", magic);
    
   // fwrite(data, 1, NUM_SECTORS * SECTOR_SIZE, fp);

    return 0;
}

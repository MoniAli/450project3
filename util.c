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
    uint_8 i;
    fp = fopen(fileName, "wb");
    
    superBlock_t sb = {0, 0, 0, 0, NULL, NULL};
    sb.magic = 0xDEADBEEF;
    sb.size = 1;
    sb.inode_count = 9;
    sb.datablock_count = 246;
    *sb.inode_stats = malloc(sizeof(char)*144);
    *sb.datablock_stats = malloc(sizeof(char)*246);
    uint8_t* sector_fill = malloc(sizeof(char)*106);
    for (i = 0; i < 144; i++){
        sb.inode_stats[i] = 0;
    }
    for (i = 0; i < 246; i++){
        sb.datablock_stats[i] = 0;
    }
    for (i = 0; i < 106; i++){
        sector_fill[i] = 0;
    }
    if (fwrite(&sb.magic, 4, 1, fp) != 1) return -1;
    if (fwrite(&sb.size, 4, 1, fp) != 1) return -1;
    if (fwrite(&sb.inode_count, 4, 1, fp) != 1) return -1;
    if (fwrite(&sb.datablock_count, 4, 1, fp) != 1) return -1;
    if (fwrite(sb.inode_stats, 1, 144, fp) != 144) return -1;
    if (fwrite(sb.datablock_stats, 1, 246, fp) != 246) return -1;
    if (fwrite(sector_fill, 1, 106, fp) != 106) return -1;
    
    uint16_t occupied_inode = 0x1111;
    uint16_t d_inode = 0x3333;
    uint16_t initial_size = 0;
    uint8_t empty = 0;
    
    if (fwrite(&occupied_inode, 2, 1, fp) != 1) return -1;
    if (fwrite(&d_inode, 2, 1, fp) != 1) return -1;
    if (fwrite(&initial_size, 2, 1, fp) != 1) return -1;
    if (fwrite(&empty, 1, 26, fp) != 26) return -1;
    if (fwrite(&empty, 1, 480, fp) != 480) return -1;
    
    for (i = 0; i < 8; i++){
        if (fwrite(&empty, 1, 512, fp) != 512) return -1;
    }
    
    for (i = 0; i < 246; i++){
    if (fwrite(&empty, 1, 512, fp) != 512) return -1;
    }
    
   
    fclose(fp);
    fp = NULL;
    return 0;
}

int8_t mount(char* fileName){
    
    FILE* fp;
    return 0;
}








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
    (fwrite(&sb.magic, 4, 1, fp) == 1) ? 1 : return -1;
    if(fwrite(&sb.size, 4, 1, fp)) != 1) return -1;
    if(fwrite(&sb.inode_count, 4, 1, fp) != 1 return -1;
    if(fwrite(&sb.datablock_count, 4, 1, fp) != 1 return -1;
    fwrite(sb.inode_stats, 1, 144, fp);
    fwrite(sb.datablock_stats, 1, 246, fp);
    fwrite(sector_fill, 1, 106, fp);
    
   

    return 0;
}

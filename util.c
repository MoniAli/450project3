//
//  util.c
//  
//
//  Created by Moni Ali on 10/31/17.
//
//

#include "util.h"

int8_t format(char* fileName){
    //Open the file and overwrite if currently exists
    FILE *fp;
    uint8_t i;
    fp = fopen(fileName, "wb");

    
    //Create a new superblock that will be written
    superBlock_t sb = {0, 0, 0, 0, NULL, NULL};
    
    //Magic number, size, inode count, datablock count, and inode count
    sb.magic = 0xDEADBEEF;
    sb.size = 1;
    sb.inode_count = 9;
    sb.datablock_count = 246;
    *sb.inode_stats = malloc(sizeof(char)*144);
    *sb.datablock_stats = malloc(sizeof(char)*246);
    uint8_t* sector_fill = malloc(sizeof(char)*106);
    
    // The first inode is NOT FREE, contains root directory
    *sb.inode_stats[0] = 1;
    
    //Rest are free
    for (i = 1; i < 144; i++){
        sb.inode_stats[i] = 0;
    }
    
    //The first datablock is NOT FREE, contains root dir data
    *sb.datablock_stats[0] = 1;
    
    //Rest are free
    for (i = 1; i < 246; i++){
        sb.datablock_stats[i] = 0;
    }
    
    //Used to fill the rest of this sector
    for (i = 0; i < 106; i++){
        sector_fill[i] = 0;
    }
    
    //Write all of these to file
    if (fwrite(&sb.magic, 4, 1, fp) != 1) return -1;
    if (fwrite(&sb.size, 4, 1, fp) != 1) return -1;
    if (fwrite(&sb.inode_count, 4, 1, fp) != 1) return -1;
    if (fwrite(&sb.datablock_count, 4, 1, fp) != 1) return -1;
    if (fwrite(sb.inode_stats, 1, 144, fp) != 144) return -1;
    if (fwrite(sb.datablock_stats, 1, 246, fp) != 246) return -1;
    if (fwrite(sector_fill, 1, 106, fp) != 106) return -1;
    
    
    //First inode is occupied with a directory, size 0
    uint16_t occupied_inode = 0x1111;
    uint16_t d_inode = 0x3333;
    uint16_t initial_size = 0;
    uint8_t initial_block = 11;
    
    //Writes empty byte
    uint8_t empty = 0;
    
    if (fwrite(&occupied_inode, 2, 1, fp) != 1) return -1;
    if (fwrite(&d_inode, 2, 1, fp) != 1) return -1;
    if (fwrite(&initial_size, 2, 1, fp) != 1) return -1;
    if (fwrite(&initial_block, 1, 1, fp) != 1) return -1;
    if (fwrite(&empty, 1, 25, fp) != 26) return -1;
    if (fwrite(&empty, 1, 480, fp) != 480) return -1;
    
    
    //Write the remaining empty inodes
    for (i = 0; i < 8; i++){
        if (fwrite(&empty, 1, 512, fp) != 512) return -1;
    }
    
    //Write the 246 empty data blocks
    for (i = 0; i < 246; i++){
    if (fwrite(&empty, 1, 512, fp) != 512) return -1;
    }
    
   
    //Close the file and return
    fclose(fp);
    fp = NULL;
    return 0;
}

int8_t mount(char* fileName){
    
    FILE* fp;
    fp = fopen(fileName, "r");
    if (fp == NULL) return -1;
    
    superBlock_t sb = {0, 0, 0, 0, NULL, NULL};
    if (fread(&sb.magic, 4, 1, fp) != 1) return -1;
    
    if (sb.magic != 0xDEADBEEF) return -1;
    
    if (fread(&sb.size, 4, 1, fp) != 1) return -1;
    
    if (fread(&sb.inode_count, 4, 1, fp) != 1) return -1;
    
    if (fread(&sb.datablock_count, 4, 1, fp) != 1) return -1;
    
    *sb.inode_stats = malloc(sizeof(char)*144);
    if (fread(sb.inode_stats, 1, 144, fp) != 144) return -1;
    
    *sb.datablock_stats = malloc(sizeof(char)*246);
    if (fread(sb.datablock_stats, 1, 246, fp) != 246) != -1;
    
    
    

    
    return 0;
}








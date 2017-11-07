//
//  util.h
//  
//
//  Created by Moni Ali on 10/31/17.
//
//

#ifndef util_h
#define util_h

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "macros.h"



typedef struct inode{
    uint16_t freedom;
    uint16_t type;
    uint16_t size;
    uint8_t indexes[26];
}inode_t;


typedef struct superBlock{
    uint32_t magic;
    uint32_t size;
    uint32_t inode_count;
    uint32_t datablock_count;
    uint8_t* inode_stats[144];
    uint8_t* datablock_stats[246];
} superBlock_t;

typedef struct fileSystem{
    superBlock_t sb;
    uint8_t* inode_t[144];
}fileSystem_t;



int8_t mount(char* fileName);
int8_t format(char* fileName);

#endif /* util_h */

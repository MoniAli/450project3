//
//  main.c
//  
//
//  Created by Moni Ali on 10/30/17.
//
//

#include <stdio.h>
#include <stdbool.h>
#include "util.h"

int main(int argc,char** argv){
    uint8_t response;
    while (true):
        printf("Menu of options:\n");
        printf("    1) Format\n");
        printf("    14) Exit the program\n");
    
    
        get_input(&response);
        printf("%d", response);
    
}

void get_input(){
    scanf("%d", response);
}
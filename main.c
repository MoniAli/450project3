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


void get_input(int8_t *response){
    scanf("%hhd", response);
}

void print_menu(){
    printf("Menu of options:\n");
    printf("    1) Format\n");
    printf("    14) Exit the program\n");
}

int8_t handle_response(uint8_t response){
    switch(response){
        case 1:
            printf("Please enter the name of the file that contains the file system ");
            char* fileName;
            scanf("%s", fileName);
            format(fileName);
            break;
        case 14:
            return -1;
            break;
        default:
            printf("Invalid response, try again\n");
            response = 0;
            break;
    }
    return 0;
    
}

int main(int argc,char** argv){
    uint8_t response;
    int8_t ended;
    ended = 0;
    while (ended != -1){
        print_menu();
        get_input(&response);
        ended = handle_response(response);
    }
    return 0;
}
//
//  main.c
//  
//
//  Created by Moni Ali on 10/30/17.
//
//

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "util.h"


void get_input(uint8_t *response){
    scanf("%"SCNd8, response);
}

void print_menu(){
    printf("Menu of options:\n");
    printf("    1) Format\n");
    printf("    14) Exit the program\n");
}

bool handle_response(uint8_t response){
    switch(response){
        case 1:
            format();
            break;
        case 14:
            return false;
            break;
        default:
            printf("Invalid response, try again\n");
            break;
    }
    return true;
    
}

int main(int argc,char** argv){
    uint8_t response;
    bool going = true;
    
    while (going){
        print_menu();
        get_input(&response);
        going = handle_response(response);
    }
    return 0;
}
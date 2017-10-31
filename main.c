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


void get_input(int8_t *response){
    printf("MADE IT HERE");
    scanf("%"SCNd8, response);
    printf("%hhd is the int", *response);
}

void print_menu(){
    printf("Menu of options:\n");
    printf("    1) Format\n");
    printf("    14) Exit the program\n");
}

int8_t handle_response(int8_t response){
    switch(response){
        case 1:
            format();
            break;
        case 14:
            return 0;
            break;
        default:
            printf("Invalid response, try again\n");
            break;
    }
    return 1;
    
}

int main(int argc,char** argv){
    int8_t response;
    int8_t ended;
    ended = 1;
    while (ended){
        print_menu();
        get_input(&response);
        ended = handle_response(response);
    }
    return 0;
}
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

void handle_response(uint8_t response){
    switch(response){
        case 1:
            format("Hello");
            response = 0;
            break;
        case 14:
            return 0;
            break;
        default:
            printf("Invalid response, try again\n");
            response = 0;
            break;
    }
    
}

int main(int argc,char** argv){
    uint8_t response;
    while (true){
        print_menu();
        get_input(&response);
        handle_response(response);
    }
    
}
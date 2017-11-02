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
#include <ctype.h>
#include "util.h"
#include "macros.h"

void get_input(uint8_t *response){
    char* buffer = malloc(sizeof(char)*10);
    fgets(buffer, 10, stdin);
    bool alpha = false;
    int8_t i = 0;
    while (buffer[i] != '\0' && i != 10 && buffer[i] != '\n'){
        if (!isdigit(buffer[i])){
            alpha = true;
        }
        i++;
    }

    if (alpha){
        *response = 0;
        free(buffer);
        return;
    }
    
    *response = atoi(buffer);
    printf("%s", buffer);
    free(buffer);
}

void print_menu(){
    printf("Menu of options:\n");
    printf("    1) Format\n");
    printf("    14) Exit the program\n");
}

bool handle_response(uint8_t response){
    char* fileName;
    switch(response){
        case 1:
            fileName = malloc(sizeof(char)*100);
            printf("Please enter the name of the file that contains the file system ");
            scanf("%99s", fileName);
            format(fileName);
            free(fileName);
            fileName = NULL;
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
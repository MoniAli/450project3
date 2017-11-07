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


char* f_success = "The file has successfully been formatted";
char* f_fail = "The file failed to format";
char* m_success = "The file has successfully been mounted";
char* m_fail = "The file has failed to mount";

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
    free(buffer);
}

void print_menu(){
    printf("Menu of options:\n");
    printf("    1) Format a file system\n");
    printf("    2) Mount a file system\n");
    printf("    14) Exit the program\n");
}

void clear_input(){
    while(getchar() != '\n'){
        continue;
    }
}

bool handle_response(uint8_t response){
    char* fileName;
    switch(response){
        case 1:
            fileName = malloc(sizeof(char)*100);
            printf("Please enter the name of the file that contains the file system ");
            scanf("%99s", fileName);
            printf("%s\n", format(fileName) == 0 ? f_success : f_fail);
            free(fileName);
            fileName = NULL;
            clear_input();
            break;
        case 2:
            fileName = malloc(sizeof(char)*100);
            printf("Please enter the name of the file that contains the file system ");
            scanf("%99s", fileName);
            printf("%s\n", mount(fileName) == 0 ? m_success : m_fail);
            free(fileName);
            fileName = NULL;
            clear_input();
            break;
        case 14:
            return false;
            break; //style
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
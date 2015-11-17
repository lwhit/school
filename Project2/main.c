//
//  main.c
//  Project2
//
//  Created by Logan Whitmire on 11/16/15.
//  Copyright © 2015 Logan Whitmire. All rights reserved.
//

#include "stack.h"
#include <string.h>
#include <ctype.h>

void printIntro();

int main(int argc, const char * argv[]) {
    // insert code here...
    int quit = 0; //0 = false. We will use this to know when to quit asking the user for input
    char input[50];
    int inputIndex, tempIndex;
    int isInt;
    char temp[50];
    int dontContinue, numInput;
    stackType op1, op2, value;
    int entryCount;
    int successfulRun = 1;
    
    printIntro();
    
    while (quit == 0) {
        successfulRun = 1;
        printf("Input: ");
        gets(input); //gather input. Accept white space characters, stop taking input when a new line character is entered
        inputIndex = 0;
        tempIndex = 0;
        dontContinue = 0;
        numInput = 1;
        entryCount = 0;
        
        
        while (input[entryCount] != '\0') {
            entryCount++; //gives us size of the input array
        }
        
        input[entryCount] = ' '; //for some reason my code needs a space at the end to run correctly.
        input[entryCount+1] = '\0';
        
        //printf("value entered is: %s\n" , input);
        
        if ( !strcmp(input, "q ") ) {
            quit = 1; //strcmp returns 0 if the strings are equal
            successfulRun = 0;
        }
        
        else { //user does not wish to quit
            while (input[inputIndex] != '\0') {
                if (input[inputIndex] != ' ') {
                    temp[tempIndex] = input[inputIndex];
                    tempIndex++;
                    inputIndex++;
                } else {
                    //we found a space!
                    //printf("space found\n");
                    
                    inputIndex++;
                    dontContinue = 0;
                    numInput = 1;
                    
                    temp[tempIndex] = '\0'; //end of string
                    //printf("temp is: %s\n", temp);
                    //printf("temp index = %i\n", tempIndex);
                    
                    for (int i = 0; i < tempIndex; i++) {
                        isInt = isdigit(temp[i]);
                        //printf("tested %d tempIndex for a digit\n", i );
                        //printf("index %d has value %c\n", i, temp[i]);
                        //printf("isInt = %d\n", isInt);
                        
                        if (isInt == 0) {
                            //printf("non integer found!: %s\n", temp);
                            
                            numInput = 0;
                            //we found a non integer :(
                            //let's hope we have a symbol
                            switch (temp[i]) {
                                case '+':
                                    op1 = pop();
                                    op2 = pop();
                                    if (op1 != -1001 && op2 != -1001) {
                                        
                                        value = op1+op2;
                                        push(value);
                                    } else successfulRun = 0;
                                    break;
                                case '-':
                                    op1 = pop();
                                    op2 = pop();
                                    if (op1 != -1001 && op2 != -1001) {
                                        
                                        value = op1-op2;
                                        push(value);
                                    } else successfulRun = 0;
                                    break;
                                case '*':
                                    op1 = pop();
                                    op2 = pop();
                                    if (op1 != -1001 && op2 != -1001) {
                                    
                                        value = op1*op2;
                                        push(value);
                                    } else successfulRun = 0;
                                    break;
                                case '/':
                                    op1 = pop();
                                    op2 = pop();
                                    if (op1 != -1001 && op2 != -1001) {
                                    
                                        value = op1/op2;
                                        push(value);
                                    } else successfulRun = 0;
                                    break;
                                    
                                default: printf("bad value entered: %c\n", temp[i]);
                                    dontContinue = 1;
                                    successfulRun = 0;
                                    break;
                            } //end of switch
                        } //end of if isint = 0...
                        
                    } //end of for....
                    if (dontContinue == 0 && numInput == 1) {
                        //if we have a valid, numerical input...
                        op1 = atoi(temp);
                        push( op1 );
                        
                    }
                    tempIndex=0;
                    memset(temp, 0, sizeof(temp)); //clear temp
                    
                }
            }
        }
        
        if (successfulRun == 1) {
            //entryCount = (int)pop();
            int newvalue = (int)pop();
            if (empty() == 1) {
                printf("output: %d\n", newvalue);
            } else printf("Too many operands entered\n");
        }
        
        clearStack();
        memset(input, 0, sizeof(input));
        
    
    }
    
    
    return 0;
}

void printIntro() {
    printf("Intro\n");

}


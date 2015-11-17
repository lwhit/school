//
//  stack.c
//  Project2
//
//  Created by Logan Whitmire on 11/16/15.
//  Copyright © 2015 Logan Whitmire. All rights reserved.
//

#include "stack.h"
#include <stdio.h>

struct stack *top = NULL; //defines top as null, until we push a value onto the stack

void push(stackType newValue) {
    struct stack *temp; //our new node!
    
    temp = (struct stack*)malloc(sizeof(struct stack)); //temp now holds the pointer address given to us by the heap when we called malloc. If this value is zero then we are out of memory :(
    
    temp->value = newValue;
    //printf("value to be added is: %d\n", newValue);
    temp->linkTo = top; //point this new node to the current top node
    
    top = temp; //now temp is a part of our structure.
    //printf("added a value of %f to the stack!\n" , (double)newValue);
}

stackType pop(void) {
    int error = -1001;
    stackType value;
    struct stack* temp;
    if (top == NULL) {
        //no entires in stack...
        printf("ERROR: Not Enough Operands Entered\n");
        return (stackType)error; //error condition
        
    }
    else { //stack has something in it. whoopeeee
        value = top->value;
        //printf("removing a value of %d from the stack\n" , value);
        temp = top;
        top = top->linkTo; //top is now the node that the old top pointed to. So once closer to the first node
        free(temp); //give up old top's memory allocation
    }
    
    return value;
}

stackType peek(void) {
    stackType topValue = top->value;
    return topValue;
}

int empty(void) {
    int isEmpty = 0;
    if (top == NULL) {
        isEmpty = 1;
    }
    return isEmpty;
}

void clearStack(void) {
    struct stack* temp;
    
    while (top != NULL) {
        temp = top;
        top = top->linkTo;
        free( temp );
    }
}

__attribute__((constructor)) void initStack(void) {
    //printf("Stack constructor has been called\n"); //testing

}

__attribute__((destructor)) void freeStack(void) {
    clearStack();
    printf("Thanks for playing!\n"); //testing purposes
}



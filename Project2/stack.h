//
//  stack.h
//  Project2
//
//  Created by Logan Whitmire on 11/16/15.
//  Copyright © 2015 Logan Whitmire. All rights reserved.
//

#ifndef stack_h
#define stack_h
#include <stdlib.h>
#include <stdio.h>

typedef int stackType;

struct stack{
    stackType *theStack;
    stackType value; //the value of the node
    struct stack* linkTo; //will let us point a new node to the current top node
};

void initStack( void ); //stack constructor
void clearStack( void ); //clears current stack
void freeStack( void ); //stack destructor

stackType pop( void ); //remove one value from stack, return that value
void push( stackType ); //puts a new node into our stack, value is of type stackType
stackType peek( void ); //returns the value of our top level node
int empty( void ); //returns 1 if empty, 0 if not

#endif /* stack_h */

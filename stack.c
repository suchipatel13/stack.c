#include <stdio.h>
#include <string.h>
#include "stack.h"
#include <stdlib.h>

#define ERROR_VALUE -99999

//pop: remove an item from the stack
//Parameters: stack: a pointer to a stack structure
//result: a pointer to an integer to hold the value from the top of the stack.
//Returns: non-zero on success, 0 on failure
int pop(arrayStack_t* stack,int* result){
        if (stack->top==0)
                return 0;
        stack->top--;
        *result=stack->stackArray[stack->top];
        return 1;
}

void push(arrayStack_t* stack,int value){
    if(stack->top >= stack->arraySize){
        int* oldArray = stack->stackArray;
        stack->stackArray = (int*)malloc(sizeof(int)*stack->arraySize*2);
        for (int i =0;i < stack ->arraySize;i++)
    {
        stack-> stackArray[i]=oldArray[i];
    }
    stack ->arraySize = stack->arraySize * 2;
    free(oldArray);
    }
//as we get here ,we know that the stack is big enough
stack -> stackArray[stack->top++]=value;
}

#define INTIAL_STACK_SIZE 5
void initStack(arrayStack_t* stack, int initialSize){
    stack->arraySize = initialSize;
    stack -> stackArray =(int*)malloc(sizeof(int)*initialSize);
    stack -> top=0;
}

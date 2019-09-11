#include <stdlib.h>
#include <stdio.h>
#include "bexp.h"

static int value_length(value value){
    int len = 0;
    while(value.begin++ != value.end){
        ++len;
    }
    // printf("\n%d", len);
    return len;
}

int bexp_length(const expression * ex){
    if(ex->op == NOT || ex->op == COMPLEMENT){
        return value_length(ex->value1);
    }
    else if(ex->op == AND || ex->op == OR || ex->op == XOR){
        if(value_length(ex->value1) > value_length(ex->value2)){
                return value_length(ex->value1);
            }
        return value_length(ex->value2);
    }
    else if(ex->op == GREATER_THAN || ex->op == LESS_THAN){
        return 1;
    }
    return -1;
}


int bexp_evaluate(value * result, expression * ex){
    int len_res = bexp_length(ex);
    result->begin = (char*)malloc(sizeof(char)*(len_res+1));
    result->end = result->begin+len_res; // To check 
    *result->end = '\0';
    char * value_true_begin = ex->value1.begin;
    char * result_true_begin = result->begin;

    // while(ex->value1.begin != ex->value1.end){
    //     // printf("NOT");
    //     printf("%c", *ex->value1.begin++);
    // }
    // printf("\n");
    // ex->value1.begin = value_true_begin;

    /* Cloud be done also with switch */
    if(ex->op == NOT){
        while(ex->value1.begin != ex->value1.end){
            if(result->begin == result->end){
                return 0; //failure 
            }
            if(*ex->value1.begin == '1'){
                *result->begin = '0';
            } else {
                *result->begin = '1';
            }
            ++result->begin;
            ++ex->value1.begin;
        }
        result->begin = result_true_begin;
        ex->value1.begin = value_true_begin;

        /*PRINT*/
        // while(result->begin != result->end){
        //     // printf("NOT");
        //     printf("%c", *result->begin++);
        // }
        // result->begin = result_true_begin;

    } else if (ex->op == AND){
        
    } else{
        return 0; //failure 
    }
}

int main(){
    char* binaryNumber = "1001\0";
    value value1;
    value value2;
    value1.begin = binaryNumber;
    value1.end = &binaryNumber[4];

    // printf("\n%d", value_length(value1));
    value* result = (value*)malloc(sizeof(value));
    expression* ex1 = (expression*)malloc(sizeof(expression));
    ex1->op = NOT;
    ex1->value1 = value1;
    ex1->value2 = value2;

    char* true_beg = ex1->value1.begin;
    
    while(ex1->value1.begin != ex1->value1.end){
        printf("%c", *ex1->value1.begin);
        ++ex1->value1.begin;
    }
    printf("\n");
    ex1->value1.begin = true_beg;

    bexp_evaluate(result, ex1);
}
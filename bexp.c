#include <stdlib.h>
#include <stdio.h>
#include "bexp.h"

static int value_length(value value){
    int len = 0;
    while(value.begin != value.end){
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
    return -1;
}

int main(){
    char* binaryNumber = "1001\0";
    value value1;
    value1.begin = binaryNumber;
    value1.end = &binaryNumber[4];
    value_length(value1);

}
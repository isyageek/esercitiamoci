#include"strstack.h"
#include <stdio.h>
#include <stdlib.h> 
#include <stddef.h>
#include <string.h>
// #include <assert.h>

/*
        [000000000000000000000000000000000000000000]
         ^                                        ^  
*/       


/* Global variables */
char * buffer;
char * pointer;
size_t buffer_len;
size_t free_space;
int empty;

void strstack_use_buffer(char * mem, size_t mem_size){
    empty = 1; //true 
    buffer = mem;
    pointer = buffer + buffer_len; /*to check*/
    buffer_len = free_space = mem_size;
}

void strstack_clear(){
    empty = 1; //true 
    free_space = buffer_len;
    pointer = buffer + buffer_len;
}


int strstack_push(const char * s){
    if(buffer){
        if(strlen(s)+1 <= free_space){
            pointer -= strlen(s)+1;
            strcpy(pointer, s);
            free_space = buffer - pointer;
            if(empty){
                empty = 0; 
                //empty = !empty; ?? 
            } 
            return 1;
        }
    }
    return 0;
}

const char * strstack_pop(){
    char * string; 
    if(buffer){
        if(!empty){
            int i = strlen(pointer)+1;
            strcpy(string, pointer);
            pointer += (strlen(string)+1);
            if(pointer == buffer+buffer_len){
                empty = 1;
            } 
            free_space += strlen(pointer)+1;
            return string;
        }
    }
    return 0;

}

// const char * S[] = {
//     "ciao mamma",
//     "blah!",
//     "it ain't over till it's over",
//     "",
//     "ciao",
//     "",
//     "#include <stdio.h>",
//     "Hello world!"
// };

// int main() {
//     int i;

// #if STRSTACK_USES_EXTERNAL_MEMORY
//     char * stack_memory = malloc(10000); /* 10000 char */
//     assert(stack_memory);

//     assert(!strstack_push(""));
//     assert(!strstack_pop());

//     strstack_use_buffer(stack_memory, 10000);
//     assert(strstack_push(""));
//     assert(strstack_pop());
// #endif

//     strstack_clear();

//     for (i = 0; i < 8; ++i)
// 	assert(strstack_push(S[i]));

//     while (i > 0) {
// 	const char * s = strstack_pop();
// 	assert(s);
// 	assert(strcmp(s, S[--i]) == 0);
//     }

//     assert(!strstack_pop());

//     for (i = 0; i < 8; ++i)
// 	assert(strstack_push(S[i]));

//     strstack_pop();
//     strstack_pop();

//     for (i = 0; i < 8; ++i)
// 	assert(strstack_push(S[i]));

//     while (i > 0) {
// 	const char * s = strstack_pop();
// 	assert(s);
// 	assert(strcmp(s, S[--i]) == 0);
//     }

//     i = 6;

//     while (i > 0) {
// 	const char * s = strstack_pop();
// 	assert(s);
// 	assert(strcmp(s, S[--i]) == 0);
//     }

//     assert(!strstack_pop());

//     printf("TEST PASSED.\n");

// #if STRSTACK_USES_EXTERNAL_MEMORY
//     free(stack_memory);
// #endif

//     return 0;
// }
#include"strstack.h"
#include <stdio.h>
#ihnclude <stdlib.h> 


void strstack_use_buffer(char * mem, size_t mem_size);
void strstack_clear();
int strstack_push(const char * s);
const char * strstack_pop();
#include <stdio.h>
#include <string.h>
#include <assert.h>

#if STRSTACK_USES_EXTERNAL_MEMORY
#include <stdlib.h>
#endif

#include "strstack.h"

const char * S[] = {
    "ciao mamma",
    "blah!",
    "it ain't over till it's over",
    "",
    "ciao",
    "",
    "#include <stdio.h>",
    "Hello world!"
};

int main() {
    int i;

#if STRSTACK_USES_EXTERNAL_MEMORY
    char * stack_memory = malloc(10000); /* 10000 char */
    assert(stack_memory);

    assert(!strstack_push(""));
    assert(!strstack_pop());

    strstack_use_buffer(stack_memory, 10000);
    assert(strstack_push(""));
    assert(strstack_pop());
#endif

    strstack_clear();

    for (i = 0; i < 8; ++i)
	assert(strstack_push(S[i]));

    while (i > 0) {
	const char * s = strstack_pop();
	assert(s);
	assert(strcmp(s, S[--i]) == 0);
    }

    assert(!strstack_pop());

    for (i = 0; i < 8; ++i)
	assert(strstack_push(S[i]));

    strstack_pop();
    strstack_pop();

    for (i = 0; i < 8; ++i)
	assert(strstack_push(S[i]));

    while (i > 0) {
	const char * s = strstack_pop();
	assert(s);
	assert(strcmp(s, S[--i]) == 0);
    }

    i = 6;

    while (i > 0) {
	const char * s = strstack_pop();
	assert(s);
	assert(strcmp(s, S[--i]) == 0);
    }

    assert(!strstack_pop());

    printf("TEST PASSED.\n");

#if STRSTACK_USES_EXTERNAL_MEMORY
    free(stack_memory);
#endif

    return 0;
}
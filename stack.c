#include <assert.h>
#include<stdio.h>

static unsigned int data; // initialized to 0 by default
static unsigned int len;

unsigned int get_stack_val()
{
    return data;
};

unsigned int get_stack_len()
{
    return len;
}

void push_to_stack(unsigned int arg)
{
    assert(arg == 0 || arg == 1);
    data <<= 1;
    len++;
    data += (unsigned int) arg;
    #ifdef DEBUG
    printf("current stack value is %u, current stack len is %u\n", data, len);
    fflush(stdout);
    #endif
}

void pop_from_stack()
{
    data >>= 1;
    len--;
    #ifdef DEBUG
    printf("current stack value is %u, current stack len is %u\n", data, len);
    fflush(stdout);
    #endif
}

void zero_stack()
{
    #ifdef DEBUG
    printf("current stack value is %u, current stack len is %u\n", data, len);
    fflush(stdout);
    #endif
    data = 0;
    len = 0;
}

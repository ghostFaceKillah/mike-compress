#include <assert.h>

static int data; // initialized to 0 by default
static int len;

unsigned int get_stack_val()
{
    return data;
};

unsigned int get_stack_len()
{
    return len;
}

void push_to_stack(int arg)
{
    assert(arg == 0 || arg == 1);
    data <<= 1;
    data += (int) arg;
}

void pop_from_stack()
{
    data >>= 1;
}

void zero_stack()
{
    data = 0;
    len = 0;
}

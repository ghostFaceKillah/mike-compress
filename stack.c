#include <assert.h>

static int data; // initialized to 0 by default
static int len;

int get_stack_val()
{
    return data;
};

int get_stack_len()
{
    return len;
}

void push_to_stack(int arg)
{
    assert(arg == 0 || arg == 1);
    data <<= 1;
    data += (int) arg;
}

int pop_from_stack()
{
    data >>= 1;
}

int zero_stack()
{
    data = 0;
}

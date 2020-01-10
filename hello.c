#include "hello.h"


static int hello_init(void* self_, int num)
{
    struct hello* self = (struct hello*)self_;

    self->num= num;
    return 0;
}

static void hello_set(void* self_, int val)
{
    struct hello* self = (struct hello*)self_;
    
    self->num = val;
}

static int hello_get(void* self_)
{
    struct hello* self = (struct hello*)self_;
    
    return self->num;
}

static void hello_exit(void* self_)
{
    struct hello* self = (struct hello*)self_;
    
    self->num = 0;
}

struct hello_ops hello_ops_ = {
    .init = hello_init,
    .set = hello_set,
    .get = hello_get,
    .exit = hello_exit
};

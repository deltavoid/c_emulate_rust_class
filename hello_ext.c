#include "hello_ext.h"
#include <stdio.h>
#include <stdlib.h>

static int hello_ext_init(void* self_, int num, int val)
{
    struct hello_ext* self = (struct hello_ext*)self_;
    
    self->num = num;
    self->val = val;

    return 0;
}

static void hello_ext_exit(void* self_)
{
    struct hello_ext* self = (struct hello_ext*)self_;

    self->num = 0;
    self->val = 0;
}

static void hello_ext_set_num(void* self_, int num)
{
    struct hello_ext* self = (struct hello_ext*)self_;

    self->num = num;
}

static int hello_ext_get_num(void* self_)
{
    struct hello_ext* self = (struct hello_ext*)self_;

    return self->num;
}


static void hello_ext_set_val(void* self_, int val)
{
    struct hello_ext* self = (struct hello_ext*)self_;

    self->val = val;
}

static int hello_ext_get_val(void* self_)
{
    struct hello_ext* self = (struct hello_ext*)self_;

    return self->val;
} 

struct hello_ext_ops hello_ext_ops = {
    .hello_ops = {
        .init = NULL,
        .exit = hello_ext_exit,
        .set = hello_ext_set_num,
        .get = hello_ext_get_num,
    },
    .init = hello_ext_init,
    .exit = hello_ext_exit,
    .set_val = hello_ext_set_val,
    .get_val = hello_ext_get_val,
};
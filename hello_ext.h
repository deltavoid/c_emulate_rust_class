#ifndef HELLO_EXT_H
#define HELLO_EXT_H

#include "hello.h"


struct hello_ext
{
    int num;
    int val;
};

struct hello_ext_ops
{
    int (*init)(void* self_, int num, int val);
    void (*exit)(void* self_);

    void (*set_num)(void* self_, int num);
    int (*get_num)(void* self_);

    void (*set_val)(void* self_, int val);
    int (*get_val)(void* self_);
};

struct hello_ext_trait
{
    struct hello_ext_ops* ops;
    void* data;
};

extern struct hello_ext_ops hello_ext_ops;
extern struct hello_ops hello_ext_impl_hello_ops;



#endif
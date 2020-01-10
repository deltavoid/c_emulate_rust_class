#ifndef HELLO_H
#define HELLO_H

struct hello_ops;

struct hello
{
    const struct hello_ops * ops;
    int num;
};

struct hello_ops
{
    // struct hello* create(int num);
    // void destroy(void* self_);

    int (*init)(void* self_, int num);
    void (*exit)(void* self_);
    
    void (*set)(void* self_, int num);
    int (*get)(void* self_);
};

extern const struct hello_ops hello_ops_;

// 不存在多重实现，接口与接口只有包含于被包含的关系，接口与实现只有一层关系。

#endif
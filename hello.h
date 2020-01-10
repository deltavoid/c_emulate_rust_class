#ifndef HELLO_H
#define HELLO_H


struct hello
{
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

struct hello_trait
{
    struct hello_ops* ops;
    void* data;
};

extern struct hello_ops hello_ops;



// 不存在多重实现，接口与接口只有包含于被包含的关系，接口与实现只有一层关系。

// 函数指针作虚函数，实例函数作实函数

#endif
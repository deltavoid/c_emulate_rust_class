#include <stdio.h>
#include <stdlib.h>
#include "hello.h"
#include "hello_ext.h"


void hello_display(struct hello_trait hello)
{
    int val;
    
    val = hello.ops->get(hello.data);
    printf("hello value: %d\n", val);

    hello.ops->set(hello.data, 2);
    val = hello.ops->get(hello.data);
    printf("hello value: %d\n", val);
    
}


int main()
{
    int val;
    printf("hello world\n");

    struct hello* hello = malloc(sizeof(struct hello));
    hello_ops.init(hello, 1);

    struct hello_trait hello1 = {
        .ops = &hello_ops,
        .data = hello,
    };

    hello_display(hello1);

    hello1.ops->exit(hello1.data);
    free(hello1.data);


    struct hello_ext* hello_ext = malloc(sizeof(struct hello_ext));
    hello_ext_ops.init(hello_ext, 1, 2);

    struct hello_trait hello2 = {
        .ops = &hello_ext_impl_hello_ops,
        .data = hello_ext,
    };

    hello_display(hello2);

    hello2.ops->exit(hello2.data);
    free(hello2.data);


    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "hello.h"



int main()
{
    int val;
    printf("hello world\n");

    struct hello* hello_ = malloc(sizeof(struct hello));
    hello_ops_.init(hello_, 1);

    struct hello_trait hello1 = {
        .ops = &hello_ops_,
        .data = hello_
    };

    val = hello1.ops->get(hello1.data);
    printf("hello_ value: %d\n", val);

    hello1.ops->set(hello1.data, 2);
    val = hello1.ops->get(hello1.data);
    printf("hello_ value: %d\n", val);

    hello1.ops->exit(hello1.data);
    free(hello_);


    return 0;
}
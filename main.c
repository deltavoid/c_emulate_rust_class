#include <stdio.h>
#include <stdlib.h>
#include "hello.h"



int main()
{
    int val;
    printf("hello world\n");

    struct hello* hello_ = malloc(sizeof(struct hello));
    hello_ops_.init(hello_, 1);

    val = hello_->ops->get(hello_);
    printf("hello_ value: %d\n", val);

    hello_->ops->set(hello_, 2);
    val = hello_->ops->get(hello_);
    printf("hello_ value: %d\n", val);

    hello_->ops->exit(hello_);
    free(hello_);

    

    


    return 0;
}
#include <assert.h>
#include <stdio.h>
#include "list.h"
#include "hash.h"

void print_int_node(list_p node){
    node->data ? printf("%d->",*(int*)(node->data)) : printf("NULL\n");
}

void test_list(){
    int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    int five = 5;
    list_p l1 = NULL;

    printf("l1 is empty=%d\n", list_is_empty(l1));

    l1 = list_create();
    printf("l1 is empty after create=%d\n", list_is_empty(l1));

    assert(l1);

    list_add_head(&l1, &two);
    list_add_tail(l1, &three);
    list_add_tail(l1, &four);
    list_add_tail(l1, &five);
    list_add_head(&l1, &one);

    printf("l1 is empty after add=%d\n", list_is_empty(l1));

    list_print(l1,print_int_node);
}

int main(int argc,char* argv[]){
    test_list();
    return 0;
}
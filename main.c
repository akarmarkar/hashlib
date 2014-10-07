#include <assert.h>
#include <stdio.h>
#include "list.h"
#include "hash.h"

void print_int_node(list_p node){
    node && node->data ? printf("%d->",*(int*)(node->data)) : printf("NULL\n");
}

bool isEqualInt(void* data1,void* data2) {
    return (bool) ( *(int*)(data1) == *(int*)(data2) );
}

void test_list(){
    int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    int five = 5;
    int six = 6;
    list_p one_prev_node,two_prev_node,three_prev_node,four_prev_node,five_prev_node,six_prev_node;

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

    one_prev_node = list_find_prev(l1, &one, isEqualInt);
    printf("One prev node=\n");
    print_int_node(one_prev_node);
    printf("\n");

    two_prev_node = list_find_prev(l1, &two, isEqualInt);
    printf("Two prev node=\n");
    print_int_node(two_prev_node);
    printf("\n");

    three_prev_node = list_find_prev(l1, &three, isEqualInt);
    printf("Three prev node=\n");
    print_int_node(three_prev_node);
    printf("\n");

    four_prev_node = list_find_prev(l1, &four, isEqualInt);
    printf("Four prev node=\n");
    print_int_node(four_prev_node);
    printf("\n");

    five_prev_node = list_find_prev(l1, &five, isEqualInt);
    printf("Five prev node=\n");
    print_int_node(five_prev_node);
    printf("\n");

    six_prev_node = list_find_prev(l1, &six, isEqualInt);
    printf("NOT FOUND node=\n");
    print_int_node(six_prev_node);
    printf("\n");
}

int main(int argc,char* argv[]){
    test_list();
    return 0;
}
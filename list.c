#include <malloc.h>
#include <assert.h>
#include "list.h"


list_p create_new_node(void* data){
    list_p current = (list_p) malloc(sizeof(list));
    current->next = NULL;
    current->data = data;
    return current;
}

list_p list_create(){
    // Create a 'dummy' head node with NULL data and return it.
    return create_new_node(NULL);
}

/*
* Gets the tail of the list
* */
list_p list_get_tail(list_p head){
    list_p current = head;
    list_p prev;

    assert(head);
    prev = head;

    while(current){
        prev = current;
        current = current->next;
    }

    return prev;
}

/*
* Given a pointer to the pointer to head of the list and a pointer to the data to add, append the data to the start of the list.
*/
void list_add_head(list_p* head_p,void* data){
    list_p node = create_new_node(data);
    node->next = *head_p;
    (*head_p)->data = data;

    *head_p = node;
}

/*
* Given a pointer to head of the list and a pointer to the data to add, append the data to the end of the list.
*/
void list_add_tail(list_p head,void* data){
    assert(head);
    list_p tail = list_get_tail(head);
    list_p node = create_new_node(data);
    tail->next = node;
}


/*
* Given a pointer to head of the list, return 1 if list is empty, 0 otherwise.
*/
bool list_is_empty(list_p head){
    if (head && head->next)
        return 0;
    else
        return 1;
}

/*
* Given a pointer to head of the list and a function to print a node, print out the entire list
*/
void list_print(list_p head, void (*print_node_func)(list_p)){
    assert(head);

    printf("List (%p)=",head);
    for(list_p current=head->next;current;current=current->next) {
        print_node_func(current);
    }
    printf("NULL\n");
}

/*
* Find an item in the list.
* head: head of the list
* data: data item to find
* isEqual : pointer to a comparison function.
* returns a pointer to the previous node. returns head if found in first node, NULL otherwise.
*/
list_p list_find_prev(list_p head,void* data,bool (*isEqual)(void*,void*)){
    list_p prev = head;
    assert(head);
    assert(data);

    if (list_is_empty(head))
        return NULL;

    for(list_p current=head->next;current;current=current->next) {
        if (current->data && isEqual(data,current->data) )
            return prev;
        prev = current;
    }

    return NULL;
}


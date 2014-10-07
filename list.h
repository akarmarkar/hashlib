
#ifndef __LIST_H__
#define __LIST_H__

typedef struct list{
    struct list* next;
    void* data;
} list;

typedef list* list_p;
typedef unsigned int bool;


/* Helper routines */
list_p create_new_node(void* data);
list_p list_get_tail(list_p head);
void list_print(list_p head, void (*print_node_func)(list_p node));
bool list_is_empty(list_p head);

/* CRUD ops */
list_p list_create();

void list_add_head(list_p* head_p,void* data);
void list_add_tail(list_p head,void* data);

list_p list_find_prev(list_p head,void* data,bool (*isEqual)(void* data1,void* data2));

#endif
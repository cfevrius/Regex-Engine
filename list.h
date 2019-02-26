#ifndef LIST_H
#define LIST_H

/* Node Module */
typedef struct node node;
struct node {
    char* str;
    node* next;
};

/* Node helper functions */
node* node_create(char* str);
void  node_destroy(node* node);

/* List module */
typedef struct list list;
struct list {
    node* head;
    node* tail;
    int size;
};

/* List helper functions */
list* list_create(void);
void  list_push(list* ls, char* str);
void  list_destroy(list* ls);
void  list_display(list* ls); 

#endif

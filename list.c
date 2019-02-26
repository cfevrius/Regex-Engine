#ifndef LIST_C
#define LIST_C

#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strdup(const char *str){
    int n = strlen(str) + 1;
    char *dup = malloc(n);
    if(dup){
        strcpy(dup, str);
    }
    return dup;
}

node* node_create(char* str){
    node* n = (node*)malloc(sizeof(node));
    n->str = strdup(str);
    return n;
}

void  node_destroy(node* node){
    free(node->str);
    free(node);
}

list* list_create(void){
    list* ls = (list*)calloc(1, sizeof(list));
    return ls;
}

void  list_push(list* ls, char* str){

    node* new_node = node_create(str);

    if(ls->head == NULL){
        ls->head = new_node;
        ls->tail = new_node;
        new_node->next = NULL;
    } else {
        ls->tail->next = new_node;
        new_node->next = NULL;
        ls->tail = new_node;
    }
}

void  list_destroy(list* ls){
    /*
    for(node* curr = ls->head; curr != NULL; curr = curr->next){
        node_destroy(curr); 
    }
    */

    node* curr = ls->head;
    while(curr != NULL){
        node* temp = curr;
        curr = curr->next;
        free(temp->str);
        free(temp);
    }
    free(ls);
}

void  list_display(list* ls){
    printf("{ ");

    node* curr;
    for(curr = ls->head; curr != NULL; curr = curr->next){
       printf("\t%s,\n", curr->str); 
    }
    printf("}\n");
}

#endif

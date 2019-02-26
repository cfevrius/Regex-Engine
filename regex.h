#ifndef REGEX_H
#define REGEX_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

/* Regular Expression Module */
typedef struct regex_node regex_node;
struct regex_node {
    list* ls;
    regex_node* next;
};

regex_node* regex_node_create(list* ls);
void regex_node_destroy(regex_node* rn);


typedef struct regex regex;
struct regex {
    regex_node* head;
    regex_node* tail;
    int evil_counter;
};

regex* regex_create();
void add(regex* re, list* ls);

void regex_destroy(regex* re);
void regex_display(regex* re);

list* plus(char *q);
list* star(char *q);
list* character(char *q);
list* dot(void);
list* evil(char* q);


bool starts_with(char* s, char* m); bool match(char* str, regex* re);

#endif

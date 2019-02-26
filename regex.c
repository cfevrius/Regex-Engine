#ifndef REGEX_C
#define REGEX_C

#include "regex.h"

int evil_count = 0;

regex_node* regex_node_create(list* ls){
    regex_node* rn = (regex_node*)calloc(1, sizeof(regex_node));
    rn->ls = ls;
    return rn;
}

void regex_node_destroy(regex_node* rn){
    list_destroy(rn->ls);
    free(rn);
}

regex* regex_create(){
    regex* re = (regex*)calloc(1, sizeof(regex));
    return re;
}

// add(item, re)  , adds a given string item to a given re object (or struct, language dependent).
void add(regex* re, list* ls){

    regex_node* new_regex_node = regex_node_create(ls);
    if(re->head == NULL){
        re->head = new_regex_node;
        re->tail = new_regex_node;
        new_regex_node->next = NULL;
    } else {
        re->tail->next = new_regex_node;
        new_regex_node->next = NULL;
        re->tail = new_regex_node; 
    }
}

void regex_destroy(regex* re){
    /*
    for(regex_node* curr = re->head; curr != NULL; curr = curr->next){
        regex_node_destroy(curr);
    }
    free(re);
    */
    regex_node* curr = re->head;
    while(curr != NULL){
        regex_node* temp = curr;
        curr = curr->next;
        regex_node_destroy(temp);
    }
    free(re);
}

void regex_display(regex* re){
    printf("Regex: \n");
    for(regex_node* curr = re->head; curr != NULL; curr = curr->next){
        list_display(curr->ls);
   }
}

/* plus(q), returns q, qq, qqq...  up to a specified memory limit. */
list* plus(char *q) {
    list* l =  list_create();
    
    /* Create 20 elements within the list */
    for(int i = 0; i < 20; i++){
        char final_string[100];
        strcpy(final_string, q);
        for(int j = 1; j <= i; j++){
            strcat(final_string, q); 
        }
        list_push(l, final_string);
    }
    return l;
}

/* star(q), returns empty, q, qq, qqq...  up to a specified memory limit. */
list* star(char *q) {
    list* l =  list_create();

    /* Create 20 elements within the list */
    list_push(l, "");  /* make the empty list the first item */
    for(int i = 0; i < 20; i++){
        char final_string[100];
        strcpy(final_string, q);
        for(int j = 1; j <= i; j++){
            strcat(final_string, q); 
        }
        list_push(l, final_string);
    }
    return l;
}

/* character(q), returns a list with just that character */
list* character(char *q){
    list* l = list_create();
    list_push(l, q);
    return l;
}

/* dot(), returns all alphanumeric chars. */
list* dot(void){
    list* l = list_create();

    /* Loop through all of the lowercase letters 
     * in the ASCII character set (97-122) */
    for(int i = 97; i <= 122; i++){
        char c[2] = {i, '\0'};
        list_push(l, c);
    }

    /* Loop through all of the uppercase letters 
     * in the ASCII character set (65-90) */
    for(int i = 65; i <= 90; i++){
        char c[2] = {i, '\0'};
        list_push(l, c);
    }

    /* Loop through all of the numbers in the 
     * ASCII character set (48-57) */
    for(int i = 48; i <= 57; i++){
        char c[2] = {i, '\0'};
        list_push(l, c);
    }
    
    return l;
}

// evil(q)  , returns q repeated the number of times evil has appeared in the regular expression.
list* evil(char* q){
    evil_count++;

    list* l =  list_create();
    
    /* Create evil_count elements within the list */
    for(int i = 0; i < evil_count; i++){
        char final_string[100];
        strcpy(final_string, q);
        for(int j = 1; j <= i; j++){
            strcat(final_string, q); 
        }
        list_push(l, final_string);
    }
    return l;
}

bool starts_with(char* s, char* m){
    if(strlen(m) > strlen(s)){
        return false;
    }
    for(int i = 0; i < strlen(m); i++){
        if(s[i] != m[i]){
            return false;
        }
    }
    return true;
}

/* match(str, re), returns true only if given str is matched by given re 
 * 
 * Citation: General algorithm for matching was discussed with Michael Moynihan 
 */
bool match(char* str, regex* re){
    /* loop through all regex elements */
    for(regex_node* curr_el = re->head; curr_el != NULL; curr_el = curr_el->next){
        bool found = false;
        int match_len = 0;
        /* loop through every element in the linked-list */
        for(node* curr = curr_el->ls->head; curr != NULL; curr = curr->next){
            if(starts_with(str, curr->str)){
                found = true;
                match_len = strlen(curr->str);
            }
        }
        if(!found){
            return false;
        }
        str = str + match_len;
    }
    return true;
}

#endif

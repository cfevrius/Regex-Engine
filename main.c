#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "regex.h"
#include "list.h"

int main(int argc, char* argv[]) {

    puts("----------Regex----------");

    regex* re = regex_create();

    add(re, plus("cat"));
    add(re, dot());
    add(re, character("d"));
    add(re, character("o"));
    add(re, star("g"));

    // regex_display(re);
    printf("\"catcatQdogggggg\" in cat+.dog*: ");
    if( match("catcatQdogggggg", re) ){
        puts("True");
    } else {
        puts("False");
    }

    printf("\"turkeybaconcheese\" in cat+.dog*: ");
    if( match("turkeybaconcheese", re) ){
        puts("True");
    } else {
        puts("False");
    }
     
    regex_destroy(re);

    regex* myre = regex_create();

    add(myre, dot());
    add(myre, evil("cat"));
    add(myre, dot());
    add(myre, evil("cat"));
    add(myre, star("g"));

    printf("\"acatacatcat\" in .cat<e>.cat<e>g*: ");
    if( match("acatacatcat", myre) ){
        puts("True");
    } else {
        puts("False");
    }

    regex_destroy(myre);

    return 0;
}


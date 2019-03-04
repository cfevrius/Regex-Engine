Name: Carl-Michel Fevrius
Date: February 15 2019

**Extraction and Compilation**

After extracting the tar ball using the 'tar xvf regex.tar.gz' command, you should
get the following directory and files.

    $ tar xvf regex.tar.gz
    regex/
    regex/list.c
    regex/list.h
    regex/regex.c
    regex/regex.h
    regex/main.c
    regex/Makefile
    regex/README.md

Move into the regex directory and call the 'make' command. The included Makefile 
should compile the 'regex' module, the 'list' module and the 'regex' executable.

    $ cd regex
    $ make
    gcc  -std=c99 -Wall -c list.c
    gcc  -std=c99 -Wall -c regex.c
    gcc  -std=c99 -Wall -o regex main.c list.o regex.o

**Running**

To run the program simply call the exectuable './regex'.

    $ ./regex
    ----------Regex----------
    "catcatQdogggggg" in cat+.dog*: True
    "turkeybaconcheese" in cat+.dog*: False
    "acatacatcat" in .cat<e>.cat<e>g*: True


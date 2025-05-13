/*
        Inheritable book file. this file may be inherited
    to make a simple reading book. There are a few
    functions to be set.

    set_pages(integer)  :  sets the number of pages in the book
    set_book(string)    :  sets the directory the book pages will
                               be in and the name of the pages.
                               pages will be referenced by the
                               path and files name given here
                               plus a number for the page the player
                               has turned to.
                  Example: player is on page 3
                           book set to /players/mangla/page
                           action done:
                                  cat("/players/mangla/page3");

    query_book()    :     where pages are located

*/
inherit "obj/treasure";

#include "/players/mangla/defs.h"

#define DEFBOOK "/players/mangla/book/page"
#define DEFPAGES 5

int page,open,PAGES;
string BOOK;

int query_pages() {
    return PAGES;
}

string query_book() {
    return BOOK;
}

int set_pages(int pag) {

    if(!pag) {
        PAGES = DEFPAGES;
        return 1;
    }
    else {
        PAGES = pag;
    }
    return 1;
}

int set_book(string str) {

    if(!str) {
        BOOK = DEFBOOK;
        return 1;
    }
    else {
        BOOK = str;
    }
    return 1;
}

int _close(string str) {

    if(!str || str != "book") return 0;
    else {
        PAGES = 1;
        open = 0;
    }
    return 1;
}

int _read(string str) {

    int pa;

    if(ENV(TO) != TP && ENV(TO) != ENV(TP)) {
        notify_fail("Read what?!\n");
        return 0;
    }
    if(!open) {
        notify_fail("The book is not open.\n");
        return 0;
    }
    if(sscanf(str,"page %d",pa)==1) {
        page = pa;
    }
    if(!str && str != "book" && str != "page") {
        notify_fail("Read what?\n");
        return 0;
    }
    cat(BOOK+page);
    return 1;
}

int _open(string str) {

    if(ENV(TO) != TP && ENV(TO) != ENV(TP)) {
        return 0;
    }
    if(!str || str != "book") {
        notify_fail("Open what?\n");
        return 1;
    }
    if(!open) {
        printf("You open the book to the first page.\n");
        page = 1;
        open = 1;
    }
    else {
        printf("The book is already open.\n");
    }
    return 1;
}

int _turn(string str) {

    int pa;

    if (!str || (ENV(TO) != TP && ENV(TP) != ENV(TP))) return 0;

    if(sscanf(str,"to page %d",pa)!=1
        && sscanf(str,"page %d",pa)!=1) return 0;
    if(pa > PAGES || pa < 0) {
        printf("There is no such page. You have turned too far.\n");
    }
    else {
        printf("You flip over to page %d.\n",pa);
        page = pa;
    }
    return 1;
}


void reset (int arg) {
    ::reset (arg);
    if (!arg) {
        set_name("book");
        set_short("Book of Many Wonders");
        set_alias("book");
        set_long("A wonderous book that is filled with many wonderous " +
                 "ideas. Opening this book could open a whole new world.\n");
        set_value(0);
        set_weight(1);
    }
}

init() {

    ::init();
    add_action("_open","open");
    add_action("_read","read");
    add_action("_turn","turn");
    add_action("_close","close");
}

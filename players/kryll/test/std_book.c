/*-------------------------------------------------------------------------*/
/* FILE : std_book.c                                                       */
/*                                                                         */
/* Description : This is the inheritable file for books. It also inherits  */
/*               /obj/treasure which also contains things to set.          */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 28 1997  Mangla       Coded new std_book.
Jun 28 1997  Kryll        Added USERDOCs.
*/

/*
inherit "obj/treasure";
*/
inherit "/players/kryll/test/treasure";
 
#include "/obj/obj_defs.h"
 
#define DEFBOOK "/players/mangla/book/page"
#define DEFPAGES 5
 
int    page, open, pgs;
string bk;
 
/* USERDOC:
query_pages
Function  : i=query_pages()
See also  : set_pages

This function returns the number of pages in the book.
*/
int query_pages() {
  return pgs;
}
 
/* USERDOC:
query_book
Function  : s=query_book()
See also  : set_book

This function returns the directory that the pages are in.
*/
string query_book() {
  return bk;
}
 
/* USERDOC:
set_pages
Function  : i=set_pages(i)
Examples  :
See also  : query_pages

This function sets the number of pages that the book contains.
*/
int set_pages(int pag) {
  if(!pag) {
    pgs = DEFPAGES;
    return 1;
  }
  pgs = pag;
  return 1;
}
 
/* USERDOC:
set_book
Function  : i=set_book(s)
Examples  : val = set_book("/doc/rules/pbook/")
See also  : query_book

This sets the directory which is the location that contains the
contents of the book by pages.
*/
int set_book(string str) {
  if(!str) {
    bk = DEFBOOK;
    return 1;
  }
  bk = str;
  return 1;
}
 
int _close(string str) {
  if(!str || str != "book")
    return 0;
  else {
    pgs = 1;
    open = 0;
  }
  return 1;
}
 
int _read(string str) {
  if(ENV(TO) != TP) {
    notify_fail("Read what?!\n");
    return 0;
  }

  if(!str && str != "book" && str != "page") {
    notify_fail("Read what?\n");
    return 0;
  }

  if(!open) {
    notify_fail("The book is not open.\n");
    return 0;
  }

  cat(bk + page);
  return 1;
}
 
int _open(string str) {
  if(ENV(TO) != TP)
    return 0;

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
 
  if(!str || ENV(TO) != TP) return 0;
 
  if(sscanf(str,"to page %i",pa)!=1);
  if(pa > pgs || pa < 0) {
    printf("There is no such page. You have turned too far.\n");
  }
  else {
    printf("You flip over to page %i.\n",pa);
    page = pa;
  }
  return 1;
}
 
void long() {
  write(long + "The book is " + (open?"open":"closed") + ".\n");
  return;
}
 
void reset (int arg) {
  ::reset (arg);
  if(arg) return;

  set_name("book");
  set_short("Book of Many Wonders");
  set_alias("book");
        long = "A Book.\nThe book is " + (open?"open":"closed") + ".\n";
//        set_long("A wonderous book that is filled with many wonderous " +
//                 "ideas. Opening this book could open a whole new world.\n");
  set_value(0);
  set_weight(1);
}
 
void init() {
  ::init();
  add_action("_open","open");
  add_action("_read","read");
  add_action("_turn","turn");
  add_action("_close","close");
}


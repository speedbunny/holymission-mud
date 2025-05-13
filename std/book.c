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
                           book set to /players/fred/page
                           action done:
                           more("/players/fred/page3");

    query_book()    :     where pages are located
    query_pages()   :     number of pages in book
    query_book()    :     where pages are located

*/

inherit "/std/object.c";

#include <lw.h>
#include <obj_defs.h>
#include <setlight.h>
#include <material.h>
#include <size.h>

int pagecount,pagecount,currpage;
status bookopen;
string bookdir;

int query_pages() { return pagecount; }
string query_book() { return bookdir; }

// Sets the number of pages up. returns number of pages if set successfully. 
// 0 if no pages found
int set_pages(int pgcount) {
  if(!pgcount) 
    return 0;
  currpage=1;
  return pagecount=pgcount;
}

//Customised verision of long() - allows us to also pass how many pages and
//whether the book is open or not.

void long() {
  string amt;

  amt=sprintf("%d",pagecount);
  write(lw(long_desc)+"\n");
  write("It has "+ (pagecount > 10 ? "many" : amt) +" page"+
	(pagecount !=1 ? "s " : " ")+"and is "+(bookopen ? "open.\n" : "closed.\n"));
}

int set_book(string bdir) {
  if(!bdir) {
    bdir="/std/defs/book";
    return 0;
  }

  // Check that book directory exists
  if (file_size(bdir) == -2) {
    bookdir=bdir;
    return 1;
  } else {
    write("Cannot find pages for the book!\n");
    return 0;
  }
}

int _close(string str) {
  if( !str || str != "book") return 0;

  if (!bookopen) {
    notify_fail("The book's already closed.\n");
    return 0;
  }

  write("You close the book.\n");
  tell_room(environment(this_player()), capitalize(this_player()->query_name())+" closes the book.\n", ({this_player()}));
  
  currpage = 1;
  bookopen = 0;

  return 1;
}

int _read(string str) {
  int page;

  if(environment(this_object()) != this_player()) {
    notify_fail("Read what?!\n");
    return 0;
  }

  if(!bookopen) {
    notify_fail("You need to open the book first.\n");
    return 0;
  }

  if(sscanf(str,"page %d", page) == 1) 
    if ((page <=0) || (page > currpage)) {
      notify_fail("There's not that many pages in this book!\n");
      return 0;
    }

  currpage = page;

  if( !str && str != "book" && str != "page") {
    notify_fail("Read what?\n");
    return 0;
  }

  tell_room(environment(this_player()), capitalize(this_player()->query_name())+" studies a page in the book.\n", ({this_player()}));

  this_player()->more(bookdir+"/page"+currpage);

  return 1;
}

int _open(string str) {
  if(environment(this_object()) != this_player()) 
    return 0;

  if(!str || str != "book") {
    notify_fail("Open what?\n");
    return 0;
  }

  if(!bookopen) {
    printf("You open the book to the first page.\n");
    tell_room(environment(this_player()), capitalize(this_player()->query_name())+" opens the book.\n", ({this_player()}));
    currpage = 1;
    bookopen = 1;
  }
  else 
    printf("The book's already open.\n");
    
  return 1;
}

int _turn(string str) {
  int pa;

  if (!str || environment(this_object()) != this_player()) return 0;

  if(sscanf(str,"to page %d",pa)!=1);
  if(pa > pagecount || pa < 0) {
    printf("There is no such page. You have turned too far.\n");
  }
  else {
    printf("You flip over to page %i.\n",pa);
    tell_room(environment(this_player()), capitalize(this_player()->query_name())+" turns over a page.\n", ({this_player()}));
    currpage = pa;
  }
  return 1;
}


// Sets the default book up. Note that you should create your own reset(), add
// ::reset() after if (arg) return; and use replace_program("/std/book.c") 
// at the end.
void reset (int arg) {
  if (arg) return;

  ::reset(); // Always remember this line!

  set_name("book");
  set_short("Standard Book");
  set_long("A wonderous book that is filled with many wonderous " +
	   "ideas. Opening this book could open a whole new world.");
  set_value(0);
  set_weight(1);
  set_book("/std/defs/book");
  set_pages(1);
  set_can_get(1);
  set_alias_list(({"tome"}));

}

void init() {
  ::init();
  add_action("_open","open");
  add_action("_read","read");
  add_action("_turn","turn");
  add_action("_close","close");
}










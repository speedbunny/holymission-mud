// Standard Book.
// This object should be inherited and then modified.

// For standard books, replace program should be used at the end
// of the reset() to reduce memory overheads.

// Any queries about this object should be directed to Dworkin.

#include <lw.h>
inherit "/std/object.c";

// Prototypes
void add_page(string page, string title, string msg);
void remove_page(string page);
void reset(int arg);
void init();

// Variables
mapping pages;
int book_flag;

//Functions
void reset(int arg) {
  if (arg) return;

  ::reset();

  set_name("book");
  set_short("A dusty, old, book");
  set_long("It appears to be one of those ancient, dust covered tomes that make everyone in the room sneeze when you open it.");
  set_weight(1);
  set_value(3);
  set_can_get(1);

  book_flag=0; // Book is closed by default.

  // Form is : ({ page title , page text })

  pages=([ ]);
  pages["1"]=({"Inheriting this object","Inherit this object and modify as necessary"});
  pages["2"]=({"Page 2","Page 2"});
  pages["3"]=({"3rd Page","3rd Page"});
  
}

void init() {
  add_action("open_close_book","open");
  add_action("open_close_book","close");
  add_action("read_page","read");
}

// Allows the user to open/close the book
int open_close_book(string arg) {
  string verb;

  if (arg != "book") return 0;

  verb=query_verb();

  if ( ((verb=="open") && book_flag) || ((verb=="close") && !book_flag)) {
    write("The book is already "+verb+"ed!\n");
    return 1;
  }

  book_flag=!book_flag;

  write("You "+verb+" the book.\n");
  say(this_player()->query_name()+" "+verb+"s the book.\n");
  return 1;
}

// Allows the user to read a page from the book.

int read_page(string arg) {
  string fore_arg, post_arg, *keys;
  int i;

  if (!arg) return 0;
  
  if (arg=="book") {
    write("To read the book, use :\nopen book\nclose book\nread contents page\nread page <page>\n");
    return 1;
  }

  if (sscanf(arg,"%s %s",fore_arg,post_arg)!=2) return 0;

  if ((fore_arg=="contents") && (post_arg=="page")) {
    if (!book_flag) {
      write("You need to open the book first!\n");
      return 1;
    }
    keys=m_indices(pages);
    keys=sort_array(keys, #'<);
    i=sizeof(keys);
    while(i--)
      write(keys[i]+"\t"+pages[keys[i]][0]+"\n");

    say(this_player()->query_name()+" studies the book intently.\n");
    return 1;
  }

  if ((fore_arg=="page") && (member(pages, post_arg ))) {
    if (!book_flag) {
      write("You need to open the book first!\n");
      return 1;
    }
    write(lw(pages[post_arg][1]+"\n"));
    say(this_player()->query_name()+" studies the book intently.\n");
    return 1;
  }

  return 0;
}

// This function allows objects to add more pages to the book
void add_page(string page, string title, string msg) {
  pages[page]= ({ title, msg });
}

// This function allows objects to remove pages from the book
void remove_page(string page) {
  m_delete(pages, page);
}

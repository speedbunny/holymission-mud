#include "/players/redsexy/guild/guilddefs.h"

#define MAX_PAGES 7
#define BOOK_DIR  ("/players/redsexy/guild/text/lore_page")

int open, pagenum;

id(arg) {
  return arg == "book" || arg == "tome" ||
    arg == "black tome" || arg == "black book";
}

short() {
  return "A huge black tome";
}

long() {
  write("    This is a very large book bound in black leather, resting\n");
  write("on a black pedestal in the center of the room.\n");
  if(!open) {
    write("    On its cover, in silver lettering, are the words\n");
    write("           'LORE OF THE SUMMONER'.\n");
  }
  else {
    write("    The book is open at page " + pagenum + ". Type " +
	  "\"contents\" for a table\n");
    write("of contents.\n");
  }
}

init() {
  add_action("open", "open");
  add_action("close", "close");
  add_action("turn", "turn");
  add_action("contents", "contents");
  add_action("read", "read");
}

open(arg) {
  if(id(arg)) {
    if(!open) {
      write("You open the book.\n");
      say(TP->NAME + " opens the book.\n");
      open = 1;
      pagenum = 1;
      return 1;
    }
    write("The book is already open.\n");
    return 1;
  }
}

close(arg) {
  if(id(arg)) {
    if(open) {
      write("You close the book.\n");
      say(TP->NAME + " closes the book.\n");
      open = 0;
      return 1;
    }
    write("The book is already closed.\n");
    return 1;
  }
}

contents(arg) {
  if(!arg) {
    if(open) {
      write("1.) General\n");
      write("2.) Rise\n");
      write("3.) Fall\n");
      write("4.) Restoration\n");
      write("5.) Powers\n");
      write("6.) Learning\n");  
      write("7.) Rules\n\n");
      write("You can turn to any page number.\n");
      return 1;
    }
  }
}

turn(arg) {
  int num;
  if(open) {
    if(sscanf(arg, "to page %d", num)) {
      if((1 <= num) && (num <= MAX_PAGES)) {
	write("You turn to page " + num + ".\n");
	say(TP->NAME + " turns the pages of the book.\n");
	pagenum = num;
	return 1;
      }
      write("No such page.\n");
      return 1;
    }
    write("Turn to what page?\n");
    return 1;
  }
  write("The book is closed.\n");
  return 1;
}

read(arg) {
  if(id(arg)) {
    if(open) {
      if(!pagenum) pagenum = 1;
      write("You read the book.\n\n");
      say(TP->NAME + " reads the book.\n");
      cat(BOOK_DIR + pagenum);
      return 1;
    }
    write("The book is closed.\n");
    return 1;
  }
}

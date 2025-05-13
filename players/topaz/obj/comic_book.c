/* Re-coded by Matt 7-16-93 */
/* Changed by Ac/Dc 7-19-93 */
/* Ac/Dc 7-30-93 */

#define MAX_PAGE 8
#define TP this_player()
#define NAME query_name()

int opened, page_num;

id(arg) {
  return arg == "book" || arg == "player rulebook" || arg == "chain";
}
short() { return "A book on a chain"; }
long(arg) {
  if(arg == "chain") {
    write("The chain is secured to the wall.\n");
    return 1;
  }
  if(!opened) {
    write("A book hanging from a chain on the wall.\n");
    write("The title is \"PLAYER RULES\".\n");
    return 1;
  }
  write("A book hanging from a chain on the wall.\n");
  write("The book has the following sections:\n");
  write("  1.  Player Killing \n"
       +"  2.  Wiz Interfernces \n"
       +"  3.  Multiple Characters \n"
       +"  4.  Passwords         \n"
       +"  5.  Quest Information \n"
       +"  6.  Divorces           \n"
       +"  7.  Reboots/Purge     \n"
       +"  8.  Partying           \n"
       );
  write("You can turn page <num> and then read book.\n");
  write("The book is currently on page " + page_num + ".\n");
  return 1;
}

init() {
  add_action("open", "open");
  add_action("close", "close");
  add_action("read", "read");
  add_action("turn", "turn");
}

open(arg) {
  if(id(arg)) {
    if(!opened) {
      write("You open the book. Look at it for more details.\n");
      say(TP->NAME + " opens the book.\n");
      opened = 1;
      page_num = 1;
      return 1;
    }
    write("The book is already opened to page " + page_num + ".\n");
    return 1;
  }
}

close(arg) {
  if(id(arg)) {
    if(opened) {
      write("You close the book.\n");
      say(TP->NAME + " closes the book.\n");
      opened = 0;
      return 1;
    }
    write("The book is already closed.\n");
    return 1;
  }
}

read(arg) {
  if(id(arg)) {
    if(opened) {
      write("You read page " + page_num + ".\n\n");
      say(TP->NAME + " reads the book.\n");
     if(page_num == 1) {
       command("help playerkilling",TP);
       return 1;
     }
     else if(page_num == 4) {
        TP->more_string(read_file("/doc/rules/password"));
        return 1;
     }
     else {
       TP->more_string(read_file("/players/acdc/office/playerrule" + page_num));
       return 1;
     }
    }
    write("The book is closed.\n");
    return 1;
  }
}

turn(arg) {
  int page;
  if((sscanf(arg, "page %d", page)) || (sscanf(arg,"%d",page))) {
    if(opened) {
      if(page != page_num) {
       if(page <= MAX_PAGE && page > 0) {
     /* Fixed negative page bug       */
    /*  Ac/Dc   09/04/1993            */
	  write("You turn to page " + page + ".\n");
	  page_num = page;
	  return 1;
	}
	write("That page doesn't exist.\n");
	return 1;
      }
      write("The book is already at that page.\n");
      return 1;
    }
    write("The book is closed.\n");
    return 1;
  }
  write("Turn to what page?\n");
  return 1;
}

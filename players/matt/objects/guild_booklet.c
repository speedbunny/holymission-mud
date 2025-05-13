#include "/players/matt/defs.h"

#define PAGES 11

no_clean_up() {
    return 1;
}

id(arg) { return arg == "book" || arg == "booklet"; }
short() { return "Small booklet"; }
long() {
  write("A small booklet with the words \"GUILDS OF HOLY MISSION\" printed\n");
  write("on its cover. There are " + PAGES + " pages in the booklet; " +
	"to read one,\n");
  write("just type \"read page <num>\".\n");
  write("The current guild list is:\n");
  write("  Page 1:  Adventurer\n");
  write("  Page 2:  Thief\n");
  write("  Page 3:  Fighter\n");
  write("  Page 4:  Jedi\n");
  write("  Page 5:  Mage\n");
  write("  Page 6:  Bard\n");
  write("  Page 7:  Monk\n");
  write("  Page 8:  Ninja\n");
  write("  Page 9:  Summoner\n");
  write("  Page 10: Barbarian\n");
  write("  Page 11: Vagabonds\n");
}
get() { return 1; }

init() {
  add_action("read", "read");
}

read(arg) {
  int page;
  if(arg && sscanf(arg, "page %d", page)) {
    if((page > 0) && (page <= PAGES)) {
      write("You read page " + page + ".\n");
      say(TP->SNAME + " reads the brochure.\n");
      TP->more_string(read_file(PATH + "text/guild" + page + ".page"));
      return 1;
    }
    write("Read which page?\n");
    return 1;
  }
}

query_value() { return 10; }

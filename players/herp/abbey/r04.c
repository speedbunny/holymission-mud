#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="Library";
     long_desc=
"You are in the finest library in existence today. There are\n"+
"many books here lying in tumbled heaps.  There are exits to\n"+
"the north, west and south.  To the east you sense you\n"+
"need something to pass....\n";
     dest_dir=({ PATH+"/r01","north",
		 PATH+"/r07","south",
		 PATH+"/r05","west" });
  }
}

init() {
  ::init();
  add_action("east","east");
}

long() { write(long_desc); }

east() {
  if (!(present("relic",this_player()))) {
     write("You may not enter without the relic.\n");
     return 1;
  }
  /* Unsneakable ! */
  this_player()->move_player("east#"+PATH+"/g09");
  return 1;
}

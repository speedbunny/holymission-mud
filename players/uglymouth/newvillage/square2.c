/*
 * Author : Uglymouth
 * Date   : 5-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="The church square";
  long_desc="You stand on the square, before the church. A small well stands in the centre\n"
        + "of the square. East lies the village square and west continues Main Street.\n"
        + "To the south is the entrance to the church.\n";
  dest_dir=({PATH+"square1","east",
        PATH+"church1","south",
	PATH+"street5","west" });
  items=({
        "square","A wide cobblestone square gives even more dignity to the church",
        "church","A small wooden church, but built with much skill",
	"well","A small stone well providing water. A rope hangs down into the depths",
        "rope","A weathered rope tied to a bucket. Pull it to get some water",
	"village square","The cobblestones continue east",
        "cobblestones","Small dark grey stones, smoothed by the years",
        "main street","The main road through the village",
        "entrance","The big oakwooden door stands open for visitors"  });
}

void init() {
  ::init();
  add_action("pull_rope","pull");
}

/* pull up some water from the well. */
pull_rope(string str) {
  if(str!="rope") return 0;
  write("You pull up a bucket full of water and drink some of it.\n"
    + "It is cool and refreshing.\n");
  say(this_player()->query_name() + " drinks some water from the well.\n");
  return 1;
}

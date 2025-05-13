inherit "/room/room";

#include "/room/room_defs.h"
#define RELIGION "Illuvatar"

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="The church square";
  long_desc=
    "You stand on the square, before the church. A small well stands "+
    "in the center of the square. East lies the village square and "+
    "west continues Main Street. To the south is the entrance to the "+
    "church of " + RELIGION + ".  A small, unobtrusive building sits to the "+
    "north.\n";

  dest_dir=({
    HM_VILLAGE + "post", "north",
    HM_VILLAGE + "square1", "east",
    HM_VILLAGE + "street05", "west",
    HM_VILLAGE + "church1", "south",
  });

  items=({
    "square","A wide cobblestone square gives even more dignity to the "+
      "church",
    "church","A small wooden church, but built with much skill",
    "well","A small stone well providing water. A rope hangs down into "+
      "the depths",
    "building","The village post office",
    "rope","A weathered rope tied to a bucket. Pull it to get some water",
    "village square","The cobblestones continue east",
    "cobblestones","Small dark grey stones, smoothed by the years",
    "main street","The main road through the village",
    "entrance","The big oaken door stands open for visitors",
  });

  clone_list=({
    1,1,"danseuse","/players/emerald/misc/danseuse",0,
    1,1,"paperboy","/players/emerald/misc/paperboy",0,
  });

  ::reset(arg);
}

void init() {
  ::init();
  add_action("_pull","pull");
}

/* pull up some water from the well. */
status _pull(string str) {
  if(str != "rope") return 0;
  switch(str) {
    case "rope" :
    case "on rope" :
      writelw("You pull up a bucket full of water and drink some of it. "+
              "It is cool and refreshing.\n");
      say(TP->NAME + " drinks some water from the well.\n");
      return 1;
    default :
      notify_fail("Pull what?\n");
      return 0;
  }
}

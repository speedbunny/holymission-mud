inherit "room/room";

#include "/players/topaz/defs.h"

int _climb(string arg) {
  if(!arg) {
    notify_fail("Climb what?\n");
  }
  if(arg=="tree"||arg=="oak"||arg=="lone tree"||arg=="lone oak tree"||arg=="lone oak"||arg=="oak tree") {
    write("You easily climb the tree.\n");
    say(TP->NAME + " climbs the tree effortlessly.\n");
    MP("up the tree#players/topaz/rooms/attach/tree");
  }
  return 1;
}

reset(arg) {
  if(!arg) {
    short_desc="A meadow";
    long_desc="You are standing in a small meadow.\n" +
              "A slight breeze is blowing and you feel relaxed and\n" +
              "comfortable here.  The tall grass sways slightly in the\n" +
              "breeze.  There is a lone oak tree standing in the middle of\n" +
              "the meadow.\n";

    dest_dir=({ATTACH + "path1","south",
    });
    items=({"meadow","It is very peaceful here",
            "tree","You might be able to climb it",
            "oak","You might be able to climb it",
            "lone tree","You might be able to climb it",
            "oak tree","You might be able to climb it",
            "lone oak tree","You might be able to climb it",
            "lone oak","You might be able to climb it",
            "grass","The grass rustles quietly in the breeze",
            "tall grass","The tall grass rustles quietly in the breeze",
    });
    set_light(1);
return 1;
  }
}

init() {
  ::init();

    add_action("_climb","climb");
    add_action("_shake","shake");
}

_shake(str) {
    if( str=="tree" || str=="oak" || str=="lone tree" || str=="lone oak tree" || str=="lone oak" || str=="oak tree") {
      write("You shake the tree and some leaves fall off.\n" +
            "What kind of unfeeling brute are you?!?\n");
      say(TP->query_name() + " shakes the tree like a barbarian!\n");
      return 1;
    }
    else {
      write("Shake what?\n");
      return 1;
    }
}

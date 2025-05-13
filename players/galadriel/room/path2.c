#include "defs.h"
inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A small path along the river";
  long_desc="You are on a small path along the river. To the east you\n"
        + "see another wooden hut. To the west is the river.\n";
  dest_dir=({PATH+"path1","north",
        PATH+"path3","south"});
  items=({
        "river","The river quietly flows from the north to the south",
        "hut","Its a little hut made of wood, there is no door in this side",
        "path","The path is not wide and you can't see far ahead", });
}

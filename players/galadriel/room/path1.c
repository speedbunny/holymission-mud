#include "defs.h"
inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A small path along the river";
  long_desc="You are on a small path along the river. To the east is a wooden\n"
        + "hut. A few little flowers grow against its wall. To the west flows\n"
        + "the river.\n";
  dest_dir=({"room/hump","northwest",
        PATH+"path2", "south", });
  items=({
        "river","The river quietly flows to the south",
        "flowers","They are small and yellow",
        "hut","Its a little hut made of wood, there is no door in this side",
        "path","The path is not wide and you can't see far ahead", });
}

init() {
  ::init();
  add_action("west","west");
  add_action("pick","pick");
}

west() {
  write("Watch your step! The path is narrow, you could fall in the river!\n");
  return 1;
}

pick(arg) {
  if (arg!="flower" && arg!="flowers") {
    write("Pick what?\n");
    return;
  }
  write("You decide to leave the flowers in peace.\n");
  return 1;
}

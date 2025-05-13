#include "defs.h"
inherit "room/room";

reset(arg) {
  string mill_desc;
  if (arg) return;
  set_light(1);
  short_desc="A small path along the river";
  long_desc="You are on a small path along the river. To the north and\n"
        + "east you see some bushes. To the west is the river.\n";
  dest_dir=({PATH+"path3","northwest",
        PATH+"path5","southeast"});
  mill_desc="A large watermill on the other bank of the river";
  items=({
        "river","The river quietly flows from the northwest to the southeast.\n"+
        "On the opposite bank, somewhat to the south, you can see a mill",
        "mill",mill_desc,
        "watermill",mill_desc,
        "water mill",mill_desc,
        "bushes","The bushes are very thick",
        "path","The path is not wide and you can't see far ahead", });
}

init () {
  ::init();
  add_action("pass","pass");
  add_action("pass","enter");
  add_action("east","east");
}

pass(arg) {
  if (arg!="bushes" && arg!="bush") {
    return;
  }
  write("You can't pass the bushes here, they are too thick!\n");
  return 1;
}
east() {
  write("The bushes are too thick!\n");
  return 1;
}

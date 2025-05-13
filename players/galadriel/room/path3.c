#include "defs.h"
inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A small path along the river";
  long_desc="You are on a small path along the river. To the east you\n"
        + "see some bushes. To the west is the river.\n";
  dest_dir=({PATH+"path2","north",
        PATH+"path4","southeast"});
  items=({
        "river","The river quietly flows from the north to the southeast",
        "bushes","The bushes are not very thick",
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
  TP->move_player("in the bushes#"+PATH+"bushes1");
  return 1;
}
east() {
  write("There are bushes! But maybe you can enter them...\n");
  return 1;
}

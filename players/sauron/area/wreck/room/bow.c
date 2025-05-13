inherit "/players/sauron/wreck/rooms/inside_water_room";

#include "/players/sauron/std_defs.h"
#include "/players/sauron/wreck/path_defs.h"

void leave() {
  WRITE("You enter the hole in the side of the bow and leave the wreck.\n");
  MP(TP,"out through the hole in the side of the bow of the wreck#"
    +WKRMS+"ishikawa_sea4_2");
}

int leave_wreck(string str) {
  if(!str || str!="wreck") {
    NF("Leave what?\n");
    return 0;
  }
  leave();
  return 1;
}

int enter_hole(string str) {
  if(!str || str!="hole") {
    NF("Enter what?\n");
    return 0;
  }
  leave();
  return 1;
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc=("The bow of a sunken wreck.");
    long_desc=("You are standing in the bow of the sunken wreck.\n");
    dest_dir=({
    });
    items=({
    });
  }
}

void init() {
  ::init();
  add_action("leave_wreck","leave");
  add_action("enter_hole","enter");
}

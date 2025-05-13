#include "../seaworld.no_water.h"
inherit "room/room";

reset(arg) {
set_light(1);
short_desc = "On a stony path";
long_desc =
    "You have now reached the northern end of the stony path\n"+
    "You are now standing in front of a little hut.\n"+
    "It looks very inviting, maybe you should try to enter it.\n";
dest_dir = ({
    PATH+"path_end","south",
      });
items = ({ "bottom","A stony bottom",
            "hut","A little wooden hut" });
}

init() {
  ::init();
  add_action("enter","enter");
  }
 enter(str) {
 if(str!="hut"){
notify_fail("Enter what ?\n");
 return 0;
}
   this_player()->move_player("into the hut#players/whisky/seaworld/room/sw_shop");

  return 1; }


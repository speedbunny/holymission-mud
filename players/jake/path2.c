inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
  set_light(1);
  short_desc = "path2";
  long_desc = 
        "The path splits here.\n"
        "To the east is the trail to Jake's newbie area.\n";
 dest_dir = ({
  NEW + "new1","east",
 "/players/jake/path1","south",
  "/players/emerald/country/entry", "west",
});
  clone_list = ({ 1, 1, "goober", "players/jake/Old_area/monster/goober", 0 });

::reset();
replace_program("room/room");
}


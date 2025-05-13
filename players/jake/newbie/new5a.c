inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
  set_light(1);
  short_desc = "new5a";
  long_desc = 
        "Brrr.....\n"
        "You have wandered into a snow storm.\n"
        "It is snowing very heavily here.  There are piles of snow everywhere.\n";
  items = ({ "pile", "Huge piles of snow...Everywhere!" });
  DD = ({
  NEW + "new5","west" });
clone_list = ({ 1, 1, "snowdrift", "/players/jake/Old_area/monster/snowdrift", 0});

::reset();
replace_program("room/room");
}


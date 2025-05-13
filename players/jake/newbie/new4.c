inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
  set_light(1);
  short_desc = "new4";
  long_desc = 
        "It seems that you have wandered into a desert.\n"
        "You see a cactus north of you.\n"
        "It is very hot here.\n";
  items = ({ "cactus", "A large cactus with pointy needles" });
 DD = ({
  NEW + "new3","west",
  NEW + "new5","east",
 });
 clone_list = ({ 1, 1, "snake", "players/jake/Old_area/monster/snake", 0});

::reset();
replace_program("room/room");
}


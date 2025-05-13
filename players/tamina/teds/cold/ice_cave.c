inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Frozen Foothills";
    long_desc =
"You are at the base of a huge mountain of ice.\n"+
"A path winds precariously up the side of the mountain.\n"+
"While a dark cave opening can be seen to the west.\n";

    dest_dir = ({
  TCOLD + "cold_top", "up",
  TCOLD + "ice_drag", "west",
  TCOLD + "ice_path2", "east"
    });

    items = ({
  "opening",
"It is very dark, but large enough for you to enter..",
  "path",
"It is long, windy, and steep",
  "cave",
"It is very dark, but large enough for you to enter..",
    });

    ::reset(arg);
    replace_program("room/room");

}

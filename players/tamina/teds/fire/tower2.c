inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Tower Hall";
    long_desc =
"This is a small north-south hall. A large window opens on the\n"+
"west wall. A door leads east and the hall continues south.\n";

    dest_dir = ({
      TFIRE + "tower1", "north",
      TFIRE + "tower3", "south",
      TFIRE + "tower_room", "east"
    });

    items = ({
"windows","Out the window you can see a large forest of petrified trees",
"window","Out the window you can see a large forest of petrified trees",
"door","This is a small wooden door. It is slightly ajar"
    });

  ::reset(arg);
  RPR("room/room");
}

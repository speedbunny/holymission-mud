inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Volcano Bottom";
    long_desc =
    "You are at the base of a huge smoldering volcano.\n"+
    "A gaping fissure leads east into the bowls of the\n"+
    "volcano, while a ridge of cooled lava forms a natural\n"+
    "stairway up to the rim.\n";

    dest_dir = ({
      THOT + "rim","up",
      THOT + "fire_path2","west",
      THOT + "red_drag","east"
    });

    ::reset(arg);
    replace_program("room/room");
}

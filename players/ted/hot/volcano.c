#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Volcano Bottom";
    long_desc =
    "You are at the base of a huge smoldering volcano.\n"+
    "A gaping fissure leads east into the bowls of the\n"+
    "volcano, while a ridge of cooled lava forms a natural\n"+
    "stairway up to the rim.\n";
    dest_dir = ({
      HOT + "rim","up",
      HOT + "fire_path2","west",
      HOT + "red_drag","east"
    });
    replace_program("room/room");
}

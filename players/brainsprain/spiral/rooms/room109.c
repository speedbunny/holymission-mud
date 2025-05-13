
inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
reset(arg) {

  short_desc = "A barren room";
  long_desc =
    "It appears as if this room as been cleaned from top to bottom.  "+
    "The walls, floor, and ceiling show no signs of dust.  Four flags: "+
    "red, green, yellow, and black hang from brass poles along the "+
    "southern wall.\n"+
"\n";
    set_light(1);
    dest_dir = ({
    sr+ "/room107","northwest",
    sr+"/room110","east",
  });
  items = ({
    "flags",
    "You should look at each individually",
    "floor",
    "The floor of this room",
    "ceiling",
    "The ceiling of this room",
    "room",
    "An underground cavern",
    "walls",
    "The walls of an underground cavern",
    "red flag",
    "A red flag with an orc and the word Ormag on it",
    "green flag",
    "A green flag with a troll and the word Trakag on it",
    "yellow flag",
    "A yellow flag with a goblin and the word Galgug on it",
    "black flag",
    "A black flag with an ogre and the word Ogram on it",
    "fungus",
    "A green fungus that covers most of the walls",
    "poles",
    "Huge brass poles from which multi-colored banners hang",
  });
    clone_list = ({ 1, 2, "rat", sm+"/rat.c", 0 });
    ::reset(arg);
    replace_program("room/room");
}

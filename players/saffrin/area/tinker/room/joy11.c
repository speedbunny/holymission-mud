inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
    set_light(2);
    short_desc="Joy's Park";
    long_desc=
         "You are standing in the middle of Joy's Park.  There is a large marble "+
         "statue of the Mage Joyful resting here.  Around the base of the statue "+
         "is a plaque with something written on it.  There are flowers all about the "+
         "ground.  There is the sound of trickling water coming from the east.\n";
    dest_dir = ({
      TINK+"room/joy10", "north",
      TINK+"room/joy6", "south",
      TINK+"room/joy12", "east",
      TINK+"room/joy8", "west",
    });
    items =({
      "statue", "A statue of the Mage Joyful",
      "plaque", "It reads: A park dedicated to the Mage Joyful by Saffrin",
      "flowers", "Sweet smelling flowers",
    });
    ::reset();
    replace_program("room/room");
}

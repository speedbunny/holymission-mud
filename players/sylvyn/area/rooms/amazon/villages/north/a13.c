inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc="A village path.";
    long_desc=
    "You have entered the ante-chamber of the Tribal Chief. There are\n" +
    "two very large guards standing on either side of a door way. You\n" +
    "can't see into the room due to a lepoard skin blocking the view.\n" +
    "\n";

     dest_dir=({
         PATH+TRIBE+"a14.c", "east",
         PATH+TRIBE+"a05.c", "south",
         PATH+TRIBE+"a04.c", "southwest",
         PATH+TRIBE+"a11.c", "west",

     });

     property = ({
       "no_teleport", "no_sneak", "no_steal",

     });

     items = ({
       "guard", "A huge guard with a very large spear in his hands",

     });

    smell = "A light sent of fragrence fills the air.";

replace_program ("room/room");
}

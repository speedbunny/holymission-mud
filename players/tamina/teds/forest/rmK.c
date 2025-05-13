inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    if (arg) return 0;
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"The trees thin out here at the top of a small hill.\n"+
"A bubbling brook runs in front of the entrance to a\n"+
"small cave to the east.\n";

   dest_dir = ({
   TFOREST + "rmQ", "north",
   TFOREST + "rmF", "south",
   TFOREST + "rmL", "east",
   TFOREST + "rmJ", "west",
    });

    items = ({
"brook", "A small stream filled with clear, cold water",
"cave",  "A dark cave entrance. You can here strange noises within"
    });

    ::reset(arg);
    replace_program("room/room");
}

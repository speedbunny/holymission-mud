inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Snowy Clearing";
    long_desc =
"The forest ends here and the ice tundra starts. As far\n"+
"as the eye can see is white frozen ice and snow.\n";

    dest_dir = ({
   TCOLD + "ice_troll", "north",
   TCOLD + "quaggoth", "west",
   TCOLD + "ice_elem", "east",
   TCOLD + "mammoth", "south"
    });

    ::reset(arg);

    replace_program("room/room");
}

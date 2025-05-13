inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Frozen Mountain Top";
    long_desc =
"This ice covered mountain top provides a spectacular\n"+
"view of the surrounding land. Far to the north can be\n"+
"seen a shining castle. While off to the east\n"+
"lies a smoking volcano.\n";

    dest_dir = ({
    TCOLD + "ice_cave", "down",
    TCOLD + "yeti", "west"
    });

    ::reset(arg);
    replace_program("room/room");
}

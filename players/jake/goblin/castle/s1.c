inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
if (arg) return;
set_light(1);
short_desc = "Hallway to the stables";
long_desc = "You are standing in a small hallway that leads to the castle stables.\n" +
            "Small slits for windows are in the east and west walls.  The sounds\n" +
            "of horses come from the north.\n";
items = ({
 "slits","Narrow slits in the walls that serve as windows"
});
dest_dir = ({
CAS + "s2","north",
CAS + "c14","south",
});
}

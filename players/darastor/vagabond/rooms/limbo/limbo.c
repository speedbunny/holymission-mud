inherit "room/room";
#include "/players/nylakoorub/guild/defines.h"


void reset(int arg) {
    ::reset(arg);
    set_light(1);
    short_desc = "Limbo";
    long_desc =
    "There is not much to describe of this space, it is like\n"+
    "this place is no where.\n"+
    "\n";


    dest_dir = ({
      "", "nowhere",
    });

    hidden_dir = ({
      "room/church",
      "church",
    });




    property = ({
      "no_clean_up",
      "no_teleport",
    });

    replace_program("room/room");

}






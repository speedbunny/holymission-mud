inherit "room/room";
#include "/players/nylakoorub/clearing/defines.h"

void reset(int arg) {
    ::reset(arg);
    set_light(1);
    short_desc = PATH_SHORT_DESC;
    long_desc =
    "You are standing on a path in a very large clearing.\n"+
    "As you glance up, you can see the open blue skies, filled with soft \n"+
    "white clouds.  The cool crisp air blows by your face and ruffles \n"+
    "through your hair.\n"+
    "\n";




    dest_dir = ({
      CLEARING+PATH+"rooms/c092.c",
      "west",
      CLEARING+PATH+"rooms/c083.c",
      "southeast",


    });


    items = ({
      "path","Its a dirt path."


    });


    replace_program("room/room");

}

inherit "room/room";
#include "/players/nylakoorub/clearing/defines.h"

void reset(int arg) {
    ::reset(arg);

/*
    (CLONER)->random_cloner(PATHROOMS,
      PATHMONS,
      12);
*/

    set_light(1);
    short_desc = PATH_SHORT_DESC;
    long_desc =
    "You are standing on a dirt path in a very large clearing.\n"+
    "As you look up, you can see the open blue skies, filled with soft\n"+
    "white clouds.  The cool crisp air blows by your face and ruffles \n"+
    "through your hair.\n"+
    "To the north you can see the entrance to the vast Koorubian \n"+
    "Rainforest.  The dirt path runs in many directions.\n"+
    "\n";

    dest_dir = ({
      CLEARING+PATH+"rooms/c072.c",
      "south",
      CLEARING+PATH+"rooms/c084.c",
      "east",
      CLEARING+PATH+"rooms/c093.c",
      "northwest",


    });


    items = ({
      "path", "Its a dirt path",
      "forest", "You look at the splendor of the vast Koorubian Rainforest",
      "rainforest", "You look at the splendor of the vast Koorubian Rainforest",


    });


    replace_program("room/room");

}

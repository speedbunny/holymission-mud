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
    "As you glance up, you can see the open blue skies, filled with soft \n"+
    "white clouds.  The cool crisp air blows pass your face and ruffles \n"+
    "through your hair.\n"+
    "To the distant north you see the entrance to the vast Koorubian\n"+
    "Rainforest.  The dirt path runs north and south.\n"+
    "\n";

    dest_dir = ({
      CLEARING+PATH+
      "rooms/c039.c",
      "north",
      CLEARING+PATH+
      "rooms/c017.c",
      "south",


    });


    items = ({
      "path", "Its a dirt path",
      "forest", "You look at the splendor of the vast Koorubian Rainforest",
      "rainforest", "You look at the splendor of the vast Koorubian Rainforest",


    });



}






inherit "room/room";
#include "/players/nylakoorub/clearing/defines.h"

void reset(int arg) {
    ::reset(arg);
    set_light(1);
    short_desc = PATH_SHORT_DESC;
    long_desc =
    "You are standing on a dirt path in a very large clearing.  "+
    "As you glance up, you can see the open blue skies, filled with soft "+
    "white clouds.  The cool crisp air blows by your face and ruffles "+
     "through your hair.  "+
   "To the distant north, you see the entrance to the vast Koorubian "+
    "Rainforest.  The dirt path runs north and south.  "+
    "To the south, you can see the path leading into a valley "+
    "and you can smell a vile odor, which you believe to be that of "+
    "an orc.\n";


    dest_dir = ({
      CLEARING+PATH+"rooms/c017.c",
      "north",
      "/room/orc_valley/valley11", "south",


    });


    items = ({
      "path", "Its a dirt path",
      "forest", "You look at the splendor of the vast Koorubian Rainforest",
      "rainforest", "You look at the splendor of the vast Koorubian Rainforest",


    });

}

init() {

    ::init();
/*
  write("THIS AREA CLOSED\n");
write("Perhaps Permanantly.\n");
  this_player()->move_player("south#room/orc_valley/valley11");
*/
    if(this_player()->query_race() == "orc" || "ogre"
      &&  this_player()->query_npc()) {
	this_player()->move_player("south#players/herp/orc/v11");
    }
}

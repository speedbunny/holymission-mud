inherit "room/room";
#include "/players/nylakoorub/clearing/defines.h"
object board;
string extra;
int i;

void reset(int arg) {
    ::reset(arg);

    if(!board)
    {
	board = clone_object("/obj/board");
	board->set_name("Clearing of "+AREANAME+" Main");
	board->set_file("/players/nylakoorub/clearing/boards/clearing");
	board->set_short("Clearing of "+AREANAME+" Main");
	transfer(board,this_object());
    }


    set_light(1);
    short_desc = PATH_SHORT_DESC;
    long_desc =
    "You are standing on a dirt path in a very large clearing.\n"+
    "As you glance up, you can see the open blue skies, filled with soft \n"+
    "white clouds.  The cool crisp air blows by your face and ruffles \n"+
    "through your hair.\n"+
    "To the distant north you see the entrance to the vast Koorubian\n"+
    "Rainforest.  The dirt path runs north and south.\n"+
    "\n"+
    "Here, you see the Main Board of Nylakoorub's Area, on this board \n"+
    "you will find updates, reports of bugs, and suggestion for this area\n"+
    "\n";           

    dest_dir = ({
      CLEARING+PATH+"rooms/c028.c",
      "north",
      CLEARING+PATH+"rooms/c006.c",
      "south",


    });


    items = ({
      "path", "Its a dirt path",
      "forest", "You look at the splendor of the vast Koorubian Rainforest",
      "rainforest", "You look at the splendor of the vast Koorubian Rainforest",


    });



    replace_program("room/room");
}

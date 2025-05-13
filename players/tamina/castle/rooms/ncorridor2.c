/*  This is the North Corridor  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(-1);
	short_desc = "North Corridor ";
	long_desc = 
"You go east along the darkened corridor.  Small piles of dust erupt \n"+
"around your feet as you walk along the stone floor.  Here, the passage\n"+
"forks in two directions.  Soft light can be seen from straight ahead to\n"+ 
"the east.  Only deeper darkness can be seen to the north-east, but a \n"+
"strange odour can be smelled from that room.\n";

	dest_dir = ({
          CROOMS + "chapel","east",
          CROOMS + "infirm","northeast",
	  CROOMS + "n_junction","west",
        });

    ::reset (arg);

    RPR("room/room");
}


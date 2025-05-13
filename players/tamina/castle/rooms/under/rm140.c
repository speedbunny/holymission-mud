/*  This is an Underground Maze  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
   if (arg) return ;

      	set_light(0);
	short_desc = "Underground Passage (s,e)";
	long_desc = 
"This part of the passage seems to have gotten lighter than the rest.\n"+
"The walls don't seem any different than the ones before, though.\n"+
"There is a distinctive glow coming from the east.\n";

	dest_dir = ({
          UND + "rm141","south",
          UND + "m_room","east",
     });

	items = ({
  "walls","Made of earth, and all very similar to each other..",
    });

}

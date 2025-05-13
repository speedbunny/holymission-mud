/*  This is an Underground Maze  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
   if (arg) return ;

      	set_light(-1);
	short_desc = "Underground Passage (n,s,e,w)";
	long_desc = 
"This looks like the beginnings of a maze...\n"+
"The walls all look similar, and you really don't know\n"+
"where you are going.\n";

	dest_dir = ({
          UND + "rm24","north",
          UND + "rm25","south",
          UND + "rm3","east",
          UND + "rm1","west",
     });

	items = ({
  "walls","Made of earth, and all very similar to each other..",
    });

}

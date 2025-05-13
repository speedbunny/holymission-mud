/*  This is an Underground Maze  */

#include "/players/tamina/defs.h"

inherit "room/room";
object stalker;

void reset(int arg) {

   if(!stalker) {
   stalker=CLO(UND + "stalker");
   transfer(stalker,TO);
   }
   if (arg) return ;

      	set_light(-1);
	short_desc = "Underground Passage (e,w)";
	long_desc = 
"This looks like the beginnings of a maze...\n"+
"The walls all look similar, and you really don't know\n"+
"where you are going.\n";

	dest_dir = ({
          UND + "rm110","east",
          UND + "rm9","west",
     });

	items = ({
  "walls","Made of earth, and all very similar to each other..",
    });

}

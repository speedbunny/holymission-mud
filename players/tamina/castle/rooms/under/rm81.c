/*  This is an Underground Maze  */

#include "/players/tamina/defs.h"

inherit "room/room";
object ob;

void reset(int arg) {
   if(!ob=present("hound"))
      MO(CLO(UND + "hound"),TO);

   if (arg) return ;

      	set_light(-1);
	short_desc = "Underground Passage (n,s,e,w)";
	long_desc = 
"This looks like the beginnings of a maze...\n"+
"The walls all look similar, and you really don't know\n"+
"where you are going.\n";

	dest_dir = ({
          UND + "rm80","north",
          UND + "rm82","south",
          UND + "rm90","east",
          UND + "rm71","west",
     });

	items = ({
  "walls","Made of earth, and all very similar to each other..",
    });

}

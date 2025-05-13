inherit "room/room";
#include "/players/gambit/defs2.h"
reset(arg) {
    if (!arg) {
	short_desc = "Room Entrance";
	long_desc = 
          "The cave leads into a dark room. A huge hole is in the "+
          "northern wall. It looks as if this hole was created "+
           "by a great force. The rest of the room looks like the cave, "+
           "all scratched up and covered with dried blood. Skeleton "+
           "bones lay about, and a low growl can be heard from the next room.\n";
	dest_dir = ({
	  "/players/whisky/hole/room/cave2","north",
	  "/players/whisky/hole/room/cave","east",
	});
	smell = "The room smells like dried blood";
	items = ({
	  "wall","Huge scratches are dug into the wall",
	  "walls","Dried blood and scratches are dug into the wall",
	  "floor",
	  "Dried blood covers the floor",
	  "bones","Bones are scattered all about the cave",
	  "ceiling","The ceiling has jagged rocks hanging from it",
	  "scratches","Huge scratches from something are dug into the walls",
	});
    }
}

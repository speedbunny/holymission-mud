inherit "room/room";

#include "/players/nunu/path.h"

reset(arg) {

	short_desc="A Closet";

	long_desc="You in a little box.  It feels like your in a coffin.  "+
		  "There isn't much room to move around and you seem to "+
		  "keep hitting the shelf above you.  There is a little "+
                  "hole in the door about half way up.\n";

	set_light(0);

items=({"shelf","The bottom side looks nice, mabye you can search the "+
    		"shelf.",
   	"hole","It looks like a little hole.  There is a speck of light "+
 	        "shining in from the outside.",
        "door","From the judge of the hinges it looks like your on the "+
	       "inside of this door.",
	"hinge","There are two of them, both look to make the door swing "+
 		"outward.",
	"hinges","They look to make the door swing outward.",
      });
	
	property=({"no_teleport","no_fight","no_steal"});

	smell="Is smells like a closet in here.\n";







	::reset(arg);
	replace_program("room/room");
}

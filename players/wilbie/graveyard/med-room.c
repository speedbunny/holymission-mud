inherit"/room/room";
#include "/players/wilbie/def.h"
#define PATH "/players/wilbie/graveyard/"

void reset(int arg){
    set_light(1);
    short_desc=
	"Meditation Room";
    long_desc=
   	"You are in a dimly lit room, empty except for a small black rug "+
	"in the center.  The Matriarch of the Dark Order uses this room to "+
	"draw upon the power of her dark goddess.  A sense of evil fills "+
	"this room!\n";
    items=({
  	"room",
	    "It is a room designed for meditation",
	"rug",
	    "A small black rug the Matriarch can kneel upon",
	"center",
	    "There is a rug in the center of the room",
    });
    dest_dir=({
	GPATH+"longhall9","east",
    });
    clone_list=({
	 1,1,"matriarch",PATH+"monsters/high_priestess",0,
 	-1,1,"shield",PATH+"armor/shield1",0,
        -1,1,"cloak","/players/wilbie/graveyard/armor/cloak",0,
 	-1,1,"plate",PATH+"armor/armor3",0,
 	-1,1,"hammer",PATH+"weapons/bhammer",0,
    });

    ::reset(); 
    replace_program("/room/room");
}

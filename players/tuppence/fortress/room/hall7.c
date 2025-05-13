inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Lighted up hallway";
	long_desc= "The hallway is lit up by a small barred window on the north\n"+
	"wall. Swords and different types of shields are lined up on the wall\n"+
	"from great warriors long forgotten. A large spiral stone stairway\n"+
	"leads up to the next floor.\n";
	items=
	({
	  "window","As you look out you can see guards wandering around",
	  "swords","All diffrent types of swords ftom claymore ro short swords",
	  "shield","Large and small shields are lined up on the walls",
	  "stairway","Large stairway with magic runes carved into it",
	});
	dest_dir=
	({
	  FROOM+"top1","up",
	  FROOM+"hall6","south",
	});
    }
::reset(arg);
replace_program("/room/room");
}

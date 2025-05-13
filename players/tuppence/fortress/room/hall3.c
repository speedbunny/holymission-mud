inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc = "Bloody hall";
	long_desc= "More heads are hanging on the walls, but these seem recent,\n"+
	"blood is still dripping off them. As you walk down the hall you\n"+
	"step in a puddle of blood...EWW! Strange sounds are coming from\n"+
	"the east and west rooms.\n";
	items =
	({
	  "heads","Recently hung heads with blood dripping off them",
	});
	dest_dir =
	({
	  FROOM+"slroom1","west",
	  FROOM+"hall4","north",
	  FROOM+"slroom2","east",
	  FROOM+"hall2","south",
	});
    }
::reset(arg);
replace_program("/room/room");
}

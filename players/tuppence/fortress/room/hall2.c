inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Evil hallway";
	long_desc= "As you walk down the hallway you sense the presence of evil\n"+
	"magic. The hallway continues to the north.\n";
	dest_dir =
	({
	  FROOM+"hall3","north",
	  FROOM+"hall1","south",
	});
    }
::reset(arg);
replace_program("/room/room");
}

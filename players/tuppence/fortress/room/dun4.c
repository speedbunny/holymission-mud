inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Dungeon hallway";
	long_desc= "This is the dungeon hallway leading to all the cells. You can\n"+
	"hear the prisoners screaming from being tortured. Rats run up\n"+
	"and down the hallways. Standing next to the walls are stands of\n"+
	"oils on fire to light up the hallway. You feel as if you'd better\n"+
	"go before you become one of the prisoners too.\n";
	items =
	({
	  "stands","Different oils are put in here to be lit",
	});
	dest_dir =
	({
	FROOM+"dun5","north",
	  FROOM+ "dun3","south",
	  FROOM+ "cell1","east",
	  FROOM+ "cell2","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
